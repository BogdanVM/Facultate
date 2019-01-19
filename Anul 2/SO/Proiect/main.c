#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[1;31m"
#define KGRN  "\x1B[1;32m"
#define KYEL  "\x1B[1;33m"
#define KBLU  "\x1B[1;34m"
#define KMAG  "\x1B[1;35m"
#define KCYN  "\x1B[1;36m"
#define KWHT  "\x1B[1;37m"

int redirectIn(char* fileName)
{
	int in = open(fileName, O_RDONLY);
	if (in == -1) {
		printf("%sError with opening the file\n", KRED);
		return errno;
	}

	if (dup2(in, 0) == -1) {
		printf("%sError with reading from the file\n", KRED);
		return errno;
	}

	if (close(in) == -1) {
		printf("%sError while closing the file\n", KRED);
		return errno;
	}

	return 0;
}

int redirectOut(char* fileName)
{
	int out = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (out == -1) {
		printf("%sError with opening the file\n", KRED);
		return errno;
	}

	if (dup2(out, 1) == -1) {
		printf("%sError with writing in the file\n", KRED);
		return errno;
	}

	if (close(out) == -1) {
		printf("%sError while closing the file\n", KRED);
		return errno;
	}

	return 0;
}

int execute (char** command) {

	pid_t pid = fork();
	if (pid < 0) {
		perror(NULL);
		return errno;
	}

	else if (pid == 0) {
		if (execvp(command[0], command) == -1) {
			printf("%sUndefined Command\n", KRED);
			exit(0);
		}
	}

	else {
		wait(NULL);
	}

	int in = redirectIn("/dev/tty");
	if (in != 0) {
		return in;
	}

	int out = redirectOut("/dev/tty");
	if (out != 0) {
		return out;
	}

	return 0;
}

int runPipe(char** command) {

	int fd[2];
	if (pipe(fd) == -1) {
		printf("%sError with creating the pipe\n", KRED);
		return errno;
	}

	if (dup2(fd[1], 1) == -1) {
		printf("%sAn unexpected error has occurred\n", KRED);
		return errno;
	}

	if (close(fd[1]) == -1) {
		printf("%sAn unexpected error has occurred\n", KRED);
		return errno;
	}

	int ex = execute(command);
	if (ex != 0) {
		return ex;
	}

	if (dup2(fd[0], 0) == -1) {
		printf("%sAn unexpected error has occurred\n", KRED);
		return errno;
	}

	if (close(fd[0]) == -1) {
		printf("%sAn unexpected error has occurred\n", KRED);
		return errno;
	}

	return 0;
}

char* addSpaces(char* instr) {
	char specialChars[] = "<>|";
	int i, apps = 0;
	for (i = 0; i < strlen(instr); ++i) {
		if (strchr(specialChars, instr[i]) != NULL) {
			apps++;
		}
	}

	char* spaced = (char*) malloc(strlen(instr) + apps * 2);
	int currentChar = 0;
	for (i = 0; i < strlen(instr); ++i) {
		if (instr[i] != '<' && instr[i] != '>' && instr[i] != '|') {
			spaced[currentChar] = instr[i];
			currentChar++;
		} else {
			spaced[currentChar] = ' ';
			spaced[currentChar + 1] = instr[i];
			spaced[currentChar + 2] = ' ';

			currentChar += 3;
		}
	}

	spaced[currentChar++] = '\0';

	return spaced;
}

char** parseInstr(char* spaced) {
	char* temp = strtok(spaced, " ");
	char** arguments = (char**) malloc(sizeof(char*) * 32);

	int currentArgument = 0;
	while(temp) {
		switch(*temp) {
			case '<': {
				char* fileName = strtok(NULL, " ");
				if (redirectIn(fileName) != 0) {
					return NULL;
				}

				break;
			}

			case '>': {
				char* fileName = strtok(NULL, " ");
				if (redirectOut(fileName) != 0) {
					return NULL;
				}

				break;
			}

			case '|': {
				arguments[currentArgument] = NULL;
				if (runPipe(arguments) != 0) {
					return NULL;
				}
				currentArgument = 0;
				break;
			}

			default: {
				arguments[currentArgument] = temp;
				currentArgument++;
				break;
			}
		}

		temp = strtok(NULL, " ");
	}

	arguments[currentArgument] = NULL;
	return arguments;
}

int main()
{
	int i = 0;
	char** commandsHistory = (char**) malloc (0);
	int commandsNumber = 0;

	// Sterge consola (clear)
	printf("\033[H\033[J");

	while (1) {
		/* Obtine directorul curent */
		char currentDirectory[1024];
		if (getcwd(currentDirectory, sizeof(currentDirectory)) != NULL)
			printf("  %s%s%s$ ", KGRN, currentDirectory, KNRM);
		else {
			printf("\n%sError with the current directory\n", KRED);
			continue;
		}

		char* instr = (char*) malloc(32);
		size_t bufSize = 32;

		getline(&instr, &bufSize, stdin);
		instr[strlen(instr) - 1] = '\0';

		if (strcmp(instr, "exit") == 0)
			return 0;


		commandsNumber++;
		char** temp = (char**) realloc(commandsHistory, commandsNumber * sizeof(char*));
		if(temp) {
			commandsHistory = temp;
			commandsHistory[commandsNumber - 1] = (char*) malloc(strlen(instr));
			memcpy(commandsHistory[commandsNumber - 1], instr, strlen(instr));
		}
		else {
			printf("%sTrouble with memory\n", KRED);
			commandsNumber--;
			continue;
		}


		if (strcmp(instr, "history") == 0) {

			printf("\n");
			for (i = 0; i < commandsNumber; ++i) {
				printf("%d. %s\n", i + 1, commandsHistory[i]);
			}

			printf("\n");
			continue;
		}



		char* spaced = addSpaces(instr);
		char** arguments = parseInstr(spaced);

		if (arguments == NULL) {
			continue;
		}

		if (strcmp(arguments[0], "cd") == 0) {
			if (chdir(arguments[1]) == -1) {
				printf("%sInvalid directory\n", KRED);
				continue;
			}

			continue;
		}

		if (strcmp(arguments[0], "history") == 0) {
			int poz = atoi(arguments[1]) - 1;
			char** historyArgs = parseInstr(addSpaces(commandsHistory[poz]));

			if (strcmp(historyArgs[0], "cd") == 0) {
				if (chdir(historyArgs[1]) == -1) {
					printf("%sInvalid directory\n", KRED);
					continue;
				}

				continue;
			}

			if (strcmp(commandsHistory[poz], "history") == 0) {
				printf("\n");
				for (i = 0; i < commandsNumber; ++i) {
					printf("%s\n", commandsHistory[i]);
				}

				printf("\n");
				continue;
			}

			if (execute(historyArgs) != 0) {
				continue;
			}

			continue;
		}
		if (execute(arguments) != 0) {
			continue;
		}


	}
	return 0;
}
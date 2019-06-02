package com.fmi.project.services;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class WriteService {
    private static WriteService instance = null;
    private String path;

    private WriteService() { }

    public static WriteService getInstance(String path) {
        if (instance == null) {
            instance = new WriteService();
        }

        instance.setPath(path);
        return instance;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    /**
     * <p>Method that writes to the file a list of lists of strings (storing the lines of a file). </p>
     * <p> It iterates through all the lines and, for each line, through all the words,
     * writing each one of them to the file.</p>
     *
     * @param lines a list of lists of strings, meaning the lines of a file. Each sublist is a single row
     * @throws IOException in case of a problem with writing in the file
     */
    private void writeLines(List<List<String>> lines) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path));
        for (List<String> row : lines) {
            for (String word : row) {
                bufferedWriter.write(word + ",");
            }

            bufferedWriter.write("\n");
        }

        bufferedWriter.flush();
        bufferedWriter.close();
    }

    /**
     *
     * <p>Method that deletes a line, given by its index, from the .csv file.</p>
     * <p>It iterates through every line, saving each row in a list (except for the one "deleted").</p>
     * <p>Then, using a BufferedWriter, the file is updated with only the remaining lines.</p>
     *
     * @param i index of the line to be deleted
     * @throws IOException thrown in the case of a problem with the file while reading and writing to it
     */
    void deleteLine(int i) throws IOException {
        ReadService readService = ReadService.getInstance(path);
        int currRow = 0;

        List<String> line;
        List<List<String>> lines = new ArrayList<>();
        while ((line = readService.readLine()) != null) {
            if (currRow++ == i) {
                continue;
            }

            lines.add(line);
        }

        writeLines(lines);
    }

    /**
     * Method that updates a line in a file, specified at "lineIndex",
     * by replacing the word at "wordIndex" with "updatedWord".
     *
     * @param lineIndex index of the line to be updated in the file (starting from 0);
     * @param wordIndex index of the word to be updated from the line specified (starting from 0);
     * @param updatedWord word to be added to the specified location the file.
     * @throws IOException in case of a problem with reading or writing to the file.
     */
    void updateLine(int lineIndex, int wordIndex, String updatedWord) throws IOException {
        ReadService readService = ReadService.getInstance(path);
        int currRow = 0;

        List<String> line;
        List<List<String>> lines = new ArrayList<>();
        while ((line = readService.readLine()) != null) {
            if (currRow++ == lineIndex) {
                line.set(wordIndex, " " + updatedWord); // update the word at the specified index
            }

            lines.add(line);
        }

        writeLines(lines);
    }
}

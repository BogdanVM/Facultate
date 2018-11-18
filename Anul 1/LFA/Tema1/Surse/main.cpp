#include <bits/stdc++.h>
#include "DFA.h"
using namespace std;
int main() {

    ifstream fileIn("dfa.in");

    bool stringLetters = false;

    int number;
    fileIn >> number; // Citesc numarul de stari

    DFA dfa(number);

    fileIn >> number; // Citesc numarul de litere din alfabet
    for(int i = 0; i < number; i++){
        string letter;
        fileIn >> letter;
        dfa.insertInAlphabet(letter);

        if (letter.size() >= 2)
            stringLetters = true;
    }
    fileIn >> number; // Citesc starea initiala
    dfa.setInitialState(number);

    fileIn >> number; // Citesc numarul de stari finale
    for (int i = 0; i < number; i++){
        int finalState;
        fileIn >> finalState;
        dfa.setFinalState(finalState);
    }

    int firstState, secondState;
    string letter;
    while (fileIn >> firstState >> letter >> secondState){
        if (!dfa.isLetterInAlphabet(letter)){
            cout << endl << "O tranzitie contine o litera care nu apartine alfabetului " << endl;
            return 0;
        }
        dfa.markTransition(firstState, letter, secondState);
    }
    string word;

    if (!stringLetters){
        cout << endl << "Introduceti cuvantul( ';' pentru a iesi, '$' pentru sirul vid ): ";
        cin >> word;
        cout << endl;

        while (word != ";")
        {
            if (dfa.isWordAccepted(word))
                if (word == "$")
                    cout << "Cuvantul vid este acceptat de automat" << endl;
                else
                    cout << "Cuvantul \"" << word << "\" este acceptat de automat" << endl;
            else if (word == "$")
                cout << "Cuvantul vid nu este acceptat de automat" << endl;
            else
                cout << "Cuvantul \"" << word << "\" nu este acceptat de automat" << endl;

            cout << endl << "Introduceti cuvantul( ';' pentru a iesi, '$' pentru sirul vid ): ";
            cin >> word;
            cout << endl;
        }
    }

    else{

      cout << endl << "Introduceti cuvantul( ';' pentru cuvantul vid ): ";
      cin >> word;
      cout << endl;

      int currentState = dfa.getInitialState();
      if (word == "$"){
        if (dfa.getStates()[currentState].isStateFinal())
          cout << endl << "Cuvantul vid este acceptat de automat";
        else
            cout << endl << "Cuvantul vid nu este acceptat de automat";

        return 0;
      }

      while (word != ";"){
        if (!dfa.isLetterInAlphabet(word)){
            cout << endl << "Litera nu apartine alfabetului";
            break;
        }

        int endState = dfa.getEndState(currentState, word);
        if (endState == -1){
            cout << endl << "Nu exista tranzitie cu aceasta litera";
            break;
        }

        currentState = endState;
        cout << endl << "Introduceti cuvantul( ';' pentru a opri citirea ): ";
        cin >> word;
        cout << endl;
      }

      if (word == ";"){
        if (dfa.getStates()[currentState].isStateFinal())
          cout << endl << "Cuvantul este acceptat de automat";
        else
            cout << endl << "Cuvantul nu este acceptat de automat";
      }
    }
    fileIn.close();
    return 0;
}

//
// Created by Bogdan on 3/12/2018.
//

#include "DFA.h"
#include <bits/stdc++.h>

using namespace std;

State::State(int number = 0, bool isFinal = false){
    this->stateNumber = number;
    this->isFinal = isFinal;
}

void State::pushInRelations(string letter, int state) {
    relations.insert( make_pair(letter, state) );
}

DFA::DFA(int numberOfStates = 0){
    this->numberOfStates = numberOfStates;
    for (int i = 0; i < numberOfStates; i++)
        states.push_back( State(i) );
}

void DFA::setFinalState(int i){
  /* Marcam starea cu nr. i ca fiind finala */
  states[i].setFinalState(true);
}

void DFA::insertInAlphabet(string newLetter) {
    alphabet.push_back(newLetter);
}

bool DFA::isLetterInAlphabet(string letter) {
    for (int i = 0; i < alphabet.size(); i++)
        if (letter == alphabet[i])
            return true;
    return false;
}

int DFA::getStatePosition(int stateNumber) {
    for (int i = 0; i < states.size(); i++)
        if (states[i].getStateNumber() == stateNumber)
            return i;
    return -1;
}

void DFA::markTransition(int firstState, string letter, int secondState) {
    states[firstState].pushInRelations(letter, secondState);
}

void DFA::computeArray(string pattern, int m, int* longestPrefix){
  int length = 0;
  longestPrefix[0] = 0; // Primul element este intotdeauna 0

  int i = 1;
  while (i < m){ // Pana cand am format toate celelalte elemente ale tabloului
    if (pattern[i] == pattern[length]){
        /* Daca am gasit un caracter care se potriveste, trecem mai departe */
        length++;
        longestPrefix[i++] = length;
    }
    else{
        /* Daca nu se potrivesc caracterele trebuie sa reincepem cautarea patternului */
        if (length != 0) // Daca lungimea nu e 0, inseamna ca am gasit anterior un prefix
          length = longestPrefix[length - 1];
        else
            longestPrefix[i++] = 0;
    }
  }
}

vector<int> DFA::searchForAppearances(string word, string pattern){
  /* Algoritmul KMP pentru a gasi aparitiile unui subsir intr-un sir modificat */
  int n = word.size();
  int m = pattern.size();

  int* longestPrefix = new int[m];
  computeArray(pattern, m, longestPrefix);

  vector<int> appearances; // Vectorul in care vom retine indicele de inceput al fiecarei aparitii
  int i = 0, j = 0;
  while (i < n){
    if (pattern[j] == word[i]){
        /* Daca am gasit o potrivire, atunci marim i si j */
        i++;
        j++;
    }
    if (j == m){
        /* Daca j == m, inseamna ca am terminat de gasit un pattern, asa ca adaugam indicele in vector */
        appearances.push_back(i - j);
        j = longestPrefix[j - 1];
    }
    else if (i < n && pattern[j] != word[i]){
        /* Daca nu am gasit o potrivire si i-ul nu a depasit lungimea cuvantului */
        if (j != 0) // am gasit cel putin o potrivire pana acum
            j = longestPrefix[j - 1];
        else
            i++;
    }
  }
  delete[] longestPrefix;
  return appearances;
}

int DFA::getEndState(int firstState, string letter){
  /* Metoda publica pentru a cauta starea de final a unei tranzitii cu litera si starea de inceput furnizate ca parametri */
  State currentStateObj = states[firstState];
  map<string, int> possibleTransitions = currentStateObj.getRelations();
  map<string, int>::iterator it;

  for (it = possibleTransitions.begin(); it != possibleTransitions.end(); it++)
    if (it->first == letter)
        return it->second;
  return -1;
}

bool DFA::isWordAccepted(string word) {
    /* Daca a fost introdus sirul vid, verificam daca starea initiala este si finala */
    if (word == "$"){
        if (states[initialState].isStateFinal())
            return true;
        return false;
    }

    /* In acest map atasam fiecarei litere din alfabet, un vector de nr intregi
    care reprezinta indicele de inceput al fiecarei aparitii in cuvantul care ar trebui acceptat */
    map<string, vector<int> > appearancesHash;
    for(int i = 0; i < alphabet.size(); i++){
      vector<int> appearances = searchForAppearances(word, alphabet[i]);
      appearancesHash.insert( make_pair(alphabet[i], appearances) );
    }

    int currentPosition = 0; // pozitia in cuvant
    int currentState = initialState; // pozitia in automat
    int length = word.size();
    map< string, vector<int> >::iterator it;

    while(currentPosition < length){

      int maximumLength = 0;
      string maxLengthLetter;
      int finalEndState;

      for (it = appearancesHash.begin(); it != appearancesHash.end(); it++){
        /* Parcurg vectorul de aparitii sa vad daca gasesc vreo litera care sa apara pe pozitia curenta.
        Daca o gasesc, aflu care litera (poate sunt mai multe) are lungimea maxima */

        vector<int> appearances = it->second;
        if (find(appearances.begin(), appearances.end(), currentPosition) != appearances.end()){
            int endState = getEndState(currentState, it->first);
            if (it->first.size() > maximumLength && endState != -1){
                maximumLength = it->first.size();
                maxLengthLetter = it->first;
                finalEndState = endState;
            }
        }
      }
      if (maximumLength == 0) // Daca nu am gasit nicio potrivire, inseamna ca nu avem nicio legatura
        return false;

      currentState = finalEndState;
      currentPosition += maximumLength; // Ne deplasam in continuare in cuvant
    }
    if (states[currentState].isStateFinal())
      return true;
    return false;
}

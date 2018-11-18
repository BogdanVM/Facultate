#ifndef DFA_H
#define DFA_H

#include <bits/stdc++.h>
using namespace std;

class State{
    int stateNumber;

    /* Map-ul relations are o cheie de tip string care retine litera care muta starea obiectului curent in starea valoare a map-ului
    adica daca 1 merge in 2 prin litera a, atunci obiectul cu stateNumber = 1 are relations["a"] = 2 */
    map<string, int> relations;
    bool isFinal;

 public:
    inline map<string, int> getRelations() const { return relations; }
    inline bool isStateFinal() const { return isFinal; }
    inline int getStateNumber() const { return stateNumber; }

    inline void setRelations(map<string, int> relations) { this->relations = relations; }
    inline void setFinalState(bool isFinal) { this->isFinal = isFinal; }
    inline void setStateNumber(int stateNumber) { this->stateNumber = stateNumber; }

    void pushInRelations(string, int);
    State(int, bool);
};

class DFA {
    int numberOfStates;
    vector<State> states;
    vector<string> alphabet;
    int initialState;

    int getStatePosition(int);
    vector<int> searchForAppearances(string, string);
    void computeArray(string, int, int*);

 public:
    inline vector<State> getStates() const { return states; }
    inline vector<string> getAlphabet() const { return alphabet; }
    inline int getInitialState() const { return initialState; }
    inline int getNumberOfStates() const { return numberOfStates; }
    inline void setInitialState(int initialState) { this->initialState = initialState; }

    void insertInAlphabet(string);
    bool isLetterInAlphabet(string);
    void markTransition(int, string, int);
    bool isWordAccepted(string);
    void setFinalState(int);
    int getEndState(int, string);

    DFA(int);
};

#endif // DFA_H

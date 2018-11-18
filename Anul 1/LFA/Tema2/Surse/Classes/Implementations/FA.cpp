//
// Created by Bogdan on 4/30/2018.
//
#include "../Headers/FA.h"
#include <bits/stdc++.h>

/*   Utility methods  */
void FA::addState(const State& state) {
    /*  Method that adds the state to the states set */

    auto it = findState(state.getLabel());
    if (it == states.end()) {
        states.insert(state);
    }

}

void FA::addTransition(const State& s1, const std::string& letter, const State& s2) {
    /*  This method adds a transition if the state is already present in the FA */
    auto it = findState(s1.getLabel());
    if (it != states.end()) {
        /* The state specified exists in the FA, so we just add the transition */
        State aux = *it;
        states.erase(it);
        aux.addTransition(s2.getLabel(), letter);

        states.insert(aux);
    }
}

void FA::eraseTransition(const State& s1, const std::string& letter, const State& s2) {
    auto it = findState(s1.getLabel());
    if (it != states.end()) {
        State aux = *it;
        states.erase(it);
        aux.eraseTransition(s2.getLabel(), letter);

        states.insert(aux);
    }
}

void FA::addLetter(const std::string& letter) {

    if (std::find(alphabet.begin(), alphabet.end(), letter) == alphabet.end()) {
        /* If the letter isn't already in the alphabet */
        alphabet.push_back(letter);
    }
}

std::set<State>::iterator FA::findState(const std::string& label) const {
    /*  This method searches for the state label and returns true if found */
    for (auto state = states.begin(); state != states.end(); ++state) {
        if (state->getLabel() == label)
            return state;
    }
    return states.end();
}

void FA::makeFinal(const std::string& label) {
    /*  This method searches for the state label and makes it final state */
    for (auto state : states) {
        if (label == state.getLabel()) {

            State aux = state;
            states.erase(state);
            aux.setFinal(true);
            states.insert(aux);

            return;
        }
    }
}

std::set<State>::iterator FA::findInitialStates() const {
    for (auto it = states.begin(); it != states.end(); ++it) {
        if (it->getInitial())
            return it;
    }

    return states.end();
}

std::queue<State> FA::findFinalStates() const {
    std::queue<State> q;
    for (auto state : states) {
        if (state.getFinal()) {
            q.push(state);
            //std::cout << state.getLabel();
        }
    }

    return q;
}

/*   Operator overloads  */
std::ostream& operator << (std::ostream& o, const FA& fa){
    o << "\nThe automata has " << fa.numberOfStates << " states:\n\n";
    for (auto state : fa.states) {
        o << "{" << state.getLabel() << "}\n";
    }

    o << "\n\n ------------------------------------------------\n";
    o << "\nTHE ALPHABET: ";
    for (auto letter : fa.alphabet) {
        o << letter << " ";
    }

    o << "\nINITIAL STATE: {" << fa.findInitialStates()->getLabel() << "} ";

    o << "\nFINAL STATES: ";
    std::queue<State> q = fa.findFinalStates();
    while (!q.empty()) {
        o << "{" << q.front().getLabel() << "} " << " ";
        q.pop();
    }

    o << "\n\n ------------------------------------------------ \n";
    o << "\n\nTHE TRANSITIONS: \n";
    for (auto state : fa.states) {
        o << state;
    }

    return o;
}
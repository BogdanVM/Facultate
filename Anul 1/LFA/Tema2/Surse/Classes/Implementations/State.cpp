//
// Created by Bogdan on 4/27/2018.
//

#include "../Headers/State.h"
#include <bits/stdc++.h>

/*   Constructors  */
State::State(const std::string& _label, bool _initial, bool _final): label(_label), isInitial(_initial), isFinal(_final)  {}
State::State(const State& s): label(s.label), isInitial(s.isInitial), isFinal(s.isFinal), transitions(s.transitions) {}

/*   Utility methods  */
void State::addTransition(const std::string& stateLabel, const std::string& letter) {
    /*   This method adds a new transition to the map, given the end state label and the letter  */

    auto it = transitions.find(letter);
    if (it != transitions.end()) {
        /*  If there is already a transition from the current state with the letter provided,
         * we add the state label to the value set  */
        it->second.insert(stateLabel);
    }

    /*  If this is the first occurance of the letter, we simply insert it into the map */
    transitions.insert( {letter, {stateLabel} });
}

void State::eraseTransition(const std::string& state, const std::string& letter) {
    auto it = transitions.find(letter);
    if (it != transitions.end()) {
        it->second.erase(state);

        if (it->second.empty()){
            transitions.erase(it);
        }
    }
}

/*   Operator overloads  */
std::ostream& operator << (std::ostream& o, const State& s) {

    for (auto transition : s.transitions) {
        for (auto label : transition.second) {
            o << "\n{" << s.label << "} " << transition.first << " {" << label << "}";
        }
    }

    return o;
}

bool State::operator==(const State& s) {

    if (label != s.label)
        return false;
    if (isInitial != s.isInitial || isFinal != s.isFinal)
        return false;

    return true;
}

bool State::operator!=(const State& s) {
    if (label != s.label)
        return true;
    if (isInitial != s.isInitial || isFinal != s.isFinal)
        return true;

    return false;
}

bool operator<(const State& s1, const State& s2) {
    if (s1.isInitial != s2.isInitial)
        return s1.isInitial;
    if (s1.isFinal != s2.isFinal)
        return !s1.isFinal;

    return s1.label < s2.label;
}
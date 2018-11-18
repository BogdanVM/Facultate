#include <bits/stdc++.h>
#include "Classes/Headers/State.h"
#include "Classes/Headers/FA.h"


/*  3 2
a b
0
1
2
6
0 a 0
0 b 0
0 b 1
1 a 2
2 a 2
2 b 2
*/

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    auto position = s.find(delimiter);
    std::vector<std::string> splitArray;
    std::string aux = s;

    while (position != std::string::npos) {
        splitArray.push_back( aux.substr(0, position) );
        aux.erase(0, position + delimiter.size());
        position = aux.find(delimiter);
    }

    splitArray.push_back(aux);
    return splitArray;
}

std::string sortStateLabel(std::string s) {
    /*  Function that sorts a string that looks like this: "1,0,2" to "0,1,2"  */
    auto v = split(s, ",");
    std::sort(v.begin(), v.end());

    std::string finalS = "";
    for(auto e : v) {
        finalS += e + ",";
    }
    finalS.erase(finalS.size() - 1);

    return finalS;
}

FA turnToDFA(const FA& nfa) {

    /* In this queue we'll store the states as we iterate through them */
    std::queue<std::string> currentStates;
    std::set<std::string> visited;
    FA dfa;

    /* We first add the existing states to the queue */
//    for (auto state : nfa.getStates()) {
//        currentStates.push(state.getLabel());
//        visited.insert(state.getLabel());
//        dfa.addState(state);
//    }

    auto it = nfa.findInitialStates();
    currentStates.push(it->getLabel());
    visited.insert(it->getLabel());
    dfa.addState(*it);

    while (!currentStates.empty()) {
        std::string label = currentStates.front(); // we get the current state and delete it from the queue
        currentStates.pop();
        visited.insert(label); // we mark the state as visited


        /*  We split the label by the comma character. Our states look like this:
         * - {0, 1}, {0, 2}... and we need to get each single state of this strings */
        auto separatedStatesVector = split(label, ",");

        for (auto letter : nfa.getAlphabet()) {
            /* For each letter of the alphabet we see what transitions we have */
            std::string newState = "";

            for (auto state : separatedStatesVector) {
                auto transitions = nfa.findState(state)->getTransitions();

                for (auto finalState : transitions[letter]){
                    if (newState.find(finalState) == std::string::npos)
                        newState += finalState + ",";
                }
            }

            if (newState != "") {
                newState.erase(newState.size() - 1);

                newState = sortStateLabel(newState);

                dfa.addState(newState);
                dfa.addTransition(label, letter, newState);

                if (visited.find(newState) == visited.end()) {
                    /* If we found a new state, we add it to the queue  */
                    currentStates.push(newState);
                }
            }
        }
    }

    for (auto state : dfa.getStates()) {
        dfa.setNumberOfStates(dfa.getNumberOfStates() + 1);

        auto trans = state.getTransitions();
        for (auto it : trans) {
            if (it.second.size() > 1){
                /* If there is more than one end state we delete the single states */

                for (auto elem : it.second) {
                    if (elem.find(",") == std::string::npos) {
                        dfa.eraseTransition(state, it.first, elem);
                    }
                }
            }
        }

        /* We search for the final states of the nfa to mark them in the dfa */
        std::queue<State> q = nfa.findFinalStates();
        while (!q.empty()) {
            if (state.getLabel().find(q.front().getLabel()) != std::string::npos) {
                /* if the state label contains one final state from the nfa, it's marked as final */
                dfa.makeFinal(state.getLabel());
                break;
            }

            q.pop();
        }
    }

    dfa.setAlphabet(nfa.getAlphabet());
    return dfa;
}

int main() {
    std::ifstream fin("lfa.in");
    std::ofstream fout("lfa.out");

    int n;
    FA nfa;

    fin >> n; // number of states
    nfa.setNumberOfStates(n);

    fin >> n; // number of letters
    for (int i = 0; i < n; ++i) {
        std::string letter;
        fin >> letter;
        nfa.addLetter(letter);
    }

    std::string s;
    fin >> s; // initial state
    nfa.addState(State(s, true)); // we add the state to the nfa as initial state

    fin >> n; // number of final states
    for (int i = 0; i < n; ++i) {
        fin >> s; // read a final state

        nfa.addState(State(s, false, true));
        nfa.makeFinal(s);
    }

    fin >> n; // number of transitions
    for (int i = 0; i < n; ++i) {
        std::string start, letter, end;
        fin >> start >> letter >> end;

        nfa.addState(State(start));
        nfa.addState(State(end));

        nfa.addTransition(State(start), letter, State(end));
    }

    FA dfa;
    dfa = turnToDFA(nfa);

    fout << "\n" << dfa;
    fin.close();
    fout.close();
    return 0;
}
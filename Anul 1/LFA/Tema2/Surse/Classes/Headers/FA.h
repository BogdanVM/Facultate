//
// Created by Bogdan on 4/30/2018.
//

#ifndef TEMA2_FINAL_V2_FA_H
#define TEMA2_FINAL_V2_FA_H

#include <bits/stdc++.h>
#include "State.h"

class FA{
    int numberOfStates;
    std::set<State> states;
    std::vector<std::string> alphabet;

    /*  Private utility methods  */

public:
    /*  Constructors and destructor  */
    FA() : numberOfStates(0) {}
    FA(int _numberOfStates) : numberOfStates(_numberOfStates) {}
    FA(const FA& fa) : numberOfStates(fa.numberOfStates), states(fa.states) {}
    ~FA() {}

    /*  Getters and setters  */
    inline int getNumberOfStates() const { return numberOfStates; }
    inline std::set<State> getStates() const { return states; }
    inline std::vector<std::string> getAlphabet() const { return alphabet; }
    inline void setNumberOfStates(int _numberOfStates) { numberOfStates = _numberOfStates; }
    inline void setAlphabet(std::vector<std::string> _alphabet) { alphabet = _alphabet; }

    /*  Utility methods  */
    void addState(const State&);
    void addTransition(const State&, const std::string&, const State&);
    void eraseTransition(const State&, const std::string&, const State&);
    void addLetter(const std::string&);
    void makeFinal(const std::string&);
    std::set<State>::iterator findState(const std::string&) const;
    std::set<State>::iterator findInitialStates() const;
    std::queue<State> findFinalStates() const;

    /*  Operator overloads  */
    friend std::ostream& operator << (std::ostream&, const FA&);
};

#endif //TEMA2_FINAL_V2_FA_H

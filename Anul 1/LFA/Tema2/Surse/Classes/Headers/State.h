//
// Created by Bogdan on 4/27/2018.
//

#ifndef TEMA2_FINAL_V2_STATE_H
#define TEMA2_FINAL_V2_STATE_H

#include <bits/stdc++.h>

class State {
    std::string label; // the label of the current state
    bool isInitial, isFinal;

    /* A map which will hold the transitions from the current state like this:
     * - the key = a letter of the alphabet;
     * - the value = a vector holding all the end states from the current state with the letter provided as key */
    std::map< std::string, std::set<std::string> > transitions;


public:
    /*   Constructors and destructor  */
    State() {}
    State(const std::string&, bool = false, bool = false);
    State(const State&);
    ~State() {}

    /*   Getters  */
    inline std::string getLabel() const { return label; }
    inline bool getInitial() const { return isInitial; }
    inline bool getFinal() const { return isFinal; }
    inline std::map< std::string, std::set<std::string> > getTransitions() const { return transitions; }

    /*   Setters  */
    inline void setLabel(std::string _label) { label = _label; }
    inline void setInitial(bool _isInitial) { isInitial = _isInitial; }
    inline void setFinal(bool _isFinal) { isFinal = _isFinal; }

    /*   Utility methods  */
    void addTransition(const std::string&, const std::string&);
    void eraseTransition(const std::string&, const std::string&);

    /*   Operator overloads  */
    friend std::ostream& operator << (std::ostream&, const State&);
    bool operator == (const State&);
    bool operator != (const State&);
    //bool operator < (const State&);
    friend bool operator < (const State&, const State&);
};


#endif //TEMA2_FINAL_V2_STATE_H

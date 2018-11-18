//
// Created by Bogdan on 5/4/2018.
//

#ifndef TEMA3_CEC_H
#define TEMA3_CEC_H


#include "Plata.h"

class Cec : public Plata {
    std::string name;

public:
    /*   Constructors and destructor  */
    Cec() {}
    Cec(const std::string& _name) : name(_name) {}
    Cec(const std::string& _name, const std::string& _date, double _sum) : Plata(_date, _sum), name(_name) {}
    Cec(const Cec& cec) : Plata(cec.date, cec.sum), name(cec.name) {}
    ~Cec() {}

    /*   Getters and setters  */
    std::string getName() const { return name; }
    void setName(const std::string& _name) { name = _name; }

    /*   Utility methods   */

    void display(std::ostream&) const;

    /*   Operator overloads  */
    friend std::istream& operator >> (std::istream&, Cec&);
    friend std::ostream& operator << (std::ostream&, const Cec&);
    const Cec& operator = (const Cec&);
};

#endif //TEMA3_CEC_H

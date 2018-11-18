//
// Created by Bogdan on 5/4/2018.
//

#ifndef TEMA3_CASH_H
#define TEMA3_CASH_H

#include "Plata.h"

class Cash : public Plata {

public:
    /*   Constructors and destructor  */
    Cash() {}
    Cash(const std::string& _date, double _sum) : Plata(_date, _sum) {}
    Cash(const Cash& cash) : Plata(cash.date, cash.sum) {}
    ~Cash() {}

    /*   Utility methods  */
    void display(std::ostream&) const;

    /*   Operator overloads  */
    friend std::istream& operator >> (std::istream&, Cash&);
    friend std::ostream& operator << (std::ostream&, const Cash&);
    const Cash& operator = (const Cash&);
};

#endif //TEMA3_CASH_H

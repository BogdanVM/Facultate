//
// Created by Bogdan on 5/4/2018.
//

#include "../Headers/Cash.h"

/*  Utility methods  */
void Cash::display(std::ostream& o) const {
    Plata::display(o);
}

/*  Operator overloads  */
std::istream& operator >> (std::istream& in, Cash& cash) {
    Plata plata;
    in >> plata;

    cash.date = plata.getDate();
    cash.sum = plata.getSum();
    return in;
}

std::ostream& operator << (std::ostream& o, const Cash& cash) {
    cash.display(o);
    return o;
}

const Cash& Cash::operator=(const Cash& cash) {
    if (this != &cash) {
        date = cash.date;
        sum = cash.sum;
    }
    return *this;
}

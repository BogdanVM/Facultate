//
// Created by Bogdan on 5/4/2018.
//

#ifndef TEMA3_CARD_H
#define TEMA3_CARD_H

#include <bits/stdc++.h>
#include "Plata.h"

class Card : public Plata {

    std::string number;
    std::string name;

public:
    /*   Constructors and destructor  */
    Card() {}
    Card(const std::string& _number, const std::string& _name) : number(_number), name(_name) {}
    Card(const std::string& _date, const std::string& _name, const std::string& _number, double _sum): Plata(_date, _sum), number(_number),
                                                                                                        name(_name) {}
    Card(const Card& card) : Plata(card.date, card.sum), number(card.number), name(card.name) {}
    ~Card() {}

    /* Getters and setters  */
    inline std::string getNumber() const { return number; }
    inline std::string getName() const { return name; }
    inline void setNumber(const std::string& _number) { number = _number; }
    inline void setName(const std::string& _name) { name = _name; }

    /* Utility methods */
    void display(std::ostream&) const;

    /*  Operator overloading */
    friend std::istream& operator >> (std::istream&, Card&);
    friend std::ostream& operator << (std::ostream&, const Card&);
    const Card& operator = (const Card&);
};

#endif //TEMA3_CARD_H

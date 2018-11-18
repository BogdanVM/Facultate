//
// Created by Bogdan on 5/4/2018.
//

#include <bits/stdc++.h>
#include "../Headers/Card.h"
#include "../Headers/Functions.h"

/*  Utility methods  */

void Card::display(std::ostream& o) const {
    Plata::display(o);
    o << "Numarul cardului: " << number << "\n";
    o << "Numele platitorului: " << name << "\n";
}

/*  Operator overloads  */

std::istream& operator >> (std::istream& in, Card& card) {

    Plata plata;
    in >> plata;

    card.date = plata.getDate();
    card.sum = plata.getSum();

    std::string s;

    do {

        try {
            std::cout << "Introduceti numarul cardului: ";
            std::getline(in >> std::ws, s);

            if (!Functions::validCard(s)){
                throw std::runtime_error("NUMARUL INTRODUS NU ESTE VALID");
            }

            break;

        } catch (std::runtime_error error) {
            std::cout << "\n---------------xxxx---------------";
            std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
            std::cout << "\n---------------xxxx---------------" << "\n";
        }
    } while (1);

    card.number = s;

    do {
        try{

            std::cout << "Introduceti numele platitorului: ";
            std::getline(in >> std::ws, s);

            if (!Functions::validName(s)) {
                throw std::runtime_error("NUMELE INTRODUS NU ESTE VALID");
            }

            break;

        } catch (std::runtime_error error) {
            std::cout << "\n---------------xxxx---------------";
            std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
            std::cout << "\n---------------xxxx---------------" << "\n";
        }
    } while (1);

    card.name = s;
    return in;
}

std::ostream& operator << (std::ostream& o, const Card& card) {
    card.display(o);
    return o;
}

const Card& Card::operator=(const Card& card) {

    if (this != &card) {
        date = card.date;
        sum = card.sum;
        number = card.number;
    }
    return *this;
}

//
// Created by Bogdan on 5/2/2018.
//

#include <bits/stdc++.h>
#include "../Headers/Plata.h"
#include "../Headers/Functions.h"

/*  UTILITY METHODS  */

void Plata::display(std::ostream& o) const {
    o << "\nPlata in valoare de " << sum << " a fost efectuata in data de " << date;
    o << "\n";

}

/*  OPERATOR OVERLOADS  */
std::istream& operator >> (std::istream& in, Plata& p) {

    std::string s;
    double x;

    do {
        try {
            std::cout << "\nIntroduceti data cand a fost efectuata plata (format DD/MM/YYYY): ";
            std::getline(in >> std::ws, s);

            /*  Daca nr de caractere difera de formatul acceptat, aruncam o exceptie  */
            if (s.size() != 10) {
                throw std::runtime_error("FORMAT INCORECT. DATA TREBUIE INTRODUSA ASTFEL: DD/MM/YYYY");
            }

            /*  Incercam sa extragem din sirul citit ziua, luna si anul.
             * Daca citirea nu s-a facut corect vom trata exceptiile in catch */
            unsigned int day = Functions::convertFromString<int>(s.substr(0, 2));
            unsigned int month = Functions::convertFromString<int>(s.substr(3, 2));
            unsigned int year = Functions::convertFromString<int>(s.substr(6, 4));

            if (!Functions::correctDate(day, month, year)) {
                throw std::runtime_error("DATA NU ESTE VALIDA!");
            }

            break; // daca nu am aruncat nicio exceptie, incheiem executia do-while

        }
        catch (std::runtime_error error) {
            std::cout << "\n---------------xxxx---------------";
            std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
            std::cout << "\n---------------xxxx---------------" << "\n";
        }
    } while (1);

    p.date = s; // daca am trecut cu bine de acest do while, inseamna ca data a fost specificata corect


    do {
        try {
            std::cout << "Introduceti suma achitata: ";
            std::getline(in >> std::ws, s);

            if (s.find_first_not_of("0123456789.") != std::string::npos)
                throw std::runtime_error("FORMAT NEVALID");

            x = Functions::convertFromString<double>(s);
            break;

        } catch (std::runtime_error error) {
            std::cout << "\n---------------xxxx---------------";
            std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
            std::cout << "\n---------------xxxx---------------" << "\n";
        }
    } while (1);

    p.sum = x; // daca am iesit din do-while, inseamna ca am citit o suma valida
    return in;
}

std::ostream& operator << (std::ostream& o, const Plata& plata) {
    plata.display(o);
    return o;
}

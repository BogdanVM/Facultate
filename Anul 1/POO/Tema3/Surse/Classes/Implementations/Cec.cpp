//
// Created by Bogdan on 5/4/2018.
//

#include "../Headers/Cec.h"
#include "../Headers/Functions.h"

/*   Utility methods  */
void Cec::display(std::ostream& o) const {
    Plata::display(o);
    o << "Numele platitorului: " << name << "\n";
}

/*   Operator overloads  */
std::istream& operator >> (std::istream& in, Cec& cec) {
    std::string s;

    Plata plata;
    in >> plata;

    cec.date = plata.getDate();
    cec.sum = plata.getSum();

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

    cec.name = s;
    return in;
}

std::ostream& operator << (std::ostream& o, const Cec& cec) {
    cec.display(o);
    return o;
}

const Cec& Cec::operator=(const Cec& cec) {
    if (this != &cec) {
        date = cec.date;
        sum = cec.sum;
        name = cec.name;
    }
    return *this;
}

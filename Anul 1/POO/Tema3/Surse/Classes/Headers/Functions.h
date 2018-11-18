//
// Created by Bogdan on 5/4/2018.
//

#ifndef TEMA3_FUNCTIONS_H
#define TEMA3_FUNCTIONS_H

#include <bits/stdc++.h>

struct Functions {

    /* In aceasta structura vom retine functiile utile de care ne vom folosi in program */

    /*  Numar de card valid */
    static bool validCard(const std::string& nr) {
        if (nr.size() != 16)
            return false;
        if (nr.find_first_not_of("0123456789") != std::string::npos)
            return false;

        int length = nr.size();
        int suma = 0;
        for (int i = length - 1; i >= 0; i -= 2) {
            /*  Calculam suma de la dreapta la stanga din 2 in 2. Adica:
            - 123456789 : calculam 9 + 7 + 5 + 3 + 1 = 25 */
            suma += nr[i] - '0';
        }

        for (int i = length - 2; i >= 0; i -= 2) {
            /* Acum dublam valoarea cifrelor ramase si calculam suma cifrelor dublului. Adica:
            - 123456789: dublam si ramanem cu: 16, 12, 8, 4;
            - apoi calculam : 1 + 6 + 1 + 2 + 8 + 4 = 22 */
            int dublu = (nr[i] - '0') * 2;
            suma += digitSum(dublu);
        }

        /* Daca suma e un multiplu de 10, numarul cardului este valid */
        if (suma % 10 == 0)
            return true;

        return false;
    }

    /*  Data valida  */
    static bool correctDate(unsigned int day, unsigned int month, unsigned int year) {

        /* Daca nu sunt indeplinite conditiile elementare pentru o data specificata corect, intoarcem fals */
        if (month < 1 || month > 12)
            return false;
        if (day < 1 || day > 31)
            return false;

        /* Verificam daca luna este februarie si luam si cazul anului bisect */
        if (month == 2) {
            bool leap = false;

            /* Un an este bisect daca e divizibil cu 400 sau e divizibil cu 4 si nu e divizibil cu 100 */
            if (year % 4 == 0) {
                if (year % 100 != 0) {
                    leap = true;
                }
                else if (year % 100 == 0) {
                    if (year % 400 == 0)
                        leap = true;
                    else
                        leap = false;
                }
            }

            if (leap) {
                /* Daca este an bisect, atunci ziua este cuprinsa intre [1, 29] */
                if (day > 29)
                    return false;
                else
                    return true;
            }

            else {
                if (day > 28)
                    return false;
                else
                    return true;
            }
        }
        /* Verificam ca ziua specificata sa fie inclusa in intervalul de zile specific fiecarei luni */
        const int day30[] = {4, 6, 9, 11};

        std::vector<int> months(day30, day30 + 4);
        if (std::find(months.begin(), months.end(), month) != months.end()) {
            /* Daca ne aflam intr-o luna cu 30 de zile, facem verificarea corespunzatoare */
            if (day > 30)
                return false;
        }

        return true;
    }

    /*  Suma cifrelor  */
    static int digitSum(int n) {
        int s = 0;

        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    /*  Nume valid  */
    static bool validName (const std::string& name) {
        int n = name.size();
        for (int i = 0; i < n; ++i) {
            /*  Testam toate cazurile de validitate ale unui nume:
             * - cratima, daca exista, se afla in interiorul numelui si nu la final sau la inceput;
             * - spatiul trebuie ignorat;
             * - in rest, numele trebuie sa contina doar caractere numerice */
            if (name[i] == ' ')
                continue;
            if (name[i] == '-' && i != 0 && i != n-1)
                continue;

            if (name[i] < 'A')
                return false;
            if (name[i] > 'Z' && name[i] < 'a')
                return false;
            if (name[i] > 'z')
                return false;
        }

        /*  Acum testam sa existe cel putin 2 nume la separarea prin caracterul spatiu */
        std::string firstName = name.substr(0, name.find(" "));
        if (firstName.size() == name.size())
            return false;

        return true;
    }

    /*  Functie template care converteste un string intr-un tip de date ca parametru */
    template <class T>
    static T convertFromString (const std::string& s) {

        std::istringstream buffer(s);

        T value;
        if (!(buffer >> value))
            throw std::runtime_error("FORMAT NEVALID");

        return value;
    }
};

#endif //TEMA3_FUNCTIONS_H

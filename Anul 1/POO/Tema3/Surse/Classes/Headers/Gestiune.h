//
// Created by Bogdan on 5/4/2018.
//

#ifndef TEMA3_GESTIUNE_H
#define TEMA3_GESTIUNE_H

#include "Plata.h"

template <class T>
class Gestiune {
    static int nrPlati;
    std::vector<T*> plati;

public:
    /*  Constructors and destructor */
    Gestiune() {}
    Gestiune(std::vector<T*> _plati): plati(_plati) {}
    Gestiune(const Gestiune& gestiune): plati(gestiune.plati) {}
    ~Gestiune() {
        for (int i = 0; i < plati.size(); i++)
            delete plati[i];
    }

    /*   Getters and setters  */
    static int getNrPlati() { return nrPlati; }
    std::vector<T*> getPlati() const { return plati; }

    /*  Utility methods  */


    /*  Operator overloads  */
    const Gestiune& operator += (T& _plata) {
        plati.push_back(&_plata);
        nrPlati++;

        return *this;
    }

    const Gestiune& operator = (const Gestiune& gestiune) {
        if (this != &gestiune) {
            plati = gestiune.plati;
        }

        return *this;
    }

    friend std::ostream& operator << (std::ostream& o, const Gestiune& gestiune) {
        o << "\nNumar plati: " << Gestiune::nrPlati;
        o << "\nPlati: ";
        for (int i = 0; i < Gestiune::nrPlati; i++) {
            o << gestiune.plati[i];
        }
        return o;
    }
};

template <>
class Gestiune<std::string> {
    int nrClienti;
    std::vector<std::string> clienti;

public:
    /*  Constructors and destructor  */
    Gestiune(): nrClienti(0) {}
    Gestiune(int _nrClienti): nrClienti(_nrClienti) { clienti.resize(_nrClienti, ""); }
    Gestiune(const Gestiune&);
    ~Gestiune() {}

    /*  Getters and setters  */
    int getNrClienti() const { return nrClienti; }
    std::vector<std::string> getClienti() const { return clienti; }
    void setNrClienti(int _nrClienti) { nrClienti = _nrClienti; }

    /*  Utility methods  */


    /*  Operator overloads  */
    Gestiune<std::string>& operator + (const std::string& nume) {
        if (std::find(clienti.begin(), clienti.end(), nume) == clienti.end()) {
            /*  Daca numele nu exista deja in vectorul de clienti */
            clienti.push_back(nume);
            nrClienti++;
        }

        return *this;
    }

    friend std::ostream& operator << (std::ostream& o, const Gestiune<std::string>& g) {
        o << "\nNumarul de clienti: " << g.nrClienti << "\nClientii:";
        for (int i = 0; i < g.nrClienti; i++)
            o << "\t" << g.clienti[i] << "\n";
        return o;
    }
};

#endif //TEMA3_GESTIUNE_H

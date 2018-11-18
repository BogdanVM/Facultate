#include <bits/stdc++.h>
#include "Classes/Headers/Gestiune.h"
#include "Classes/Headers/Card.h"
#include "Classes/Headers/Cec.h"
#include "Classes/Headers/Cash.h"
#include "Classes/Headers/Functions.h"

template <class T>
int Gestiune<T>::nrPlati = 2;

void displayMenu() {
    std::cout << "\nURMATOAREA PLATA ESTE DE TIP: ";
    std::cout << "\n1)  CASH";
    std::cout << "\n2)  CARD";
    std::cout << "\n3)  CEC\n";
    std::cout << "Introduceti optiunea aleasa: ";
}

int main() {

    Gestiune<Plata> payments; // sablonul
    Gestiune<std::string> clients; // specializarea

    int n;
    std::string s;
    do {
        try {
            std::cout << "\nIntroduceti numarul de plati efectuate: ";
            std::getline(std::cin >> std::ws, s);

            if (s.find_first_not_of("0123456789") != std::string::npos)
                throw std::runtime_error("FORMAT NEVALID");

            n = Functions::convertFromString<int>(s);
            break;

        } catch (std::runtime_error error) {
            std::cout << "\n---------------xxxx---------------";
            std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
            std::cout << "\n---------------xxxx---------------" << "\n";
        }
    } while(1);

    for (int i = 0; i < n;){
        /* Citim de fiecare data o optiune, pentru a stabili ce fel de plata vom adauga */
        int option;

        do {
            try{
                displayMenu();
                std::getline(std::cin >> std::ws, s);

                if (s.find_first_not_of("0123456789") != std::string::npos)
                    throw std::runtime_error("FORMAT NEVALID");

                option = Functions::convertFromString<int>(s);
                break;
            }
            catch (std::runtime_error error)
            {
                std::cout << "\n---------------xxxx---------------";
                std::cout << "\nA avut loc o eroare la citire: \n" << error.what();
                std::cout << "\n---------------xxxx---------------" << "\n";
            }
        } while (1);

        switch (option) {
            case 1: {
                Cash* cash = new Cash;
                std::cin >> (*cash); // citim plata de tip cash

                payments += (*cash);
                i++;
                break;
            }

            case 2: {
                Card* card = new Card;
                std::cin >> (*card); // citim plata de tip card

                payments += (*card);
                clients = clients + card->getName();
                i++;
                break;
            }

            case 3: {
                Cec* cec = new Cec;
                std::cin >> (*cec); // citim plata de tip cec

                payments += (*cec);
                clients = clients + cec->getName();
                i++;
                break;
            }

            default: {
                std::cout << "\n---------------xxxx---------------";
                std::cout << "\nOPTIUNEA INTRODUSA NU ESTE VALIDA";
                std::cout << "\n---------------xxxx---------------" << "\n";
            }
        }
    }

    std::vector<Plata*> paymentsVector = payments.getPlati();
    for (int i = 0; i < paymentsVector.size(); ++i) {
        /* Parcurgem fiecare plata si vedem de ce tip e */
        if (Card* card = dynamic_cast<Card*>(paymentsVector[i])) {
            std::cout << "\n---------------****---------------";
            std::cout << "\nCARD:\n" << *card;
        }

        else if (Cash* cash = dynamic_cast<Cash*>(paymentsVector[i])) {
            std::cout << "\n---------------****---------------";
            std::cout << "\nCASH:\n" << *cash;
        }

        else if (Cec* cec = dynamic_cast<Cec*>(paymentsVector[i])) {
            std::cout << "\n---------------****---------------";
            std::cout << "\nCEC:\n" << *cec;
        }
    }

    std::cout << "\n---------------****---------------";
    if (clients.getNrClienti() == 0) {
        std::cout << "\nNu exista niciun client inregistrat\n";
    }

    else {
        std::cout << "\nNumarul de clienti: " << clients.getNrClienti() << "\nClientii: \n";
        for (int i = 0; i < clients.getClienti().size(); i++)
           std::cout << "\t- " << clients.getClienti()[i] << "\n";
    }
    return 0;
}

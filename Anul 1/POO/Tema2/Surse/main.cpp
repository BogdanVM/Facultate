#include <bits/stdc++.h>
#include "shapes.h"
using namespace std;

void displayMenu()
{
    cout << endl << "(1) Patrat";
    cout << endl << "(2) Dreptunghi";
    cout << endl << "(3) Romb";
    cout << endl << "(4) Paralelogram";
    cout << endl << "(5) Trapez";
    cout << endl << endl << "Introduceti forma aleasa: ";
}

void displayMenuShape()
{
   cout << endl << "(1) Arie ";
   cout << endl << "(2) Perimetru ";
   cout << endl << "(0) IESIRE";
   cout << endl << endl << "Introduceti optiunea aleasa: ";
}

template<class T>
void meniuForma(T forma)
{
   int choice;

   do{
      displayMenuShape();
      cin >> choice;

      switch(choice)
      {
          case 0:
            break;

          case 1: {
            float arie = forma.arie();
            if (arie == -1){
                cout << endl << "Figura specificata nu este valida" << endl;
                break;
            }

            cout << endl << "Aria = " << forma.arie();
            break;
          }

          case 2: {
            float perimetru = forma.perimetru();
            if (perimetru == -1){
                cout << endl << "Figura specificata nu este valida" << endl;
                break;
            }

            cout << endl << "Perimetru = " << forma.perimetru();
            break;
          }

          default:
            cout << endl << "Optiunea introdusa nu este valida";
            break;
      }
   }while (choice);
}

int Patrat::nrObiecte;

int main()
{
    int n;

    cout << "Numarul de forme geometrice: ";
    cin >> n;

    Patrat* shapes[n];
    for(int i = 0; i < n; i++)
    {
        bool ok = true;
        do{
            ok = true;
            int choice;
            displayMenu();
            cin >> choice;

            switch(choice)
            {
            case 1:
            {
                Patrat p;
                cin >> p;
                shapes[i] = new Patrat(p);

                meniuForma(p);
                break;
            }

            case 2:
            {
                Dreptunghi d;
                cin >> d;
                shapes[i] = new Dreptunghi(d);

                meniuForma(d);
                break;
            }

            case 3:
            {
                Romb r;
                cin >> r;
                shapes[i] = new Romb(r);

                meniuForma(r);
                break;
            }

            case 4:
            {
                Paralelogram p;
                cin >> p;
                shapes[i] = new Paralelogram(p);

                meniuForma(p);
                break;
            }

            case 5:
            {
                Trapez t;
                cin >> t;
                shapes[i] = new Trapez(t);

                meniuForma(t);
                break;
            }

            default:
                cout << endl << "Optiunea introdusa nu este valida" << endl;
                ok = false;
                break;
            }
        }
        while (!ok);
    }

    for(int i = 0; i < n; i++)
    {

        if (Trapez* t = dynamic_cast<Trapez*>(shapes[i])){
            cout << *t;
        }
        else if (Paralelogram* p = dynamic_cast<Paralelogram*>(shapes[i])){
            cout << *p;
        }
        else if (Dreptunghi* d = dynamic_cast<Dreptunghi*>(shapes[i])){
            cout << *d;
        }
        else if (Romb* r = dynamic_cast<Romb*>(shapes[i])){
            cout << *r;
        }
        else if (Patrat* p = dynamic_cast<Patrat*>(shapes[i])){
            cout << *p;
        }
    }

    cout << endl << "Numarul de obiecte: " << Patrat::getNrObiecte() << endl;
    for (int i = 0; i < n; i++)
        delete shapes[i];

    cout << endl << "Numarul de obiecte: " << Patrat::getNrObiecte() << endl;
    return 0;
}

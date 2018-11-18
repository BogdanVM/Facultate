#include <bits/stdc++.h>
#include "../shapes.h"
using namespace std;

    /* Constructori cu si fara parametrii */
Romb::Romb() {}
Romb::Romb(const Punct& pco) : coltOpus(pco) {}

Romb::Romb(const Punct& pco, const Punct& psj, float l) : Patrat(psj, l), coltOpus(pco)
{
   valid = isShapeValid() ? 1 : 0;
}

     /* Constructorul de copiere */
Romb::Romb(const Romb& r) : Patrat(r.stangaJos, r.latura), coltOpus(r.coltOpus)
{
   valid = isShapeValid() ? 1 : 0;
}

    /*  Destructorul */
Romb::~Romb() {}

   /*  Operatorii =, <<, >> */

const Romb& Romb::operator = (const Romb& r)
{
    if (this != &r)
    {
        stangaJos = r.stangaJos;
        latura = r.latura;
        coltOpus = r.coltOpus;
        valid = r.valid;
    }
    return *this;
}

istream& operator >> (istream& in, Romb& r)
{
    cout << "INTRODUCETI ROMBUL: \nColtul din stanga jos: ";
    in >> r.stangaJos;

    int x;
    do{
        cout << "Latura rombului = ";
        in >> x;
    } while (x <= 0);

    r.latura = x;

    cout << "Coltul opus: ";
    in >> r.coltOpus;

    return in;
}

ostream& operator << (ostream& out, const Romb& r)
{
    out << "ROMB: \nColtul din stanga jos: " << r.stangaJos << "latura = " << r.latura << "\nColtul opus: " << r.coltOpus << endl;

    if (r.valid == 1)
       out << "Aria = " << r.arie() << endl << "Perimetru = " << r.perimetru() << endl;

    else
       out << "Figura nu este valida" << endl;

    return out;
}

bool Romb::isShapeValid() const
{
    /* Extragem coordonatele celorlalte 2 puncte din romb, plecand de la presupunerea enuntului ca sunt 2 laturi paralele cu Ox */
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());
    const Punct stSus(coltOpus.getX() - latura, coltOpus.getY());

    float side = distanta(coltOpus, drJos); // lungimea laturii care uneste punctele dreapta jos si dreapta sus
    if (side != latura)
    {
        return false;
    }

    /* Figura este corecta, daca diferentele coordonatelor punctelor sunt egale */
    if (abs(stSus.getX() - stangaJos.getX()) == abs(coltOpus.getX() - drJos.getX())) // Coordonatele x corespund
    {
        if (stSus.getY() - stangaJos.getY() == coltOpus.getY() - drJos.getY()) // Si coordonatele de pe Oy corespund, atunci figura e corecta
        {
            return true;
        }
    }

    return false;
}

float Romb::arie() const
{
    if (valid == 0)
    {
        cout << endl << "Figura nu este valida" << endl;
        return -1;
    }

    /* Aflam coordonatele celorlalte 2 puncte din romb */
   const Punct stSus(coltOpus.getX() - latura, coltOpus.getY());
   const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());

   /* Aflam lungimile diagonalelor folosindu-ne de coordonatele punctelor */
   float d1 = distanta(coltOpus, stangaJos);
   float d2 = distanta(drJos, stSus);

   return (d1 * d2) / 2;
}

#include <iostream>
#include "../shapes.h"
using namespace std;

    /* Constructori de initializare */

Paralelogram::Paralelogram(const Punct& psj, const Punct& pco, float l1, float l2)
                        : Patrat(psj, l1), Dreptunghi(l2), Romb(pco)
{
   valid = isShapeValid() ? 1 : 0; // daca forma e corect specificata valid = 1, altfel valid = 0
}

Paralelogram::Paralelogram() {}

      /* Constructor de copiere */
Paralelogram::Paralelogram(const Paralelogram& p) : Patrat(p.stangaJos, p.latura), Dreptunghi(p.latura2), Romb(p.coltOpus)
{
   valid = p.valid;
}

bool Paralelogram::isShapeValid() const
{
    /* Aflam coordonatele punctelor din dreapta jos si stanga sus */
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());
    const Punct stSus(coltOpus.getX() - latura, coltOpus.getY());

    /* Aflam latura care uneste pct dreapta sus cu cel din dreapta jos,
    apoi verificam daca acesta chiar este egal cu latura specificata ca data a obiectului */
    float side = distanta(coltOpus, drJos);
    if (side != latura2)
    {
        return false;
    }

    /* Ne deplasam intai pe axa Ox, apoi pe Oy respectand coordonatele furnizate obiectului.
    Daca am ajuns pe acelasi pct pe Ox, respectiv Oy, inseamna ca laturile sunt paralele */
    if (abs(stSus.getX() - stangaJos.getX()) == abs(coltOpus.getX() - drJos.getX()))
    {
        if (stSus.getY() - stangaJos.getY() == coltOpus.getY() - drJos.getY())
        {
            return true;
        }
    }

    /* Daca inca nu am returnat nimic, atunci figura nu are laturile opuse paralele */
    return false;
}

      /*  Operatorul de atribuire  */
const Paralelogram& Paralelogram::operator = (const Paralelogram& p)
{
   if (this != &p)
   {
       /* Copiem toate datele din p in obiectul this */
       latura = p.latura;
       latura2 = p.latura2;
       stangaJos = p.stangaJos;
       coltOpus = p.coltOpus;
       valid = p.valid;
   }
   return *this;
}

      /*  Operatorii >> si << */
istream& operator >> (istream& in, Paralelogram& p)
{
   cout << "INTRODUCETI PARALELOGRAMUL: \nColtul din stanga jos: ";
   in >> p.stangaJos;

   cout << "Coltul din dreapta sus: ";
   in >> p.coltOpus;

   cout << "Lungimea laturilor paralele cu Ox: ";
   in >> p.latura;

   cout << "Lungimile celorlalte laturi: ";
   in >> p.latura2;

   if (p.latura <= 0 || p.latura2 <= 0){
      p.valid = 0;
      return in;
   }
   if (p.stangaJos.getX() >= p.coltOpus.getX() || p.stangaJos.getY() >= p.coltOpus.getY()){
      p.valid = 0;
      return in;
   }

   p.valid = p.isShapeValid() ? 1 : 0;
   return in;
}

ostream& operator << (ostream& out, const Paralelogram& p)
{
   out << endl << "PARALELOGRAM:\nColtul din stanga jos: " << p.stangaJos;
   out << "Coltul din dreapta sus: " << p.coltOpus;
   out << "lungime Ox = " << p.latura << endl << "latura = " << p.latura2 << endl;

   if (p.valid == 1)
    out << "Aria = " << p.arie() << endl << "Perimetru = " << p.perimetru() << endl;

   else
     out << "Figura nu este valida" << endl;

   return out;
}

float Paralelogram::arie() const
{
    if (valid == 0)
        return -1;

    /* Aflam coordonatele celorlalte 2 puncte din paralelogram */
    const Punct stSus(coltOpus.getX() - latura, coltOpus.getY());
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());

    /* Aflam coordonatele capatului inaltimii duse din stanga sus in stanga jos */
    const Punct hPct(stSus.getX(), stangaJos.getY());

    /* Aflam lungimea inaltimii */
    float height = distanta(stSus, hPct);

    /* Aria = (b * h) / 2 */
    return (latura * height) / 2;
}

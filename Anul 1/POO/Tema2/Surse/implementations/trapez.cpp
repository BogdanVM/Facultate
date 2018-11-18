#include <bits/stdc++.h>
#include "../shapes.h"
using namespace std;

      /* Constructori de initializare */
Trapez::Trapez() {}
Trapez::Trapez(const Punct& psj, const Punct& pco, float l1, float l2, float b)
                    : Paralelogram(psj, pco, l1, l2), baza2(b)
{
    valid = isShapeValid() ? 1 : 0;
}

      /* Constructor de copiere si destructor */
Trapez::Trapez(const Trapez& t) : Paralelogram(t.stangaJos, t.coltOpus, t.latura, t.latura2), baza2(t.baza2)
{
    valid = isShapeValid() ? 1 : 0;
}
Trapez::~Trapez() {}

      /* Metoda de verificare a validitatii figurii */
bool Trapez::isShapeValid() const
{
    const Punct stSus(coltOpus.getX() - baza2, coltOpus.getY()); // Aflam punctul din stanga sus
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY()); // Aflam punctul din dreapta jos

    /* Aflam latura care uneste punctele din stanga jos si stanga sus si o comparam cu cea furnizata de obiect */
    float side = distanta(stSus, stangaJos);
    if (side != latura2)
        return false;

    return true;
}

istream& operator >> (istream& in, Trapez& t)
{
    cout << "INTRODUCETI TRAPEZUL: \nColtul din stanga jos: ";
    in >> t.stangaJos;

    cout << "Coltul din dreapta sus: ";
    in >> t.coltOpus;

    cout << "Baza de jos = ";
    in >> t.latura;

    cout << "Baza de sus = ";
    in >> t.baza2;

    cout << "latura = ";
    in >> t.latura2;

    if (t.latura <= 0 || t.latura2 <= 0){
        t.valid = 0;
        return in;
    }
    if (t.stangaJos.getX() >= t.coltOpus.getX() || t.stangaJos.getY() >= t.coltOpus.getY()){
        t.valid = 0;
        return in;
    }
    t.valid = t.isShapeValid() ? 1 : 0;
    return in;
}

ostream& operator << (ostream& out, const Trapez& t)
{
    out << endl << "TRAPEZ: \nColtul din stanga jos: " << t.stangaJos;
    out << "Coltul din dreapta sus: " << t.coltOpus;
    out << "baza de sus = " << t.baza2 << endl << "baza de jos = " << t.latura;
    out << endl << "latura = " << t.latura2 << endl;

    if (t.valid == 1)
      out << "Aria = " << t.arie() << endl << "Perimetru = " << t.perimetru() << endl;

    else
       out << "Figura nu este valida" << endl;

    return out;
}

float Trapez::perimetru() const
{
    if (valid == 0)
        return -1;

    /* Aflam coordonatele celorlalte 2 puncte din trapez */
    const Punct stSus(coltOpus.getX() - baza2, coltOpus.getY());
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());

    /* Aflam cea de-a 4-a latura a trapezului */
    float lastSide = distanta(drJos, coltOpus);

    return latura + latura2 + baza2 + lastSide;
}

float Trapez::arie() const
{
    if (valid == 0)
        return -1;

    /* Aflam coordonatele celorlalte 2 puncte din trapez */
    const Punct stSus(coltOpus.getX() - baza2, coltOpus.getY());
    const Punct drJos(stangaJos.getX() + latura, stangaJos.getY());

    /* Aflam coordonata inaltimii trasate din stanga sus pe baza de jos */
    const Punct hPct(stSus.getX(), stangaJos.getY());

    /* Aflam lungimea inaltimii */
    float height = distanta(stSus, hPct);

    /* arie = ( (b1 + b2) * h) / 2 */
    return ( (baza2 + latura) * height) / 2;
}

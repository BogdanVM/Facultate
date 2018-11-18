#include "../shapes.h"
#include <bits/stdc++.h>
using namespace std;

   /* Constructori de initializare */
Dreptunghi::Dreptunghi() { valid = 0; }
Dreptunghi::Dreptunghi(float l2) : latura2(l2) { valid = 1; }
Dreptunghi::Dreptunghi(const Punct& point, float l1, float l2) : Patrat(point, l1), latura2(l2)
{
   if (latura < latura2)
    valid = 0;
   else
    valid = 1;
}

    /* Constructorul de copiere */
Dreptunghi::Dreptunghi(const Dreptunghi& rect) : Patrat(rect.stangaJos, rect.latura), latura2(rect.latura2)
{ valid = rect.valid;}

    /* Destructorul */
Dreptunghi::~Dreptunghi() {}

    /*  Operatorii =, <<, >> */
const Dreptunghi& Dreptunghi::operator=(const Dreptunghi& rect){
  if (this != &rect){
    stangaJos = rect.stangaJos;
    latura = rect.latura;
    latura2 = rect.latura2;
    valid = rect.valid;
  }

  return *this;
}

istream& operator>>(istream& in, Dreptunghi& rect){
  cout << endl << "INTRODUCETI DREPTUNGHIUL: \nColtul din stanga jos: ";
  in >> rect.stangaJos;

  cout << "Lungimea dreptunghiului: ";
  in >> rect.latura;

  cout << "Latimea dreptunghiului: ";
  in >> rect.latura2;
  cout << endl;

  if (rect.latura < rect.latura2)
    rect.valid = 0;
  else
    rect.valid = 1;

  return in;
}

ostream& operator<<(ostream& out, const Dreptunghi& rect){
  out << "DREPTUNGHI: \nColtul din stanga jos: " << rect.stangaJos;
  out << " lungimea = " << rect.latura << endl << "latimea = " << rect.latura2 << endl;

  if (rect.valid == 1)
    out << "Aria = " << rect.arie() << endl << "Perimetru = " << rect.perimetru() << endl;

  else
     out << "Figura nu este valida" << endl;
  return out;
}

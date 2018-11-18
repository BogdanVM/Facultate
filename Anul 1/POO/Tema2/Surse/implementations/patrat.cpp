#include <iostream>
#include "../shapes.h"

using namespace std;

Patrat::Patrat() : stangaJos(0, 0), latura(0), valid(0) { nrObiecte++; }

Patrat::Patrat(const Punct& bottomLeft, float length): stangaJos(bottomLeft), latura(length), valid(1) {nrObiecte++;}

Patrat::Patrat(float bottomX, float bottomY, float length): stangaJos(bottomX, bottomY), latura(length), valid(1) {nrObiecte++;}

Patrat::Patrat(const Patrat& square): stangaJos(square.stangaJos), latura(square.latura), valid(1) {nrObiecte++;}

Patrat::~Patrat() {nrObiecte--;}

const Patrat& Patrat::operator=(const Patrat& square){
  if (this != &square){
    stangaJos = square.stangaJos;
    latura = square.latura;
    valid = square.valid;
  }
  return *this;
}

istream& operator>>(istream& in, Patrat& square){
  cout << endl << "INTRODUCETI PATRATUL: \nColtul din stanga jos: ";
  in >> square.stangaJos;
  float x;
  bool ok = true;

  do{
    ok = true;
    try
    {
      cout << "Lungimea laturii = ";
      in >> x;

      if (x <= 0)
        throw x;
    }
    catch (float e)
    {
        ok = false;
        cout << endl << "Numarul " << e << " nu este valid. Latura patratului trebuie sa fie un numar STRICT POZITIV ( > 0 )" << endl << endl;
    }
  }while (!ok);

  square.latura = x;
  square.valid = 1;
  return in;
}

ostream& operator<<(ostream& out, const Patrat& square){
  out << endl << "PATRAT: \nColtul din stanga jos: " << square.stangaJos << "latura = " << square.latura << endl;

  if (square.valid == 1)
    out << "Aria = " << square.arie() << endl << "Perimetru = " << square.perimetru() << endl;

  else
     out << "Figura nu este valida" << endl;

  return out;
}

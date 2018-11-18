#include <iostream>
#include "../shapes.h"

using namespace std;

Punct::Punct(float x, float y)
{
    this->x = x;
    this->y = y;
}

Punct::Punct(const Punct& point)
{
    this->x = point.x;
    this->y = point.y;
}

Punct::~Punct() {}

const Punct& Punct::operator=(const Punct& point)
{
    if (this != &point)
    {
        this->x = point.x;
        this->y = point.y;
    }

    return *this;
}

istream& operator>>(istream& in, Punct& point)
{
    cout << endl << "x = ";
    in >> point.x;

    cout << "y = ";
    in >> point.y;

    return in;
}

ostream& operator<<(ostream& out, const Punct& point)
{
    out << "x = " << point.x  << ", y = " << point.y << endl;
    return out;
}

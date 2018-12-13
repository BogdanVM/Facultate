#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Punct
{
    double x, y;
};

int Test_Orientare(Punct a, Punct b, Punct c)
{
    double val = ( b.y - a.y ) * ( c.x - b.x ) - ( b.x - a.x ) * ( c.y - b.y );
    if(val == 0)
        return 0; // coliniar
    if(val > 0)
        return 1; // dreapta
    return 2; // stanga
}

Punct Maxim_Y(Punct a, Punct b)
{
    if(fabs(a.y) > fabs(b.y))
        return a;
    if(fabs(a.y) < fabs(b.y))
        return b;
    if(fabs(a.x) > fabs(b.x))
        return a;
    if(fabs(a.x) < fabs(b.x))
        return b;
}
int main()
{
    int numar, i, j;

    ifstream f("fis.in");
    ofstream g("fis.out");
    vector<Punct> puncte;
    f >> numar;
    for( i = 0 ; i < numar ; i++ )
    {
        Punct p;
        f >> p.x >> p.y;
        puncte.push_back(p);
    }
    f.close();

    vector<Punct> acoperire_convexa;

    acoperire_convexa.push_back(puncte[0]);
    acoperire_convexa.push_back(puncte[1]);
    int k, m;
    for( i = 2 ; i < numar ; i++ )
    {
        m = acoperire_convexa.size();
        k =  Test_Orientare(acoperire_convexa[m-2], acoperire_convexa[m-1], puncte[i]);
        if( k == 2)
        {
            acoperire_convexa.push_back(puncte[i]);
            continue;
        }
        else if( k == 1)
        {
            acoperire_convexa[m-1] = puncte[i];
        }
        else if( k == 0)
        {
            acoperire_convexa[m-1] = Maxim_Y(acoperire_convexa[m-1], puncte[i]);

        }
    }
    m = acoperire_convexa.size();
    k =  Test_Orientare(acoperire_convexa[m-1], acoperire_convexa[0], acoperire_convexa[1]);
    if( k == 1 || k == 0)
            {
                acoperire_convexa.erase(acoperire_convexa.begin());
            }
    g << numar << endl << endl;
    for(i = 0 ; i < numar ; i++)
        g << puncte[i].x << " " << puncte[i].y << endl ;
    g << endl;
    for(i = 0 ; i < acoperire_convexa.size() ; i++)
    {
        g << acoperire_convexa[i].x << " " << acoperire_convexa[i].y << endl;
    }
    g.close();
    return 0;
}

//
// Created by Bogdan on 5/3/2018.
//

#ifndef TEMA3_PLATA_H
#define TEMA3_PLATA_H

#include <bits/stdc++.h>

class Plata {

protected:
    std::string date;
    double sum;

    /*  Private utility methods  */

public:
    /*  Constructors and destructor   */
    Plata() {}
    Plata(const std::string& _date, double _sum) : date(_date), sum(_sum) {}
    Plata(const std::string& _date) : date(_date), sum(0) {}
    Plata(const Plata& p) : date(p.date), sum(p.sum) {}
    virtual ~Plata() {}

    /*   Getters and setters  */
    std::string getDate() const { return date; }
    double getSum() const { return sum; }
    void setDate(const std::string& _date) { date = _date; }
    void setSum(double _sum) { sum = _sum; }

    /*   Utility methods  */
    virtual void display(std::ostream&) const;

    /*   Operator overloads  */
    friend std::istream& operator >> (std::istream&, Plata&);
    friend std::ostream& operator << (std::ostream&, const Plata&);
    const Plata& operator = (const Plata&);
};

#endif //TEMA3_PLATA_H

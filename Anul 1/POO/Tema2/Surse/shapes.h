#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class Punct
{
    float x;
    float y;

 public:
     Punct(float = 0, float = 0);
     Punct(const Punct&);
     ~Punct();

     const Punct& operator=(const Punct&);
     friend istream& operator>>(istream&, Punct&);
     friend ostream& operator<<(ostream&, const Punct&);

     inline float getX() const { return x; }
     inline float getY() const { return y; }
     inline void setX(float x) { this->x = x; }
     inline void setY(float y) { this->y = y; }
};

class Patrat
{
 protected:
    Punct stangaJos;
    float latura;
    int valid;
    virtual bool isShapeValid() const { return true; }
    static int nrObiecte;

 public:
    Patrat();
    Patrat(const Punct&, float);
    Patrat(float, float, float);
    Patrat(const Patrat&);
    virtual ~Patrat();

    const Patrat& operator=(const Patrat&);
    friend istream& operator>>(istream&, Patrat&);
    friend ostream& operator<<(ostream&, const Patrat&);

    virtual float arie() const { if (valid == 0) return -1;
                           return latura * latura; }

    virtual float perimetru() const { if (valid == 0) return -1;
                                return 4 * latura; }

    float distanta(const Punct& p1, const Punct& p2) const {
        return sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    }

    static int getNrObiecte() { return nrObiecte; }
};

class Dreptunghi : public virtual Patrat
{
  protected:
      float latura2;

  public:
    Dreptunghi();
    Dreptunghi(float);
    Dreptunghi(const Punct&, float, float);
    Dreptunghi(const Dreptunghi&);
    virtual ~Dreptunghi();

    const Dreptunghi& operator=(const Dreptunghi&);
    friend istream& operator>>(istream&, Dreptunghi&);
    friend ostream& operator<<(ostream&, const Dreptunghi&);

    virtual float arie() const { if (valid == 0) return -1;
                           return latura2 * latura; }

    virtual float perimetru() const { if (valid == 0) return -1;
                                return 2 * latura + 2 * latura2; }
};

class Romb : public virtual Patrat
{
   protected:
     Punct coltOpus;
     bool isShapeValid() const;

   public:
     Romb();
     Romb(const Punct&);
     Romb(const Punct&, const Punct&, float);
     Romb(const Romb&);
     virtual ~Romb();

     const Romb& operator = (const Romb&);
     friend istream& operator >> (istream&, Romb&);
     friend ostream& operator << (ostream&, const Romb&);

     virtual float arie() const;
};

class Paralelogram : public Dreptunghi, public Romb
{
   protected:
       bool isShapeValid() const;
   public:
     Paralelogram();
     Paralelogram(const Punct&, const Punct&, float, float);
     Paralelogram(const Paralelogram&);
     virtual ~Paralelogram() {}

     const Paralelogram& operator = (const Paralelogram&);
     friend istream& operator >> (istream&, Paralelogram&);
     friend ostream& operator << (ostream&, const Paralelogram&);

     virtual float arie() const;
     virtual float perimetru() const { return Dreptunghi::perimetru(); }
};

class Trapez : public Paralelogram
{
    protected:
        float baza2;
        bool isShapeValid() const;

    public:
        Trapez();
        Trapez(const Punct&, const Punct&, float, float, float);
        Trapez(const Trapez&);
        ~Trapez();

        const Trapez& operator = (const Trapez&);
        friend istream& operator >> (istream&, Trapez&);
        friend ostream& operator << (ostream&, const Trapez&);

        float perimetru() const;
        float arie() const;
};

#endif // SHAPES_H_INCLUDED

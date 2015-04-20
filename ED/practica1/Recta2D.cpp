#include "Recta2D.hpp"

using namespace ed;

Recta2D::Recta2D(double _a, double _b, double _c)
{
  setA(_a);
  setB(_b);
  setC(_c);
}

Recta2D::Recta2D(const Punto2D &p, const Punto2D &q)
{
//  #ifndef NDEBUG
//  assert(p.sonIguales(q));
//  #endif

  _a=(q.getCoordenadaY())-(p.getCoordenadaY());
  _b=(p.getCoordenadaX())-(q.getCoordenadaX());
  _c=(((-p.getCoordenadaX())*(q.getCoordenadaY()))+((p.getCoordenadaY())*(q.getCoordenadaX())));

}

float Recta2D::distancia(const Punto2D &p)
{
  float distancia;

  distancia=(((_a)*(p.getCoordenadaX()))+((_b)*(p.getCoordenadaY()))+_c)/(sqrt((_a*_a)+(_b*_b)));

  return abs(distancia);
}

void Recta2D::setA(double a)
{
  _a=a;
}

void Recta2D::setB(double b)
{
  _b=b;
}

void Recta2D::setC(double c)
{
  _c=c;
}

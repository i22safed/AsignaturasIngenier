/**
*@brief Clase Recta que usaremos para trabajar con rectas, y distancia, para calcular el error
@param _a
@param _b
@param _c
*/
#ifndef RECTA2D_HPP
#define RECTA2D_HPP

#include <iostream>
#include "Punto2D.hpp"

using namespace std;

namespace ed
{
  class Recta2D
  {
    private:

      double _a;
      double _b;
      double _c;

    public:

      Recta2D(double _a, double _b, double _c);
      Recta2D(const Punto2D &p, const Punto2D &q);

      double getA()const{return _a;};
      double getB()const{return _b;};
      double getC()const{return _c;};

      float distancia(const Punto2D &p);

      void setA(double a);
      void setB(double b);
      void setC(double c);
  };
}

#endif

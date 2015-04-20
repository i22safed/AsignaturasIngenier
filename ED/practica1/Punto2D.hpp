/**
*@brief Clase Punto que usaremos para trabajar con rectas, y listar los puntos de contorno y aproximacion, para calcular el error
@param _coordenadaX como primera coordenada
@param _coordenadaY como segunda coordenada
*/

#ifndef PUNTOS2D_HPP
#define PUNTOS2D_HPP

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

namespace ed
{
  class Punto2D
  {
    private:

      double _coordenadaX;
      double _coordenadaY;

    public:

      Punto2D(double coordenadaX, double coordenadaY)
      {
        _coordenadaX=coordenadaX;
        _coordenadaY=coordenadaY;
      }

      Punto2D(Punto2D const &p)
      {
        _coordenadaX=p._coordenadaX;
        _coordenadaY=p._coordenadaY;
      };

      double getCoordenadaX() const{return _coordenadaX;};
      double getCoordenadaY() const{return _coordenadaY;};

      void setCoordenadaX(double coordenadaX){_coordenadaX=coordenadaX;};
      void setCoordenadaY(double coordenadaY){_coordenadaY=coordenadaY;};

      bool sonIguales(const Punto2D &punto);
  };
}

#endif

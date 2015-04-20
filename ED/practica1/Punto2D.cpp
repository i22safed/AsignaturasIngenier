#include "Punto2D.hpp"

using namespace ed;

bool Punto2D::sonIguales(const Punto2D &punto)
{
  if((punto._coordenadaX==getCoordenadaX())and(punto._coordenadaY==getCoordenadaY()))
  {
    return true;
  }
  else
    return false;
}


  #include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include "Punto2D.hpp"
#include "Recta2D.hpp"

using namespace std;

namespace ed
{
  void cargarContorno(vector<Punto2D>&contorno, string ficheroContorno);
  void cargarAproximacionPoligonal(vector<int>&aproximacion, string                     ficheroAproximacionPoligonal);

  double calcularError(const vector<Punto2D>&contorno, const vector<int>&aproximacionPoligonal);


  void cargarContorno(vector<Punto2D>&contorno, string ficheroContorno)
  {
    double coordenadaX;
    double coordenadaY;

    ifstream fichero;

    fichero.open(ficheroContorno.c_str());

    if(!fichero)
    {
      cout <<"El fichero no se pudo abrir"<<"\n";
      }

      while(fichero >> coordenadaX >> coordenadaY)
      {
        Punto2D aux(coordenadaX, coordenadaY);

        contorno.push_back(aux);
      }

      fichero.close();
    }

    void cargarAproximacionPoligonal(vector<int>&aproximacion, string ficheroAproximacionPoligonal)
    {
      double coordenadaX;

      ifstream fichero;
      fichero.open(ficheroAproximacionPoligonal.c_str());

      if(!fichero)
      {
        cout << "El fichero no se pudo abrir"<<"\n";
      }

      while(fichero >> coordenadaX)
      {
        aproximacion.push_back(coordenadaX);
      }

      aproximacion.pop_back();

      fichero.close();
    }

    double calcularError(const vector<Punto2D>&contorno, const vector<int>&aproximacionPoligonal)
    {
      double error=0;

      for(int i=0; i<aproximacionPoligonal.size()-1; i++)
      {
        Punto2D principio=contorno[aproximacionPoligonal[i]];

        Punto2D final=contorno[aproximacionPoligonal[i+1]];

        Recta2D recta=Recta2D(principio, final);

        if(aproximacionPoligonal[i]<aproximacionPoligonal[i+1])
        {
          for(int j=aproximacionPoligonal[i]+1; j<aproximacionPoligonal[i+1]; j++)
          {
            error+=pow(recta.distancia(contorno[j]),2);
          }
        }
        else
        {
          for(int k=aproximacionPoligonal[i]; k<aproximacionPoligonal[contorno.size()-1]; k++)
          {
            error+=pow(recta.distancia(contorno[k]), 2);
          }
          for(int l=0; l<aproximacionPoligonal[i]; l++)
          {
            error+=pow(recta.distancia(contorno[l]), 2);
          }
        }
      }

      return error;
    }
}

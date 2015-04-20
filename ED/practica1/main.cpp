/**
*@brief Rellenamos los vectores con los puntos de los respectivos ficheros

*/

#include "main.hpp"

using namespace ed;
int main()
{
  double error=0;

  vector<Punto2D>contornoReal;
  vector<int>aproximacionPuntos;

  string ficheroContorno="abrelatas.txt", aproximacionPoligonal="aproximacion.txt";

  cout << "Cargamos ficheros de puntos" << "\n";

  cargarContorno(contornoReal, ficheroContorno);
  cargarAproximacionPoligonal(aproximacionPuntos, aproximacionPoligonal);

  cout <<  "Cargados los fichero con el contorno y su aproximacion veremos el error producido" << "\n";

  error=calcularError(contornoReal, aproximacionPuntos);


  cout << "El error es :"<< error << "\n";

  return 0;
}

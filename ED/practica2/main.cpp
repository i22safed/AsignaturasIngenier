#include "asignaturas.hpp"
using namespace std;
using namespace edi;

int main ()
{
	int opcion;

  ListaOrdenadaDoblementeEnlazada<Persona> asignatura;

  do{

    opcion=opciones();

    switch(opcion)
		{
			case 1:

          crearAsignatura(asignatura);

          break;

			case 2:

          mostrarOrdenAscendete(asignatura);

          break;

      case 3:

          mostrarOrdenDescendente(asignatura);

          break;

      case 4:

          comprendidosAscendente(asignatura);

          break;

      case 5:

          comprendidosDescendente(asignatura);

          break;

      case 6:

          modificar(asignatura);

          break;
		}

	}
	while(opcion!=0);


}

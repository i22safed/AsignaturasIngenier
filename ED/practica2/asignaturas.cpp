#include "asignaturas.hpp"
#include <iostream>
#include <cstring>

using namespace std;

using namespace edi;

void crearAsignatura(ListaOrdenadaDoblementeEnlazada <Persona> &lista)
{
	int numeroPersonas;

	vector<Persona> listaPersona;

	cout<<"Introduzca el numero de personas: ";
	cin>>numeroPersonas;

	string fichero="personas.txt";
 	char f1[15];
 	strcpy(f1,fichero.c_str());

	listaPersona=generarPersonas(f1, numeroPersonas);
	vector<Persona>::iterator it;

	for (it = listaPersona.begin(); it < listaPersona.end(); it++)
	{
		lista.inserta(*it);
	}

}

void mostrarOrdenAscendete(const ListaOrdenadaDoblementeEnlazada<Persona> &lista )
{
	Persona alumno;

	for (int i = 0; i < lista.getNumeroElementos(); i++)
	{
		alumno=lista.dato(i);

		cout<<alumno<<endl;
	}

}

void mostrarOrdenDescendente(const ListaOrdenadaDoblementeEnlazada<Persona> &lista )
{
	Persona alumno;

	for (int i = lista.getNumeroElementos()-1; i >=0 ; i--)
	{
		alumno=lista.dato(i);

		cout<<alumno<<endl;
	}
}

void comprendidosAscendente(const ListaOrdenadaDoblementeEnlazada<Persona> &lista )
{
	Persona alumno;
	Persona alumno1;
	Persona alumno2;
	Persona auxiliar;

	int posicion1;
	int posicion2;

	cout<<"Introduzca el primer alumno: ";
	cin>>alumno1;

	cout<<"Introduce el segundo alumno: ";
	cin>>alumno2;

	if(alumno1 == alumno2)
	{
		cout<<"Ha introducido dos alumnos iguales"<<endl;

		comprendidosAscendente(lista);
	}
	else
		if(alumno1 > alumno2)
		{
			auxiliar=alumno2;

			alumno2=alumno1;
			alumno1=auxiliar;
		}

	posicion1=lista.buscaDato(alumno1,0);
	posicion2=lista.buscaDato(alumno2,posicion1);


	for (int i = posicion1; i <= posicion2 ; i++)
	{
		alumno=lista.dato(i);

		cout<<alumno<<endl;
	}

}

void comprendidosDescendente(const ListaOrdenadaDoblementeEnlazada<Persona> &lista )
{
	Persona alumno;
	Persona alumno1;
	Persona alumno2;
	Persona auxiliar;

	int posicion1;
	int posicion2;

	cout<<"Introduce la 1 persona: ";
	cin>>alumno1;

	cout<<"Introduce la 2 persona: ";
	cin>>alumno2;

	if(alumno1==alumno2)
	{
		cout<<"Ha introducido dos personas iguales"<<endl;
		cout<<"Por favor, Introduzca dos personas distintas"<<endl;

		comprendidosAscendente(lista);
	}
	else
		if(alumno1 > alumno2)
		{
			auxiliar=alumno2;
			alumno2=alumno1;
			alumno1=auxiliar;
		}

	posicion1=lista.buscaDato(alumno1,0);
	posicion2=lista.buscaDato(alumno2,posicion1);


	for (int i = posicion2; i >= posicion1 ; i--)
	{
		alumno=lista.dato(i);

		cout<<alumno<<endl;
	}

}

void modificar(ListaOrdenadaDoblementeEnlazada<Persona> &lista)
{
	Persona alumno;
	Persona auxiliar;

	int posicion;

	cout<<"Introduce el alumno a modificar ";
	cin >> alumno;

	cout<<"Nuevos datos"<<endl;
	cin >> auxiliar;

	posicion=lista.buscaDato(alumno,0);
	lista.borrarPosicion(posicion);
	lista.inserta(auxiliar);

}

int opciones ()
{

	int opcion;

	do {
			cout<<"Seleccione una opcion:"<<endl;
			cout<<"1 Añadir nueva asignatura."<<endl;
			cout<<"2 Ver lista de los alumnos ordenados de forma ascendente."<<endl;
			cout<<"3 Ver lista de los alumnos ordenados de forma descendente."<<endl;
			cout<<"4 Añadir dos nuevos alumnos y ver ordenados de forma ascendente los alumnos comprendidos entre ellos."<<endl;
			cout<<"5 Añadir dos nuevos alumnos y ver ordenados de forma descendente los alumnos comprendidos entre ellos."<<endl;
			cout<<"6 Cambiar datos de alumno."<<endl;
			cout<<"0 Salir."<<endl;
			cout<<"Seleccione una opcion: "<<endl;
			cin>> opcion;

	}
	while((opcion<0) || (opcion>6));

	return opcion;
}

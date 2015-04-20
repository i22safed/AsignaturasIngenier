#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Apuesta
{
	int tipo;
	string valor;
	int cantidad;

};

class Jugador:public Persona
{
	private:

		list <Apuesta> apuestas_;

		int dinero_;

		string codigo_;

	public:

		Jugador(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="", int dinero=1000);

		Jugador(const Jugador &j);

		void setDinero(int cash);
		void setCodigo(string code);
		void setApuestas();

		int getDinero();
		string getCodigo();
		list <Apuesta> getApuestas();
};

#endif

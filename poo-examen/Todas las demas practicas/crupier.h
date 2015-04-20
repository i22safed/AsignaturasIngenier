#ifndef CRUPIER_H
#define CRUPIER_H
#include "persona.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Crupier:public Persona
{
	private:

		string codigo_;

	public:

		Crupier(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		Crupier(const Crupier &p);

		void setCodigo(string code);

		string getCodigo();


};

#endif

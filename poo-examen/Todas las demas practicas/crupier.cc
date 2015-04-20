#include "crupier.h"

Crupier::Crupier(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais)
{
	setCodigo(codigo);
}

Crupier::Crupier(const Crupier &p):Persona(p)
{
	setCodigo(p.codigo_);
}

void Crupier::setCodigo(string code)
{
	codigo_=code;
}

string Crupier::getCodigo()
{
	return codigo_;
}

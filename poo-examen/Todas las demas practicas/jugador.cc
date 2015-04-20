#include "jugador.h"

Jugador::Jugador(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais, int dinero):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais)
{
	setCodigo(codigo);
	setDinero(dinero);
}

Jugador::Jugador(const Jugador &j):Persona(j)
{
	setCodigo(j.codigo_);
	setDinero(j.dinero_);
}

void Jugador::setDinero(int cash)
{
	dinero_=cash;
}

void Jugador::setCodigo(string code)
{
	codigo_=code;
}

int Jugador::getDinero()
{
	return dinero_;
}

string Jugador::getCodigo()
{
	return codigo_;
}

void Jugador::setApuestas()
{
	apuestas_.clear();

	ifstream fichero((getDNI()+".txt").c_str());

	string tipo;
	string valor;
	string cantidad;

	Apuesta auxiliar;

	while(getline(fichero,tipo,','))
	{
		getline(fichero, valor, ',');
		getline(fichero,cantidad, '\n');

		auxiliar.tipo=atoi(tipo.c_str());
		auxiliar.valor=valor;
		auxiliar.cantidad=atoi(cantidad.c_str());

		apuestas_.push_back(auxiliar);
	}

	fichero.close();
}

list <Apuesta> Jugador::getApuestas()
{
	return apuestas_;
}

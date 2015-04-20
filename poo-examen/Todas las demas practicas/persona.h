#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>

using namespace std;

class Persona
{
	private:

		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;

	public:

		Persona(string DNI,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		Persona(const Persona &p);

		void setDNI(string num);
		void setNombre(string name);
		void setApellidos(string names);
		void setDireccion(string adress);
		void setLocalidad(string town);
		void setProvincia(string city);
		void setPais(string country);

		string getDNI();
		string getNombre();
		string getApellidos();
		string getDireccion();
		string getLocalidad();
		string getProvincia();
		string getPais();
		string getApellidosyNombre();

};


#endif

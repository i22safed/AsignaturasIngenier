#include "persona.h"

using namespace std;

	Persona::Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais)
	{
		setDNI(DNI);
		setNombre(nombre);
		setApellidos(apellidos);
		setDireccion(direccion);
		setLocalidad(localidad);
		setProvincia(provincia);
		setPais(pais);

	}



	Persona::Persona(const Persona &p)
	{
		setDNI(p.DNI_);
		setNombre(p.nombre_);
		setApellidos(p.apellidos_);
		setDireccion(p.direccion_);
		setLocalidad(p.localidad_);
		setProvincia(p.provincia_);
		setPais(p.pais_);
	}

	void Persona::setDNI(string num)
	{
		DNI_=num;
	}

	void Persona::setNombre(string name)
	{
		nombre_=name;
	}

	void Persona::setApellidos(string names)
	{
		apellidos_=names;
	}

	void Persona::setDireccion(string adress)
	{
		direccion_=adress;
	}

	void Persona::setLocalidad(string town)
	{
		localidad_=town;
	}

	void Persona::setProvincia(string city)
	{
		provincia_=city;
	}

	void Persona::setPais(string country)
	{
		pais_=country;
	}

	string Persona::getDNI()
	{
		return DNI_;
	}
	string Persona::getNombre()
	{
		return nombre_;
	}

	string Persona::getApellidos()
	{
		return apellidos_;
	}

	string Persona::getDireccion()
	{
		return direccion_;
	}

	string Persona::getLocalidad()
	{
		return localidad_;
	}

	string Persona::getProvincia()
	{
		return provincia_;
	}

	string Persona::getPais()
	{
		return pais_;
	}

	string Persona::getApellidosyNombre()
	{
		string cadena;

		cadena=apellidos_+", "+nombre_;

		return cadena;
	}

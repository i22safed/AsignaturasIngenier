/*
 * Cliente.h
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <string>
#include <iostream>

using namespace std;
class Cliente {
private:							//twitter y facebook los utilizamos asi o como struct?
	string DNI, nombre, apellido1, apellido2,numero,fijo, direccion, anotaciones,twitter, facebook;
	int favorito;
public:
	Cliente();
	virtual ~Cliente();
	const string& getAnotaciones() const;
	void setAnotaciones(const string& anotaciones);
	const string& getApellido1() const;
	void setApellido1(const string& apellido1);
	const string& getApellido2() const;
	void setApellido2(const string& apellido2);
	const string& getDireccion() const;
	void setDireccion(const string& direccion);
	const string& getDni() const;
	void setDni(const string& dni);
	const string& getFacebook() const;
	void setFacebook(const string& facebook);
	int getFavorito() const;
	void setFavorito(int favorito);
	const string& getFijo() const;
	void setFijo(const string& fijo);
	const string& getNombre() const;
	void setNombre(const string& nombre);
	const string& getNumero() const;
	void setNumero(const string& numero);
	const string& getTwitter() const;
	void setTwitter(const string& twitter);
};

#endif /* CLIENTE_H_ */

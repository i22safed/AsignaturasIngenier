/*
 * Cliente.cpp
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#include "Cliente.h"

Cliente::Cliente() {
	// TODO Auto-generated constructor stub
	  DNI="";
	  nombre="";
	  apellido1="";
	  apellido2="";
	  direccion="";
	  anotaciones="";
	  favorito=0;

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

const string& Cliente::getAnotaciones() const {
	return anotaciones;
}

void Cliente::setAnotaciones(const string& anotaciones) {
	this->anotaciones = anotaciones;
}

const string& Cliente::getApellido1() const {
	return apellido1;
}

void Cliente::setApellido1(const string& apellido1) {
	this->apellido1 = apellido1;
}

const string& Cliente::getApellido2() const {
	return apellido2;
}

void Cliente::setApellido2(const string& apellido2) {
	this->apellido2 = apellido2;
}

const string& Cliente::getDireccion() const {
	return direccion;
}

void Cliente::setDireccion(const string& direccion) {
	this->direccion = direccion;
}

const string& Cliente::getDni() const {
	return DNI;
}

void Cliente::setDni(const string& dni) {
	DNI = dni;
}

const string& Cliente::getFacebook() const {
	return facebook;
}

void Cliente::setFacebook(const string& facebook) {
	this->facebook = facebook;
}

int Cliente::getFavorito() const {
	return favorito;				//será 1 si es favorito y 0 si no lo es
}

void Cliente::setFavorito(int favorito) {
	this->favorito = favorito;
}

const string& Cliente::getFijo() const {
	return fijo;
}

void Cliente::setFijo(const string& fijo) {
	this->fijo = fijo;
}

const string& Cliente::getNombre() const {
	return nombre;
}

void Cliente::setNombre(const string& nombre) {
	this->nombre = nombre;
}

const string& Cliente::getNumero() const {
	return numero;
}

void Cliente::setNumero(const string& numero) {
	this->numero = numero;
}

const string& Cliente::getTwitter() const {
	return twitter;
}

void Cliente::setTwitter(const string& twitter) {
	this->twitter = twitter;
}

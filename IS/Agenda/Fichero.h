/*
 * Fichero.h
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */
#include <iostream>
#include <fstream>
#include <list>
#include "Cliente.h"
#include "Agenda.h"
#ifndef FICHERO_H_
#define FICHERO_H_
using namespace std;
class Fichero {
private:
	fstream f;
public:
	Fichero();
	virtual ~Fichero();
	void guardar_agenda(list<Cliente> agenda);		//estos metodos son virtuales??
	void cargar_agenda();
};

#endif /* FICHERO_H_ */

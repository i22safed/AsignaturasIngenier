/*
 * GestorFicheros.h
 *
 *  Created on: 8/1/2015
 *      Author: jose
 */
#include <iostream>
#include <list>
#include "Cliente.h"
#ifndef GESTORFICHEROS_H_
#define GESTORFICHEROS_H_

class  GestorFicheros {
public:
	GestorFicheros(){};
	virtual ~GestorFicheros(){};
	virtual  void guardar_agenda(list<Cliente> agenda, string nombre){};
	virtual	void cargar_agenda(){};

};

#endif /* GESTORFICHEROS_H_ */

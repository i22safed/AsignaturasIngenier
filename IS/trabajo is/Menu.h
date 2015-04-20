/*
 * Menu.h
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include "Agenda.h"
#include "Cliente.h"
class Menu {
public:
	Menu();
	virtual ~Menu();
	void visualizar_agenda(list<Cliente> agenda);
	void visualizar_cliente(Cliente c);
};

#endif /* MENU_H_ */

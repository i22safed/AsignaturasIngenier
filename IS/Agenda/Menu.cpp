/*
 * Menu.cpp
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#include "Menu.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::visualizar_agenda(list<Cliente> agenda) {	//que mostramos? apellidos y numero de telefono?
	list<Cliente>::iterator it;
	for(it=agenda.begin();it!=agenda.end();it++){
		visualizar_cliente((*it));
	}
}

void Menu::visualizar_cliente(Cliente c) {

	 cout<<"\nNombre:\t"<<c.getNombre();
	 cout<<"\nApellidos:\t"<<c.getApellido1()<<" "<<c.getApellido2();
	 cout<<"\nDNI:\t"<<c.getDni();
	 cout<<"\nNumero:\t"<<c.getNumero();
	 cout<<"\nNumero fijo:\t"<<c.getFijo();
	 cout<<"\nDireccion:\t"<<c.getDireccion();
	 cout<<"\nAnotaciones:\t"<<c.getAnotaciones();
	 cout<<"\nTwitter:\t"<<c.getTwitter();
	 cout<<"\nFacebook:\t"<<c.getFacebook();
	 if(c.getFavorito()==1) cout<<"\n--------FAVORITO---------";
	 cout<<"\n\n\n\n\n";


}

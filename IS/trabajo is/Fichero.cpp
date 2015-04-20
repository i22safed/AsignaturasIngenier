/*
 * Fichero.cpp
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#include "Fichero.h"

Fichero::Fichero() {
	// TODO Auto-generated constructor stub

}

Fichero::~Fichero() {
	// TODO Auto-generated destructor stub
}

void Fichero::guardar_agenda(list<Cliente> agenda, string nombre) {
		fstream f(nombre.c_str(),ios::out|ios::trunc);
		//string nombreFichero="Contactos.txt";
		char fav='n';
		f.clear();
	    //f.open(nombreFichero.c_str());
	    list<Cliente>::iterator it= agenda.begin();
	    for(int i=0;i<agenda.size();i++,it++){
	    	if((*it).getFavorito()==1)
	    		fav='s';
	    	else fav='n';
	    	f<<(*it).getNombre()+","+(*it).getApellido1()+","+(*it).getApellido2()+","+(*it).getDni()+","+(*it).getNumero()+","+(*it).getFijo()+","+(*it).getDireccion()+","+(*it).getAnotaciones()+","+(*it).getTwitter()+","+(*it).getFacebook()+","+fav+"\n";

	    }
	    f.close();
}

void Fichero::cargar_agenda() {
}

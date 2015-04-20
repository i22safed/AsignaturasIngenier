/*
 * Agenda.cpp
 *
 *  Created on: 13/12/2014
 *      Author: jose
 */

#include "Agenda.h"
using namespace std;
Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

bool Agenda::esvacia() {
	return agenda.empty();
}

int Agenda::longitud() {
	return agenda.size();
}

bool Agenda::pertenece(Cliente &e) {
	bool encontrado=false;
	list<Cliente>::iterator it= agenda.begin();
	while(!encontrado && it!=agenda.end()){//hay que buscarlo tambien por el segundo apellido para que sea igual
			if((*it).getDni()==e.getDni() ){
				encontrado=true;
			}
			else it++;
		}
	return encontrado;
}

void Agenda::insertarCliente(list<Cliente>::iterator pos, Cliente& e) {
	//hay que distinguir entre si el cliente existe o no
	bool ok=false;
	if(esvacia()){
		agenda.push_back(e);
	}
	else if(pertenece(e))
	{
		//Si ya esta en la agenda le preguntamos si desea modificaro
	cout<<"\nEl cliente ya existe";

	}
	else{

		agenda.insert(pos,1,e);	//me da a mi que asi no es :S
	}
}

bool Agenda::eliminar(list<Cliente>::iterator it) {
	agenda.erase(it);
}

list<Cliente>::iterator Agenda::buscar(Cliente &e) {
	bool encontrado=false;
	list<Cliente>::iterator it= agenda.begin();
	while(!encontrado && it!=agenda.end()){//hay que buscarlo tambien por el segundo apellido para que sea igual
		if((*it).getApellido1()==e.getApellido1() && (*it).getApellido2()==e.getApellido2() || (*it).getDni()==e.getDni() ){
			encontrado=true;
		}
		else it++;
	}
return it;
}

bool Agenda::modificar(list<Cliente>::iterator i,Cliente aux) {

	*i=aux;
	//hay que machacarlo;
}

bool Agenda::ordenar() {		//si los vamos a insertar ordenados?? para que?
}

list<Cliente> Agenda::getFavoritos() {
	list<Cliente> aux;
	list<Cliente>::iterator it;
	for(it=agenda.begin();it!=agenda.end();it++){
		if((*it).getFavorito()==1)	aux.push_back((*it));			//ESTAN ORDENAOS COÑO
	}
	return aux;
}

void Agenda::guardar(list<Cliente> agenda,string nombre) {
	Fichero f;
	f.guardar_agenda(agenda,nombre);
}

list<Cliente> Agenda::getallApellido(string apellido) {
	list<Cliente> aux;
	list<Cliente>::iterator it;
	for(it=agenda.begin();it!=agenda.end();it++){
		if((*it).getApellido1()==apellido)	aux.push_back((*it));
	}
	return aux;
}

list<Cliente> Agenda::getClientes() {
	return agenda;
}

list<Cliente>::iterator Agenda::buscarpos(Cliente& e) {
	list<Cliente>::iterator it=agenda.begin();
	bool entrado=false;


	while((*it).getApellido1()<=e.getApellido1() && it!=agenda.end() && entrado==false)
		{

	        if((*it).getApellido1()==e.getApellido1() && !entrado)
	        {
	        	if ((*it).getApellido2()<e.getApellido2() && !entrado)
	        	{
	        		//it++;
	        		entrado=true;
	        		while((*it).getApellido2()<=e.getApellido2() && it!=agenda.end())
	        		{
	        			it++;
	        		}//si el primer apellido es igual hay que compararlo con el segundo
	        		entrado=true;
	        	}
	        	entrado=true;

	        }

	        else it++;
		}
	return it;
}

Cliente Agenda::getcliente(list<Cliente>::iterator it) {

	return *it;
}

void Agenda::cargar() {
	Fichero f;
	f.cargar_agenda();
}

/*
 * main.cpp
 *
 *  Created on: 15/12/2014
 *      Author: jose
 */
#include <list>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Cliente.h"
#include "Fichero.h"
#include "Menu.h"
#include "Agenda.h"
#include <stdio.h>
#include <string>
using namespace std;
int main(){
	system("clear");
	int opc;
	Menu menu;
	string DNI, nombre, apellido1, apellido2,numero,fijo, direccion, anotaciones,twitter, facebook;
	char fav;
	Agenda agenda;
	agenda.cargar();		//siempre se hará al iniciar el programa
	do{
 		cout<<"\n------------------CLINICA--------------------\n";
 		cout<<"1.-Añadir\n";
 		cout<<"2.-Mostrar todos\n";
 		cout<<"3.-Buscar\n";
 		cout<<"4.-Modificar\n";
 		cout<<"5.-Eliminar\n";
 		cout<<"6.-Añadir Favorito\n";
 		cout<<"7.-Hacer copia de seguridad\n";
 		cout<<"8.-Restaurar copia\n";
 		cout<<"9.-Salir\n";
 		cout<<"Introduce la opcion:";
 		cin>>opc;
 		switch(opc){
 			case 1: {
 				Cliente aux;
 						system("clear");
 						 getchar();
 				         cout<<"\nIntroduce el nombre:"<<endl;
 				         getline(cin,nombre);
 				         aux.setNombre(nombre);
 				        system("clear");
 				         cout<<"\nIntroduce el primer apellido:"<<endl;
 				         getline(cin,apellido1);
 				         aux.setApellido1(apellido1);
 				        system("clear");
 				         cout<<"\nIntroduce el segundo apellido:"<<endl;
 				         getline(cin,apellido2);
 				         aux.setApellido2(apellido2);
 				        system("clear");
 				         cout<<"\nIntroduce el DNI:"<<endl;
 				         getline(cin,DNI);
 				         aux.setDni(DNI);
 				        system("clear");
 				         cout<<"\nIntroduce el numero de telefono movil:"<<endl;
 				        getline(cin,numero);
 				         aux.setNumero(numero);
 				        system("clear");
 				         cout<<"\nIntroduce el numero de telefono fijo:"<<endl;
 				        getline(cin,fijo);
 				        aux.setFijo(fijo);
 				       system("clear");
 				        cout<<"\nIntroduce la dirección:"<<endl;

 				         getline(cin,direccion);
 				         aux.setDireccion(direccion);
 				        system("clear");
 				         cout<<"\nIntroduce la cuenta de twitter:"<<endl;
 				         getline(cin,twitter);
 				         aux.setTwitter(twitter);
 				         system("clear");
 				         cout<<"\nIntroduce la cuenta de facebook:"<<endl;
 				         getline(cin,facebook);
 				         aux.setFacebook(facebook);
 				        system("clear");
 				         cout<<"\n¿Quieres marcarlo como favorito?\tS/N"<<endl;
 				         cin>>fav;
 				         if(fav=='S' || fav=='s'){
 				        	 aux.setFavorito(1);
 				         }
 				         else aux.setFavorito(0);
 				         getchar();
 				         char anotacionesaux='n';
 				        system("clear");
 				         cout<<"\n¿Desea introducir anotaciones?	S/N";
 				         cin>>anotacionesaux;
 				         if(anotacionesaux=='S' || anotacionesaux=='s'){
 				        	 cout<<"\nIntroduce las anotaciones";
 				        	 getchar();
 				        	 getline(cin,anotaciones);
 				        	 aux.setAnotaciones(anotaciones);
 				         }
 				         //ahora hay que mirar en que posicion ponerlo, para ello habra que hacer un nuevo metodo
 				         list<Cliente>::iterator it=agenda.buscarpos(aux);
 				         agenda.insertarCliente(it,aux);
 				        agenda.guardar(agenda.getClientes(),"memoria_agenda");
 				         system("clear");
               }break;
 			case 2:{
 				system("clear");
 				menu.visualizar_agenda(agenda.getClientes());		//va a ser mejor pasarlo por referencia creo

 			}break;
 			case 3:{
 				system("clear");
 				Cliente aux;
 				int opc;
 				cout<<"1.-Por apellido\n";
 				cout<<"2.-Por dni\n";
 				cin>>opc;
 				switch(opc){
 					case 1:{
 						system("clear");
 							string apellido;
 							getline(cin,apellido);
 							menu.visualizar_agenda(agenda.getallApellido(apellido));
 							}break;


 					case 2:{
 						system("clear");
 						string dni;
 						cout<<"\nIntroduce el DNI";
 						cin>>dni;
 						aux.setDni(dni);
 						if(agenda.pertenece(aux)){
 						list<Cliente>::iterator it= agenda.buscar(aux);
 						Cliente otro=(*it);
 						menu.visualizar_cliente(otro);
 						}
 						else cout<<"\nNO";

 					}break;
 				}

 			}break;
 			case 4:{
 				system("clear");
 				Cliente aux;
 				cout<<"Introduce le DNI del cliente que desea modificar"<<endl;
 				cin>>DNI;
 				aux.setDni(DNI);
 				if(agenda.pertenece(aux))
 				{	int op=0;
 					list<Cliente>::iterator it;
 					it=agenda.buscar(aux);

 					do{
 						aux=agenda.getcliente(it);
 						system("clear");
 						cout<<"\n1.Nombre";
 						cout<<"\n2.Apellidos";
 						cout<<"\n3.Numero";
 						cout<<"\n4.Numero Fijo";
 						cout<<"\n5.DNI";
 						cout<<"\n6.Direccion";
 						cout<<"\n7.Anotaciones";
 						cout<<"\n8.Twitter";
 						cout<<"\n9.Facebook";
 						cout<<"\n10.Favorito";

 						if(aux.getFavorito()==1)
 							cout<<"\t FAVORITO";
 						else
 							cout<<"\t FAVORITO";
 						cout<<"\n0.Salir";
 						cin>>op;
 						switch(op){
 						case 1:{
 							system("clear");
 							cout<<"\nIntroduce el nombre";
 							getchar();
 							getline(cin,nombre);
 							aux.setNombre(nombre);
 							agenda.modificar(it,aux);
 							system("clear");
 						}break;
 						case 2:{
 							system("clear");
 							cout<<"\nIntroduce el primer apellido";
 							getchar();
 							getline(cin,apellido1);
 							aux.setApellido1(apellido1);
 							cout<<"\nIntroduce el segundo apellido";
 							getline(cin,apellido2);
 							aux.setApellido2(apellido2);
 							agenda.modificar(it,aux);
 							system("clear");

 						}break;
 						case 3:{
 							system("clear");
 							cout<<"\nIntroduce el numero";
 							cin>>numero;
 							aux.setNumero(numero);
 							agenda.modificar(it,aux);
 							system("clear");

 						}break;
 						case 4:{
 							system("clear");
 							cout<<"\nIntroduce el numero de telefono fijo";
 							cin>>fijo;
 							aux.setFijo(fijo);
 							agenda.modificar(it,aux);
 							system("clear");
 						}break;
 						case 5:{
 							system("clear");
 							cout<<"\nIntroduce el DNI";
 							cin>>DNI;
 							aux.setDni(DNI);
 							agenda.modificar(it,aux);
 							system("clear");

 						}break;
 						case 6:{
 							system("clear");
 							cout<<"\nIntroduce la direccion";
 							getline(cin,direccion);
 							aux.setDireccion(direccion);
 							agenda.modificar(it,aux);
 							system("clear");

 						}break;
 						case 7:{
 							cout<<"\nIntroduce las anotaciones";
 							getchar();
 							getline(cin,anotaciones);

 							aux.setAnotaciones(anotaciones);
 							agenda.modificar(it,aux);
 							//(*it)=aux;
 							system("clear");


 						}break;
 						case 8:{
 							cout<<"\nIntroduce el twitter";
 							cin>>twitter;
  							aux.setTwitter(twitter);
  							agenda.modificar(it,aux);
  							system("clear");


 						}break;
 						case 9:{
 							cout<<"\nIntroduce el facebook";
 							getline(cin,facebook);
  							aux.setFacebook(facebook);
  							agenda.modificar(it,aux);
 							system("clear");


 						}break;
 						case 10:{
 							if(aux.getFavorito()==1){
 								aux.setFavorito(0);
 								agenda.modificar(it,aux);
 							}
 							else{
 								aux.setFavorito(1);
 								agenda.modificar(it,aux);
 							}

 							}break;

 						}

 						}while(op!=0);

 				}
 				else cout<<"\nEl DNI introducido es el incorrecto\n";

 				agenda.guardar(agenda.getClientes(),"memoria_agenda");
 			}break;
 			case 5:{
 				cout<<"Introduce el DNI de quien desea eliminar"<<endl;
 				cin>>DNI;
				Cliente aux2;
 				aux2.setDni(DNI);
 				if(agenda.pertenece(aux2)){
 				list<Cliente>::iterator it= agenda.buscar(aux2);
 				agenda.eliminar(it);
 				cout<<"\nEl cliente ha sido borrado";
 				agenda.guardar(agenda.getClientes(),"memoria_agenda");
 				}
 				else cout<<"El DNI introducido no pertenece a ningun cliente";
 			}break;
 			case 6:{
 				Cliente aux;
 				cout<<"\nIntroduce el dni";
 				cin>>DNI;
 				aux.setDni(DNI);
 				list<Cliente>::iterator it= agenda.buscar(aux);
 				(*it).setFavorito(1);
 			}break;
 			case 7:{
 				cout<<"Introduce el nombre de la copia de seguridad";
 				getchar();
 				getline(cin,nombre);
 				agenda.guardar(agenda.getClientes(),nombre);
 			}break;
 			case 8:{

 			}break;

 			}
 		}while(opc!=9);

}

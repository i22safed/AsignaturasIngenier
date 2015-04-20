#include "dados.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	Dados d;

	int numero1;
	int numero2;

	cout<<"los valores de los dados en el estado inicial son:"<<d.getDado1()<<"y"<<d.getDado2()<<"\n";

	d.lanzamiento();

	cout<<"los valores de los dados aleatoriamente son:"<<d.getDado1()<<"y"<<d.getDado2()<<"\n";

	cout<<"La suma de los dados aleatorios es:"<<"\n";
	cout<<d.getSuma()<<"\n";

	cout<<"Introduzca dos numeros para usarlos como valor de los dados"<<"\n";

	cin>>numero1;
	cin>>numero2;

	d.setDado1(numero1);
	d.setDado2(numero2);

	cout<<"los valores de los dados introducidos son:"<<d.getDado1()<<"y"<<d.getDado2()<<"\n";

	cout<<"La suma de los dados aleatorios es:"<<"\n";
	cout<<d.getSuma()<<"\n";

	cout<<"La media de los numeros sacados en los lanzamientos son:"<<"\n";

	cout<<d.getLanzamiento1()<<"\n";
	cout<<d.getLanzamiento2()<<"\n";
	cout<<d.getMedia1()<<"\n";
	cout<<d.getMedia2()<<"\n";

	return 0;
}

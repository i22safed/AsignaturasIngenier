#include "dados.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


void Dados::lanzamiento()
{
	int numero1,numero2;

	dado1_=rand()%6+1;
	dado2_=rand()%6+1;

	lanzamiento1_++;
	lanzamiento2_++;

	suma1_+=dado1_;
	suma2_+=dado2_;

	vector1_[getLanzamiento1()%5]=getDado1();
	vector2_[getLanzamiento2()%5]=getDado2();
}

int Dados::getDado1()
{
	return dado1_;
}
int Dados::getDado2()
{
	return dado2_;
}

int Dados::getLanzamiento1()
{
	return lanzamiento1_;
}

int Dados::getLanzamiento2()
{
	return lanzamiento2_;
}

bool Dados::setDado1(int numero)
{
	if((numero>0)&&(numero<7))
	{
		dado1_=numero;
		lanzamiento1_++;
		suma1_+=dado1_;
		vector1_[getLanzamiento1()%5]=getDado1();
		return true;
	}
	else
	{
		return false;
	}
}

bool Dados::setDado2(int numero)
{
	if((numero>0)&&(numero<7))
	{
		dado2_=numero;
		lanzamiento2_++;
		suma2_+=dado2_;
		vector2_[getLanzamiento2()%5]=getDado2();
		return true;
	}
	else
	{
		return false;
	}
}

int Dados::getSuma()
{
	return getDado1()+getDado2();
}

float Dados::getMedia1()
{
	if(getLanzamiento1()==0)
	{
		return 0;
	}
	else
	{
		return ((float)suma1_)/((float)getLanzamiento1());
	}
}

float Dados::getMedia2()
{
	if(getLanzamiento2()==0)
	{
		return 0;
	}
	else
	{
		return((float)suma2_)/((float)getLanzamiento2());
	}
}

void Dados::getUltimos1(int *v)
{
	for(int i=0; i<5; i++)
	{
		v[i]=vector1_[i];
	}
}

void Dados::getUltimos2(int *v)
{
	for(int i=0; i<5; i++)
	{
		v[i]=vector2_[i];
	}
}

Dados::Dados()
{
	dado1_=1;
	dado2_=1;

	lanzamiento1_=0;
	lanzamiento2_=0;

	suma1_=0;
	suma2_=0;

	srand(time(NULL));
}

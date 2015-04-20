#include <iostream>
#include "ejemplosobrecarga.h"

using namespace std;


	Coordenadas::Coordenadas(int x, int y, int z)
	{
		x_=x;
		y_=y;
		z_=z;
	}

	Coordenadas& Coordenadas::operator+(const Coordenadas &c)
	{
		Coordenadas aux;

		aux.x_=x_+c.x_;
		aux.y_=y_+c.y_;
		aux.z_=z_+c.z_;

		return aux;

	}

	Coordenadas& Coordenadas::operator=(const Coordenadas &c)
	{

		x_=c.x_;
		y_=c.y_;
		z_=c.z_;

		return *this;
	}

	~Coordenadas(){};

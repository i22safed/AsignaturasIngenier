#ifndef EJEMPLOSOBRECARGA_H
#define EJEMPLOSOBRECARGA_H

#include <iostream>

using namespace std;


class Coordenadas
{
	private:

			int x_;
			int y_;
			int z_;

	public:

			Coordenadas(int x, int y, int z);

			Coordenadas& operator+(const Coordenadas &c);
			Coordenadas& operator=(const Coordenadas &c);

			~Coordenadas();
};

#endif

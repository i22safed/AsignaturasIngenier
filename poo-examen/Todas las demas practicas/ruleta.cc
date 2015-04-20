#include "ruleta.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
#include "jugador.h"
#include "crupier.h"
#include "persona.h"
#include <ctime>

using namespace std;

Ruleta::Ruleta(const Crupier &crupier):crupier_(crupier)
{

	bola_=-1;
	banca_=1000000;

}

int Ruleta::getBanca()
{
	return banca_;
}

bool Ruleta::setBanca(int bank)
{
	if(bank<0)
		return false;
	else
		banca_=bank;
		return true;
}

int Ruleta::getBola()
{
	return bola_;
}

bool Ruleta::setBola(int ball)
{
	if((ball<0)||(ball>36))
		return false;
	else
		bola_=ball;
		return true;
}

Crupier Ruleta::getCrupier()
{
	return crupier_;
}

void Ruleta::setCrupier(Crupier crupier)
{
	crupier_=crupier;
}

bool Ruleta::addJugador(Jugador jugador)
{
	jugadores_.push_back(jugador);

	ifstream fichero((jugador.getDNI()+".txt").c_str());

	fichero.close();


}

int Ruleta::deleteJugador(Jugador jugador)
{
	return deleteJugador(jugador.getDNI());
}

int Ruleta::deleteJugador(string DNI)
{
	list <Jugador> :: iterator i;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++)
	{
		if(jugadores_.empty())
				return -1;

		if(i->getDNI()==DNI)
		{
			jugadores_.erase(i);

			return 1;
		}
		return -2;
	}
};

void Ruleta::escribeJugadores()
{
	jugadores_.clear();

	ofstream fichero("jugadores.txt");

	list <Jugador> :: iterator i;

	for(i=jugadores_.begin(); i!= jugadores_.end(); i++)
	{
		fichero<< i->getDNI()<<","<< i->getCodigo()<<","<< i->getNombre()<<","<< i->getApellidos()<<","<<i->getDireccion()<<","<< i->getLocalidad()<<","<< i->getProvincia()<<","<< i->getPais()<<","<< i->getDinero()<<"\n";
	}

	fichero.close();
}

void Ruleta::leeJugadores()
{
	jugadores_.clear();

	ifstream fichero("jugadores.txt");

	Jugador j("prueba","prueba");

	string DNI;
	string codigo;
	string nombre;
	string apellidos;
	string direccion;
	string localidad;
	string provincia;
	string pais;
	string dinero;

	while(getline(fichero,DNI,','))
	{
		getline(fichero,codigo,',');
		getline(fichero,nombre,',');
		getline(fichero,apellidos,',');
		getline(fichero,direccion,',');
		getline(fichero,localidad,',');
		getline(fichero,provincia,',');
		getline(fichero,pais,',');
		getline(fichero,dinero,'\n');

		j.setDNI(DNI);
		j.setCodigo(codigo);
		j.setNombre(nombre);
		j.setApellidos(apellidos);
		j.setDireccion(direccion);
		j.setLocalidad(localidad);
		j.setProvincia(provincia);
		j.setPais(pais);
		j.setDinero(atoi((dinero).c_str()));

		jugadores_.push_back(j);
	}

	fichero.close();
}

void Ruleta::giraRuleta()
{
		srand(time(NULL));

		setBola(rand()%37);
}

void Ruleta::getPremios()
{
	list <Jugador> :: iterator i;
	list <Apuesta> :: iterator j;
	list <Apuesta> listaux;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++)
	{
		i->setApuestas();
		listaux=i->getApuestas();

		for(j=listaux.begin(); i!=jugadores_.end(); i++)
		{
			switch(j->tipo)
			{
				case 1:
				{
					if(atoi(j->valor.c_str())==bola_)
					{
						i->setDinero(i->getDinero()+(j->cantidad*35));
						banca_-=j->cantidad*35;
					}
					else
					{
						i->setDinero(i->getDinero()-(j->cantidad*35));
						banca_+=j->cantidad+35;
					}
				break;

				}
				case 2:
				{
					if(bola_!=0 && j->valor==setColobola(bola_))
					{
						i->setDinero(i->getDinero()+(j->cantidad));
						banca_-=j->cantidad;
					}
					else
					{
						i->setDinero(i->getDinero()-(j->cantidad));
						banca_+=j->cantidad;
					}
				break;
				}

				case 3:
				{
					if(bola_!=0 && j->valor==setParimpar(bola_))
					{
						i->setDinero(i->getDinero()+(j->cantidad));
						banca_-=j->cantidad;
					}
					else
					{
						i->setDinero(i->getDinero()-(j->cantidad));
						banca_+=j->cantidad;
					}
				break;
				}

				case 4:
				{
					if(bola_!=0 && j->valor==setAltobajo(bola_))
					{
						i->setDinero(i->getDinero()+(j->cantidad));
						banca_-=j->cantidad;
					}
					else
					{
						i->setDinero(i->getDinero()-(j->cantidad));
						banca_+=j->cantidad;
					}
				break;
				}

			}
		}
	}
}


string Ruleta::setColobola(int bola)
{
		string color;

		if(bola==0)
		{
			color="negro";
		}
		if(bola>0 && bola<=10)
		{
			if(bola%2==0)
			{
				color="negro";
			}
			else
			{
				color="rojo";
			}
		}
		if(bola>10 && bola<=18)
		{
			if(bola%2==0)
			{
				color="rojo";
			}
			else
			{
				color="negro";
			}
		}
		if(bola>18 && bola<=28)
		{
			if(bola%2==0)
			{
				color="negro";
			}
			else
			{
				color="rojo";
			}
		}
		if(bola>28 && bola<=36)
		{
			if(bola%2==0)
			{
				color="rojo";
			}
			else
			{
				color="negro";
			}
		}

		return color;
}

string Ruleta::setAltobajo(int bola)
{
	if(bola>18)
	{
		return "alto";
	}
	else
	{
		return "bajo";
	}
}

string Ruleta::setParimpar(int bola)
{
	if(bola%2==0)
	{
		return "par";
	}
	else
	{
		return "impar";
	}
}

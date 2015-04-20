#ifndef RULETA_H
#define RULETA_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
#include "jugador.h"
#include "crupier.h"
#include "persona.h"
#include <ctime>

using namespace std;

class Ruleta
{
	private:
		int banca_;
		int bola_;
		list <Jugador> jugadores_;
		Crupier crupier_;

	public:

		Ruleta(const Crupier &crupier);


		int getBanca();
		bool setBanca(int bank);

		int getBola();
		bool setBola(int ball);

		Crupier getCrupier();
		void setCrupier(Crupier crupier);

		bool addJugador(Jugador jugador);

		int deleteJugador(Jugador jugador);
		int deleteJugador(string DNI);

		list <Jugador> getJugadores(){return jugadores_;};


		void escribeJugadores();

		void leeJugadores();

		void giraRuleta();

		void getPremios();

		string setColobola(int bola);

		string setAltobajo(int bola);

		string setParimpar(int bola);
};







#endif

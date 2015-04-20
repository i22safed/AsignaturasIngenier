#ifndef DADOS_H
#define DADOS_H

	class Dados
	{
		private:

			int dado1_;
			int dado2_;

			int lanzamiento1_;
			int lanzamiento2_;

			int suma1_;
			int suma2_;

			int vector1_[5];
			int vector2_[5];

		public:

			void lanzamiento();

			int getDado1();
			int getDado2();

			int getLanzamiento1();
			int getLanzamiento2();

			bool setDado1(int numero);
			bool setDado2(int numero);

			int getSuma();

			float getMedia1();
			float getMedia2();

			void getUltimos1(int *v);
			void getUltimos2(int *v);

			Dados();

	};

#endif

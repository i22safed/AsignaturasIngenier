#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct parametros
{
	float escalar;

	float matriz[3][3];
};

void * escalarporMatriz(void * valor)
{
	struct parametros * auxiliar;

	int i, j;

	auxiliar=(struct parametros *)malloc(sizeof(struct parametros));

	auxiliar=(struct parametros *)valor;

 	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			(*auxiliar).matriz[i][j]=((*auxiliar).matriz[i][j])*((*auxiliar).escalar);
		}
	}

	pthread_exit((void *)auxiliar);

}

int main()
{
	pthread_t *hilos;

	struct parametros * valores;
	struct parametros auxiliar;

	void *contenedor;

	int i, j, k;

	valores=(struct parametros *)malloc(sizeof(struct parametros)*2);

 	hilos=(pthread_t *)malloc(sizeof(pthread_t)*2);

	for(i=0; i<2; i++)
	{
			printf("\nIntroduce un escalar para multiplicar la matriz%d: ",i+1);
			scanf("%f", &auxiliar.escalar);

			printf("\nIntroduce todos los elementos de la matriz %d\n", i+1);

			for(j=0; j<3; j++)
			{
				for(k=0;k<3; k++)
				{
					printf("\t[%d][%d]: ", j+1,k+1);
					scanf("%f", &auxiliar.matriz[j][k]);
				}
			}

		valores[i]=auxiliar;
	}


	for(i=0; i<2; i++)
	{
		pthread_create(&hilos[i], NULL, (void *)escalarporMatriz, (void *)&valores[i]);
	}


	for(i=0; i<2; i++)
	{
		pthread_join(hilos[i], (void **)&contenedor);
		valores[i]=*(struct parametros *)contenedor;
	}

	for(i=0; i<2; i++)
	{
		printf("\nLa matriz %d por el escalar %f\n\t", i+1, valores[i].escalar);
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				printf("[%2.0f]",valores[i].matriz[j][k]);
			}

			printf("\n\t");
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global=0;

void  incrementarCincuenta()
{
	int i;

	for(i=0; i<50;i++)
	{
		global ++;
	}

}


int main()
{
	printf("\nEl valor de la variable <global>: %d", global);
	pthread_t * hilos;

	hilos=(pthread_t *)malloc(sizeof(pthread_t)*2);

	int i;

	for(i=0; i<2; i++)
	{
		pthread_create(&hilos[i], NULL, (void *)incrementarCincuenta, NULL);
	}

	for(i=0; i<2; i++)
	{
		pthread_join(hilos[i], NULL);
	}

	printf("\nEl valor de la variable <global> es: %d\n\n", global);

	return 0;
}

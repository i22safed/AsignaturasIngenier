#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void *numerosAleatorios( void *numero )
{
	int aleatorio1, aleatorio2, suma;

	sleep((int) numero);

	srand( time ( NULL ) );


	aleatorio1 = rand() % 10;
	aleatorio2 = rand() % 10;

	suma = aleatorio1 + aleatorio2;

	fflush(stdout);

	printf("Hebra %d:aleatorio1:%d, aleatorio2:%d, su suma:%d\n", (int) numero, aleatorio1, aleatorio2, suma);

	pthread_exit((void *)suma);

}



int main()
{
	int numeroHebras, sumaTotal;

	int aux, i;

	printf("Introduce el numero de hebras:\n");
	scanf( "%d", &numeroHebras);

	pthread_t hebras[numeroHebras];

	for( i = 0; i < numeroHebras; i++)
	{
		pthread_create( hebras + i, NULL, (void *)numerosAleatorios, (void *)i);

		pthread_join(hebras[i], (void**)&aux);

		sumaTotal += aux;
	}

	sumaTotal = 0;

	for( i = 0; i < numeroHebras; i++)
	{

		pthread_join(hebras[i], (void**)&aux);

		sumaTotal += aux;

	}

	printf("La suma total es:%d\n", sumaTotal);

	return 0;
}

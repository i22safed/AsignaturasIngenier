#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct posicion
{

	int inicio;

	int final;

	int * v;

};

void sumaVector (void * sum)
{
	struct posicion * aux;

	int * suma;

	int i;

	aux = ( struct posicion *) sum;

	suma = (int*) malloc (sizeof (int));

	*suma = 0;

	for ( i = (* aux).inicio; i < (* aux).final; i++)
	{

		*suma = *suma + aux->v[i];

	}
	printf("\n\t %10s %4d","Subtotal",*suma);

 	pthread_exit ((void *) suma);

}



int main (int argc, char **argv)
{
	if( argc != 2)
	{
		printf("El formato es :./eje3.exe numero\n");

		exit(EXIT_FAILURE);

	}

	int nHilos = atoi (argv [1]);

	int numAleatorios[10];

	int resto, inicio, final, i, sumaTotal = 0;

	pthread_t * hilos;

	hilos = (pthread_t *) malloc (sizeof (pthread_t)*nHilos);

	struct posicion * sum;

	sum = (struct posicion *) malloc (sizeof (struct posicion)*nHilos);

	void * subsumaTotal;

	srand (time (NULL));

	printf("\nVector aleatorio generado: ");

	for (i = 0; i < 10; i++)
	{
		numAleatorios[i] = rand() % 10;

		printf("[%d ]", numAleatorios[i]);

	}



	printf("\n");

	resto = 10 % nHilos;

	for(i=0; i<nHilos; i++){

		if(i!=0){//Si no es la primera iteracion
			inicio=final+1;
		}
		else{//Si es la primera iteracion
			inicio=0;
		}

		final=inicio+(10/nHilos)-1;

		if(resto!=0){
			final++;
			resto--;
		}

		sum[i].inicio=inicio;
		sum[i].final=final;
		sum[i].v=numAleatorios;

	}

	for (i = 0; i < nHilos ; i++)
	{
		pthread_create (&hilos[i], NULL, (void *) sumaVector, (void *)& sum[i]);

	}

	for(i=0; i<nHilos; i++)
	{
			pthread_join (hilos[i], (void **)&subsumaTotal);

			sumaTotal= sumaTotal + *(int *)subsumaTotal;
	}

	printf("\nLa suma total es: %d\n", sumaTotal);

	return 0;
}

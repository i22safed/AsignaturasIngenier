#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t semaforo;//semaforo global

void *imprimeCaracter(void *caracter);

int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Formato incorrecto introduzca el formato: ./ejercicio2.exe numeroHebras\n");
		exit(EXIT_FAILURE);
	}

	int numHilos, i;
	numHilos=atoi(argv[1]);

	char *caracter;

	pthread_t *hilo;

	caracter=(char *)malloc(sizeof(char)*numHilos);
	hilo=(pthread_t *)malloc(sizeof(pthread_t)*numHilos);

	for(i=0; i<numHilos; i++)
	{
		printf("Introduce un caracter a la posicion %d del vector de caracteres\n", i+1);
		scanf("%c", &caracter[i]);
		getchar();
	}

	for(i=0; i<numHilos; i++)
	{
		pthread_create(&hilo[i], NULL, (void *)imprimeCaracter, (void *)&caracter[i]);
	}

	for(i=0; i<numHilos; i++)
	{
		pthread_join(hilo[i],NULL);
	}

	free(caracter);
	free(hilo);

	exit(EXIT_SUCCESS);
}

void *imprimeCaracter(void *caracter)
{
	char caracteres=*(char *)caracter;

	int i;

	pthread_mutex_lock(&semaforo);

	for(i=0; i<5; i++)
	{
		printf("%c",caracteres);
		fflush(stdout);
		sleep(1);
	}

	pthread_mutex_unlock(&semaforo);

	pthread_exit(NULL);
}

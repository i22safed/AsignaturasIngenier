#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define tam 100

struct estructura
{
	int entero;

	char mensaje[tam];
};


void cambiaEstructura(void * valor)
{
	struct estructura * auxiliar;
	auxiliar=(struct estructura *)malloc(sizeof(struct estructura));

	auxiliar=(struct estructura *)valor;

	(*auxiliar).entero+=1;
	(*auxiliar).mensaje[0]='9';

	pthread_exit((void *)auxiliar);
}

int main(int argc, char ** argv)
{
	if(argc<2)
	{
		printf("\nEL formato para ejecutar es: ./ejercicio7.exe numerodeHebras\n");
		exit(EXIT_FAILURE);
	}

	int i;
	int numHebras;
	numHebras=atoi(argv[1]);

	pthread_t * hilos;
	hilos=(pthread_t *)malloc(sizeof(pthread_t)*numHebras);

	struct estructura * estructuras;
	struct estructura * auxiliar;
	void * contenedor;

	estructuras=(struct estructura *)malloc(sizeof(struct estructura)*numHebras);
	auxiliar=(struct estructura *)malloc(sizeof(struct estructura)*numHebras);


	for(i=0; i<numHebras; i++)
	{
		printf("\nIntroduce un entero para la estructura[%d]: ", i+1);
		scanf("%d", &auxiliar[i].entero);

		getchar();

		printf("Introduce un mensaje para la estructura[%d]: ", i+1);
		fgets(auxiliar[i].mensaje, 200, stdin);
	}

	for(i=0; i<numHebras; i++)
	{
		pthread_create(&hilos[i], NULL, (void *) cambiaEstructura, (void *)&auxiliar[i]);
	}

	for(i=0; i<numHebras; i++)
	{
		pthread_join(hilos[i], (void **)&contenedor);
		estructuras[i]=*(struct estructura *)contenedor;
	}

	for(i=0; i<numHebras; i++)
	{
		printf("Estructura %d: \n\tentero: %d\n\tcadena: %s", i+1, estructuras[i].entero, estructuras[i].mensaje);
	}

	return 0;
}

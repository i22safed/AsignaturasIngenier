#include <stdio.h>
#include <stdlib.h>

int *nivel;
int *esperando;
int nHilos;

int global=0;//Sección crítica

void *hilo(void *id);

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("\nEl formato introducido es erroneo, es: ./ejercicio1.exe numero de hilos\n");

		exit(EXIT_FAILURE);
	}

	nHilos=atoi(argv[1]);

	int i;
	int *id;

	pthread_t *hilos;

	hilos=(pthread_t *)malloc(sizeof(pthread_t)*nHilos);

	id=(int *)malloc(sizeof(int)*nHilos);

	nivel=(int *)malloc(sizeof(int)*nHilos);

	esperando=(int *)malloc(sizeof(int)*(nHilos-1));

	for(i=0; i<nHilos; i++)
	{
		id[i]=i;

		nivel[i]=-1;

		if(i<nHilos-1)
		{
			esperando[i]=-1;
		}

	}

	for(i=0; i<nHilos; i++)
	{
		pthread_create(&hilos[i], NULL, (void *)hilo, (void *)&id[i]);
	}

	for(i=0; i<nHilos; i++)
	{
		pthread_join(hilos[i], NULL);
	}

	printf("\nHebra principal, valor de la variable global: %d", global);

	free(hilos);
	free(id);
	free(nivel);
	free(esperando);

	exit(EXIT_SUCCESS);
}

void *hilo(void *identificador)
{
	int id=*(int *)identificador;
	int i,j;
	int existe=0;
	int local;

	for(i=0; i<nHilos-1; i++)
	{
		nivel[id]=i;
		esperando[i]=id;

		do
		{
			existe=0;
			for(j=0; j<nHilos-1; j++)
			{
				if(j!=id && nivel[j]>=i)
				{
					existe=1;
				}
			}

		}while(esperando[i]==id && existe==1);

	}

	printf("Hilo  %d esta en la seccion critica, variable global %d\n", id, global);
	for(i=0; i<5; i++)
	{
		local=global;
		local++;
		global=local;
		usleep(200000);
	}

	printf("Hilo %d sale de la seccion critica, variable global %d\n", id, global);

	nivel[id]=-1;
}

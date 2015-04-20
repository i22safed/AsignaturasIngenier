#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define TOTAL 10

int vector[TOTAL];
int nElementos;

pthread_mutex_t cerrojo;
pthread_cond_t vacio, lleno;

void *productor();
void *consumidor();

int main()
{
  srand(time(NULL));

  pthread_mutex_init(&cerrojo, NULL);

  pthread_cond_init(&vacio, NULL);
  pthread_cond_init(&lleno, NULL);

  int i;

  pthread_t hilo[2];

  for(i=0; i<TOTAL; i++)
  {
    vector[i]=rand()%10;
    nElementos++;
  }

  pthread_create(&hilo[0], NULL, (void *)productor, NULL);
  pthread_create(&hilo[1], NULL, (void *)consumidor, NULL);

  pthread_join(hilo[0], NULL);
  pthread_join(hilo[1], NULL);

  pthread_exit(NULL);
}

void *productor()
{
  int i, j;

  pthread_mutex_lock(&cerrojo);

  for(i=0; i<TOTAL; i++)
  {
    j=rand()%10;

    while(nElementos==TOTAL)
    {
      printf("\nEL vector esta lleno");
      pthread_cond_wait(&lleno, &cerrojo);
    }

    vector[i]=j;
    nElementos++;
    
    printf("\nHay %d elementos en el vector", nElementos);
    printf("\nEL elento producido es:%d", vector[i]);

  }

  pthread_cond_signal(&vacio);
  pthread_mutex_unlock(&cerrojo);

  pthread_exit(NULL);
}

void *consumidor()
{
  int i, dato;

  pthread_mutex_lock(&cerrojo);

  for(i=0; i<TOTAL; i++)
  {

    while(nElementos==0)
    {
      printf("\nEl vector esta vacio");
      pthread_cond_wait(&vacio, &cerrojo);
    }

    dato=vector[i];
    nElementos--;

    printf("\nHay %d elementos en la lista", nElementos);
    printf("\nEL elemento consumido fue:%d", dato);

  }

  pthread_cond_signal(&lleno);
  pthread_mutex_unlock(&cerrojo);

  pthread_exit(NULL);

}

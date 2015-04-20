#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL 10

pthread_mutex_t lock;
pthread_cond_t vacio, lleno;

int vector[TOTAL];
int nElementos=0;

void *productor();
void *consumidor();

int main(int argc, char **argv)
{
  srand(time(NULL));
  int i;

  pthread_mutex_init(&lock, NULL);

  pthread_cond_init(&vacio, NULL);
  pthread_cond_init(&lleno, NULL);

  pthread_t pid[2];

  for(i=0; i<TOTAL; i++)
  {
    vector[i]=rand()%5;
    nElementos++;
  }

  pthread_create(&pid[0], NULL, (void *)productor, NULL);
  pthread_create(&pid[1], NULL, (void *)consumidor, NULL);

  pthread_join(pid[0], NULL);
  pthread_join(pid[1], NULL);


  pthread_exit(NULL);
}

void *productor()
{
  int i, j;

  pthread_mutex_lock(&lock);

  for(i=0; i<TOTAL; i++)
  {
    j=rand()%5;

    while(nElementos==TOTAL)
    {
        printf("\nEL vector esta completo");
        pthread_cond_wait(&lleno,&lock);
    }
      vector[i]=j;
      nElementos++;

      printf("\nNumero de elementos en el vector:%d", nElementos);
      printf("\nEL elemento producido es: %d", vector[i]);

  }

  pthread_cond_signal(&vacio);
  pthread_mutex_unlock(&lock);


  pthread_exit(NULL);
}

void *consumidor()
{
  int i, dato;

  pthread_mutex_lock(&lock);

  for(i=0; i<TOTAL; i++)
  {
    while(nElementos==0)
    {
      printf("\nEl vector esta vacio");
      pthread_cond_wait(&vacio, &lock);
    }

    dato=vector[i];
    nElementos--;

    printf("\nNumero de elementos en el vector:%d", nElementos);
    printf("\nEl elemento consumido es: %d", dato);

  }

  pthread_cond_signal(&lleno);
  pthread_mutex_unlock(&lock);

  pthread_exit(NULL);
}

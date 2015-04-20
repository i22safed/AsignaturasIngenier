#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL 10

pthread_mutex_t lock;

int array[TOTAL];
int nElementos=0;

void *productor();
void *consumidor();

int main (int argc, int **argv)
{
  srand(time(NULL));

  int i;

  pthread_mutex_init(&lock, NULL);

  pthread_t pid [2];

  for(i=0; i<TOTAL; i++)
  {
    array[i]=rand()%5;
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

  for(j=0; j<TOTAL; j++)
  {
    i=rand()%5;

    while(nElementos==TOTAL)
    {
      printf("\nEL vector esta completo");
      pthread_mutex_unlock(&lock);
    }

    array[j]=i;
    nElementos++;

    printf("\nEl numero de elementos producidos es:%d", nElementos);
    printf("\nProducto creado\n");

  }

  pthread_mutex_unlock(&lock);

  pthread_exit(NULL);

}

void *consumidor()
{
  int j, dato;

  pthread_mutex_lock(&lock);

  for(j=0; j<TOTAL; j++)
  {
    while(nElementos==0)
    {
      printf("\nEl vector esta vacio");
      pthread_mutex_unlock(&lock);
    }

    dato=array[j];
    nElementos--;

    printf("\nEL numero de elementos que quedan sin consumir es:%d",nElementos);
    printf("\nProducto consumido: %d\n", dato);

  }

  pthread_mutex_unlock(&lock);

  pthread_exit(NULL);
}

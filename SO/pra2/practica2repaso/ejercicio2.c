#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *numAleatorios(void *i);

int main()
{
  int nHebras, sumaTotal;

  printf("\nIntroduce el numero de hebras que quieres utilizar\n");
  scanf("%d", &nHebras);

  int i, auxiliar;

  pthread_t hilos[nHebras];

  for(i=0; i<nHebras; i++)
  {
    phtread_create(&hilos[i], NULL, (void *)numAleatorios, (void *)&i);
  }

  sumaTotal=0;

  for(i=0; i<nHebras; i++)
  {
    pthread_join(hilos[i], (void **)&auxiliar);

    sumaTotal+=auxiliar;
  }

  printf("\nLa suma total es: %d", sumaTotal);

  pthread_exit(NULL);
}

void *numAleatorios(void *i)
{
  int numero1, numero2, sumaParcial;

  sleep((int)i);

  srand(time(NULL));

  numero1=rand()%10;
  numero2=rand()%10;

  sumaParcial=numero1+numero2;

  fflush(stdout);

  printf("\nHebra:%d, numeroAleatorio1:%d, numeroAleatorio2:%d, suma de los dos:%d\n", (int) i, numero1, numero2, sumaParcial);

  pthread_exit((void *)sumaParcial);
}

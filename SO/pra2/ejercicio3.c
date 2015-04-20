#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct posicion
{
  int inicio;
  int final;

  int *v;
};

void *sumaVector(void * sum)
{
    struct posicion *aux;
    int *suma;
    int i;

    aux=(struct posicion *)sum;

    suma= (int *) malloc(sizeof(int));

    *suma=0;

    for(i= (*aux).inicio; i<=(*aux).final; i++)
    {
        *suma=*suma + aux->v[i];
    }
    printf("\n\t %10s %4d", "Subtotal", *suma);

    pthread_exit((void *)suma);


}






int main(int argc, char **argv)
{


    if(argc!=2)
    {
      printf("Introduzca el formato : ./ejercicio3.exe numero");

      exit(EXIT_FAILURE);
    }

    int nHilos;

    nHilos = atoi (argv[1]);

    pthread_t *hilos;

    hilos = (pthread_t *) malloc(sizeof (pthread_t)*nHilos);

    int inicio, final, sumaTotal=0, resto;

    struct posicion* suma;

    suma = (struct posicion*) malloc(sizeof (struct posicion)*nHilos);

    int aleatorios[10];

    int i;

    void *subsuma;

    srand(time(NULL));

    printf("Generando el vector de numeros aleatorios");

    for(i=0; i<10; i++)
    {
      aleatorios[i]=rand() % 10;

      printf("[%d] ", aleatorios[i]);
    }

    printf("\n");

    resto=10 % nHilos;

    for(i=0; i<nHilos; i++)
    {
      if(i!=0)
      {
        inicio=final + 1;

      }else
        {
          inicio=0;

        }

      final=inicio + (10 / nHilos) - 1;

      if(resto!=0)
      {
        final++;
        resto--;
      }

      suma[i].inicio=inicio;
      suma[i].final=final;
      suma[i].v= aleatorios;
    }

    for(i=0; i<nHilos; i++)
    {
      pthread_create(&hilos[i], NULL, (void*)sumaVector,(void*)&suma[i]);
    }

    for(i=0; i<nHilos; i++)
    {
      pthread_join(hilos[i], (void**)&subsuma);
      sumaTotal+=*(int *)subsuma;
    }

    printf("\n\n\t %10s %4d \n\n","Total",sumaTotal);

    return 0;
}

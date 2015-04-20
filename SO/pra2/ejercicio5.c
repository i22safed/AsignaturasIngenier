#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *cuentaLineas(void *fichero)
{
    char *auxiliar;

    int letra;


    FILE *archivo;

    auxiliar=(char *)fichero;

    archivo=fopen(auxiliar,"r");


    int *sumaLineas;

    sumaLineas=(int *)malloc(sizeof(int));

    *sumaLineas=0;



    while((letra=fgetc(archivo))!=EOF)
    {

      if(letra=='\n')
      {

        *sumaLineas+=1;
      
      }

    }

    fclose(archivo);

    printf("\nLa suma de lineas de este fichero es:%d", *sumaLineas);

    pthread_exit((void *)sumaLineas);

}

int main(int argc, char **argv)
{

  system("clear");

  if(argc<1)
  {

    printf("El formato para ejecutar el programa es:/ejercicio5.c fichero1 fichero2...ficheroN");

    exit(EXIT_FAILURE);

  }

  int archivos;

  archivos=argc-1;

  pthread_t *hilos;

  hilos=(pthread_t *) malloc(sizeof(pthread_t)*archivos);

  void *subSuma;

  int sumaTotal=0;


  int i;

  for(i=1; i<argc; i++)
  {

    pthread_create(&hilos[i-1], NULL, (void *)cuentaLineas, (void*)argv[i]);

  }

  for(i=0; i<archivos; i++)
  {

    pthread_join(hilos[i], (void**)&subSuma);

    sumaTotal+=*(int *)subSuma;

  }

  printf("\nEL total de las lineas %d de %d ficheros\n\n",sumaTotal, archivos);

  return 0;

}

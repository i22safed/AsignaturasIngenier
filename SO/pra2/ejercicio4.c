#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


void *convertirMp3(void *archivo)
{

    char *aux;
    aux=(char *)archivo;

    char ruta[200]="ffmpeg -i ";

    strcat(ruta,aux);
    strcat(ruta, " -f mp3 -ab 19200 -ar 4800 -vn ");

    printf("%s\n", ruta);

    aux=strtok(aux, ".");

    strcat(ruta,aux);
    strcat(ruta,".mp3");

    printf("%s\n", ruta);

    fflush(stdout);

    printf("\n Cambiando formato: '%s'",ruta);

    system(ruta);
}

int main(int argc, char **argv)
{
  if(argc<1)
  {
    printf("El formato para ejecutar el programa es : ./ejercicio4 ejemplo.mp4 .... n.mp4\n");

    exit(EXIT_FAILURE);

  }

  int nhilos;

  nhilos=argc-1;

  char **archivos;

  pthread_t *hilos;

  system("clear");

  hilos=(pthread_t*)malloc(sizeof(pthread_t)*nhilos);

  archivos=(char **)malloc(sizeof(char *)*nhilos);

  int i;

  for(i=1; i<argc; i++)
  {
    archivos[i-1]=argv[i];
  }

  for(i=0; i<nhilos; i++)
  {

    pthread_create(&hilos[i], NULL, (void*)convertirMp3, (void*)archivos[i]);

  }

  for(i=0; i<nhilos; i++)
  {

    pthread_join(hilos[i], NULL);

  }

  printf("\n");


  return 0;
}

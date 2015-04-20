#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *imprimirCadena(char *cadena);

int main(int argc, char **argv)
{

  if(argc!=3)
  {
    printf("\nIntroduzca este formato ./ejercicio1.exe hola mundo\n");
  }

  char *cadena1;
  char *cadena2;

  cadena1=(char *)argv[1];
  cadena2=(char *)argv[2];

  pthread_t hilo1, hilo2;

  pthread_create(&hilo1, NULL, (void *)imprimirCadena, (void *)cadena1);
  pthread_create(&hilo2, NULL, (void *)imprimirCadena, (void *)cadena2);

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  return 0;
}

void *imprimirCadena(char *cadena)
{
    int tam, i;

    tam=strlen(cadena);

    for(i=0; i<tam; i++)
    {
      printf("[%c]", cadena[i]);

      fflush(stdout);
      sleep(1);
    }

    pthread_exit(NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int dato=4;
int nLectores=0;

pthread_mutex_t cerrojo;
pthread_mutex_t cerrojoLectores;

void *Lector();
void *Escritor();

int main()
{
  pthread_mutex_init(&cerrojo, NULL);
  pthread_mutex_init(&cerrojoLectores, NULL);

  pthread_t escritor1, escritor2, escritor3;
  pthread_t lector1, lector2, lector3, lector4;

  printf("Creando escritor1\n");
  pthread_create(&escritor1, NULL, (void*)Escritor, NULL);
  printf("Creando lector1\n");
  pthread_create(&lector1, NULL, (void*)Lector, NULL);
  printf("Creando escritor2\n");
  pthread_create(&escritor2, NULL, (void*)Escritor, NULL);
  printf("Creando escritor3\n");
  pthread_create(&escritor3, NULL, (void*)Escritor, NULL);
  printf("Creando lector2\n");
  pthread_create(&lector2, NULL, (void*)Lector, NULL);
  printf("Creando lector3\n");
  pthread_create(&lector3, NULL, (void*)Lector, NULL);
  printf("Creando lector4\n");
  pthread_create(&lector4, NULL, (void*)Lector, NULL);

  pthread_join(escritor1, NULL);
  pthread_join(lector1, NULL);
  pthread_join(escritor2, NULL);
  pthread_join(lector2, NULL);

  pthread_mutex_destroy(&cerrojo);
  pthread_mutex_destroy(&cerrojoLectores);

  pthread_exit(NULL);
}

void *Escritor()
{
  pthread_mutex_lock(&cerrojo);

  printf("\nEL escritor va a modificar el dato %d", dato);
  dato=dato+2;
  printf("\nEl escritor ha modificado el dato %d", dato);

  pthread_mutex_unlock(&cerrojo);

  pthread_exit(NULL);
}

void *Lector()
{
  pthread_mutex_lock(&cerrojoLectores);
  nLectores++;
  if(nLectores==1)
  {
    pthread_mutex_lock(&cerrojo);
  }

  pthread_mutex_unlock(&cerrojoLectores);
  printf("\nEL lector ha leido el dato %d\n", dato);
  pthread_mutex_lock(&cerrojoLectores);
  nLectores--;
  if(nLectores==0)
  {
    pthread_mutex_unlock(&cerrojo);
  }
  pthread_mutex_unlock(&cerrojoLectores);

  pthread_exit(NULL);
}

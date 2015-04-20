#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


void *imprimirCadena( char *cadena)
{
	int i, tam;
	
	tam = strlen(cadena);

	for( i = 0; i < tam; i++)
	{
	
	
		
		printf("[%c]", cadena [i]);
		
		fflush(stdout);
		sleep(1);
	}
	

	pthread_exit( NULL);
} 


int main (int argc, char **argv)
{

	if(argc != 3)
	{
				
		printf("Error: El formato es ./eje1.exe hola mundo\n");
		
	}
	
	char *hola;
	char *mundo;
	
	hola = (char *)argv[1];
	mundo = (char *)argv[2];	
	
	pthread_t hilo1, hilo2;
	
	pthread_create( &hilo1, NULL, (void *)imprimirCadena, (void *)hola);
	pthread_create( &hilo2, NULL, (void *)imprimirCadena, (void *)mundo);
	
		
	printf("Todos los hilos han terminados\n");
	
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);		

}

#include <sys/types.h> 
#include <wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100


int main (int argc, char ** argv)
{
	FILE *f;
	int i, estadoHijo;
	char nombreFichero [DIM];
	if (argc != 2)
	{
		printf ("\nError en el número de parámetros introducidos\n");
		printf ("\nForma de introducción: Ejecutable Nombre del fichero \n");
	}
	else
	{
		pid_t idProceso;
		f = fopen(nombreFichero, "w");
		strcpy(nombreFichero, argv[1]);
		printf ("\nEl nombre del fichero a crear es: %s\n", nombreFichero);
		for (i=1; i<3; i++)
		{
			idProceso = fork ();
			switch (idProceso)
			{
				case -1:
				{
					perror ("\nError en fork ()\n");
					printf("\nValor del errno = %d\n", errno); 
					exit (EXIT_FAILURE);
					break;
				}
				case 0: //Proceso hijo
				{
					if (i==1)
					{
						fprintf(f, "Hola, soy el hijo 1\n");
						exit (EXIT_SUCCESS);
						break;
					}
					else
					{
						fprintf(f, "Hola, soy el hijo 2\n");
						fflush(f);
						exit (EXIT_SUCCESS);
						break;
					}
				}
			
				default:
				{ 
					printf ("Padre : Mi pid es %d. El pid de mi hijo es %d\n", getpid(), idProceso); 
					wait(&estadoHijo);
					sleep(1);
					fprintf(f, "Hola, soy el padre\n");
					break;
				}
			}
		}
	}
	if (WIFEXITED(estadoHijo) != 0)
	{
		fclose (f);
		printf ("\nPrograma de apertura de ficheros terminado.\n");
	}
	else
	{
		fclose (f);
		printf ("\nError en el programa de apertura de ficheros.\n");
	}
	return (0);
}

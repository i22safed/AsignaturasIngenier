#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main (int argc, char *argv[]) 
{	
	int i,j, numero, valor;
	
	if(argc!=2)
	{
		printf("El numero de argumentos tiene el formato: ./out.c n\n");
		
		exit(EXIT_FAILURE);
	
	
	}
	
	
	numero= atoi(argv [1]);
	
	valor=numero;
	
	
	for(i = 0; i < numero; i++)
	{
		if(valor > 1)
		{
			printf("Calculando parciales del factorial de %d\n",atoi(argv [1]));
			valor--;			
			numero = numero * (valor);	 
			sleep(1);
		}
	}
				
	printf("El factorial del numero %d es %d\n",atoi(argv [1]), numero);

	return 0;
}	

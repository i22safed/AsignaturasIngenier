#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/*void abrirGedit (char **argv)
{
	int i=0;
	
	char **argEdit = &argv [1];
	
	while (argEdit[i] !=NULL);
	{
		
		execvp(argv[1], &argEdit[i]);
		
		i++;
		
		
	
	}


}*/

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		
		printf("Introduce los parametros con el formato: :/eje7.exe  gedit nombreFichero\n");
	
	}

	FILE *f;
	
	char nombreFichero [100];
	
	int valor;	
	
	pid_t pid;
	
	int i , flag;

	strcpy(nombreFichero, argv [2]);

	f = fopen(nombreFichero, "a");
	
	printf("Nombre de fichero: %s\n", nombreFichero); 
	
	for (i = 0; i < 2; i++)
	{
		
		pid = fork();
		
		
 		switch (pid)
		{
		
			case -1:
			
				perror("FORK ERROR \n");
				
				printf("errno value:%d\n", errno);
				
				exit(EXIT_FAILURE);
				
			case 0:
			
				printf("El id del hijo:%d, del padre con id:%d\n", getpid(), getppid());
				
				if(i == 0)
				{
				
					fprintf( f, "%s" ,"--------1\n");
					
					fflush(f);
		
					sleep(1);
					
					
					

				}if(i == 1)
				{
		
					fprintf( f, "%s" ,"--------2\n");
						
					fflush(f);
						
					sleep(1);					
					
									
				}
			
				
				exit(EXIT_SUCCESS);
			
			default: 
				
				wait(&valor);
				
				printf("El id del padre:%d\n", getpid());		
											
				fprintf( f, "%s" ,"++++++++\n");

				fflush(f);	


				break;
		}
	
	}
	
	fclose(f);
	
	execvp( argv[1] , &argv[1]);
		
	

	
	
	return 0;	
}

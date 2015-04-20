#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char** argv)
{
	pid_t pid;
	int i=1, j, valor, status;
	int numero[1];
	if(argc!=4)
	{
		printf("El numero de argumentos tiene el formato: ./out.c n\n");
		
		exit(EXIT_FAILURE);
	
	
	}
	
	
	//numero[0]= atoi(argv [2]);
	//numero[1]= atoi(argv [3]);
	

	
	for(j = 0; j < 2; j++)
	{
		pid=fork();
		i++;
		switch(pid)
		{		
			case -1:
				perror("Fork error\n");
				
				printf("errno value:%d\n", errno);
				
				exit(EXIT_FAILURE);
			
			case 0:								
					printf("El proceso hijo %d, del padre %d\n", getpid(), getppid());
					execl("/home/p02polea/so/ejercicios/factorial/factorial.exe", "./factorial.exe", argv[i], NULL);
					//break;
			default:
				
				printf("EL padre %d, del hijo %d\n", getppid(), getpid());
		}		
			
	}	
	while(wait(&status)!=-1);
	return 0;
}

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void abrirCalculador (char **argv)
{

	execlp("gnome-calculator", argv[1],NULL);
	
}

void abrirGedit (char **argv)
{
	
	int i = 0;
	
	char **argedit = &argv[2];
	
	while (argedit[i] != NULL)
	{
		
		execvp (argv[2], &argedit[i]);
		
		i++;
	
	}


}


int main(int argc, char **argv)
{
	pid_t pid;
	
	int i;

	
	for(i = 0; i < 2; i++)	
	{	
			
		pid = fork();
	
		switch(pid)
		{
			case -1:
			
				perror("FORK ERROR\n");
			
				printf("errno value:%d\n", errno);
			
				exit(EXIT_FAILURE);
			
			case 0:
			
				if(i == 0)
				{
					printf("El hijo con id:%d, del padre con id:%d\n", getpid(), getppid());
				
					 abrirCalculador (argv);
					
					exit(EXIT_SUCCESS);
					
				
					
				}if(i == 1) 
					{
						printf("El hijo con id:%d, del padre con id:%d\n", getpid(), getppid());
				
						abrirGedit (argv);
						
						exit(EXIT_SUCCESS);
						
						
					}
				
	
			
			
			default:
				
				wait();
				
				printf("El padre con id:%d, del hijo con id:%d\n", getppid(), getpid());	
				
				break;
		
		}
	}

	return 0;
}

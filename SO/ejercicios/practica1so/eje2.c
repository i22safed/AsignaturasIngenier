#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t pid;
	
	int status;
	
	int i;
	
	int hijos;
	
	printf("Introduce el numero de hijos a crear:\n");
	scanf("%d", &hijos);
	
	for(i=0; i<hijos; i++)
	{
		pid=fork();
		
		switch(pid)
		{
			case -1:
				perror("Fork error\n");
				
				printf("errno value= %d\n", errno);
				break;
				
			case 0:
				sleep(10*i);
				printf("Proceso hijo:%d Proceso padre:%d\n", getpid(), getppid());
				break;
				
			default:
				sleep(3);
				printf("Padre:%d. El pid de mi hijo es %d\n", getpid(), pid);
				
				wait(&status);
				
				if(WIFEXITED(status)!=0)
				{	
					printf("Padre: mi hijo ha salido. Devuelve %d\n",WEXITSTATUS(status)); 
				}
				i=hijos;
						
		}
	
	
	
	}
	while(wait(&status)!=-1);
	

	return 0;




}

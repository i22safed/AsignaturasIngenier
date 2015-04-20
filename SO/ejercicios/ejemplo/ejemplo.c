#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char *argv[]) 
{

pid_t childpid = 0;
int i, n, j, valor, flag;

if (argc != 2)
{
  /* check for valid number of command-line arguments */
  printf("Usage: %s processes\n", argv[0]);
  exit(EXIT_FAILURE);
}

n = atoi(argv[1]);

for (i = 0; i <n; i++)
{
	childpid = fork();
	if (childpid == -1)
   {
    	perror("fork error");
		printf("errno value= %d\n", errno);  
		exit(EXIT_FAILURE);
   }
	else if(childpid == 0)//Estamos en alguno de los hijos
	{
		printf("process ID:%ld parent ID:%ld\n",(long)getpid(), (long)getppid());
		exit(EXIT_SUCCESS);
	}
   //En caso contrario el padre no hace nada, vuelve al for
}

/*Esperamos a los hijos*/
while ((flag = wait(&valor)) > 0)
{
	if (WIFEXITED(valor)) {
            printf("child exited, status=%d\n", WEXITSTATUS(valor));
        } else if (WIFSIGNALED(valor)) {
            printf("child killed (signal %d)\n", WTERMSIG(valor));
        } else if (WIFSTOPPED(valor)) {
            printf("child stopped (signal %d)\n", WSTOPSIG(valor));
		  }
}
if (flag==-1 && errno==ECHILD)
	printf("No hay más hijos que esperar\n");
else
{
	printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
	exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS); //return 0;
}


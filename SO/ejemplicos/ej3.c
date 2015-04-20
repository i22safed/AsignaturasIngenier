#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main ( )
{
	int i;
	int j;
	pid_t rf;
	rf = fork( );
	switch (rf)
	{
		case -1:
			perror("fork error");
			printf("errno value= %d\n", errno);
			break;
			
		case 0:
			i = 0;
			printf ("\nSoy el hijo, mi PID es %d y mi variable i(inicialmente a %d) 	es par", getpid( ),i);
	
			for ( j = 0; j < 5; j ++ )
			{
				i ++;
				i ++;
				printf ("\nSoy el hijo, mi variable i es %d", i);
			}
			break;
			
		default:
			i = 1;
			printf ("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) 	es impar", getpid(), i);
	
			for ( j = 0; j < 5; j ++ )
			{
				i++;
				i++;
				printf ("\nSoy el padre, mi variable i es %d", i);
			}
	}
		//Esta linea la ejecuta tanto el padre como el hijo
		printf ("\nFinal de ejecucion de %d \n", getpid());
	exit (0);
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct info{

	long *vector;
	long desde;
	long hasta;

};


void * hebras(void* arg);

long main(long argc, char* argv[]){

	if(argc!=2){
		printf("Error de argumentos: <ejecutable><numero de hilos menos de 10>");
		exit(-1);
	}	

	long vector[10];	
	long i,j, hebras, fail1=0, fail2=0;
	srand(time(NULL));
	void* resultado;
	long total;


	
	hebras = atoi(argv[1]);
	pthread_t th[hebras];
	

	for(i=0; i<10; i++){
		vector[i]= rand()%10;
		printf("< %ld >", vector[i]);
	}

	

	for(i=0; i<10; i++){


		fail1=pthread_create(th[i%hebras], NULL, (void*)hebras, (void*)&vector[i]);



		if(fail1!=0){
			perror("Error en el create\n");
			exit(-1);
		}

		if(i%hebras==0){

			for(j=0; j<hebras; i++){

				fail2 = pthread_join(th[i], (void**)&resultado);
				if(fail2!=0){
					perror("Error en el join\n");
					exit(-1);
				}
					printf("Suma de la hebra %ld: %ld", i+1,*(long*)resultado);
				total+=*(long*)resultado;

			}
		}	
	}

	for(i=0; i<10%hebras; i++){
		
				fail2 = pthread_join(th[i], (void**)&resultado);
				if(fail2!=0){
					perror("Error en el join\n");
					exit(-1);
				}
					printf("Suma de la hebra %ld: %ld", i+1,*(long*)resultado);
				total+=*(long*)resultado;

	}

	printf("Suma total: %ld",total);
	



	pthread_exit(NULL);
}

void * hebras(void* arg){
	
	long* num = (long*) malloc(sizeof(long));

	num=(long*)arg;

	pthread_exit((void*)num);
}

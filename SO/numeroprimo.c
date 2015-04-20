#include <stdio.h>

int main() {

int numero, i, contador;

printf("Introduzca un numero:\n");
scanf("%d",&numero);

for(i=1;i<=numero;i++) {
if(numero%i==0) {
	contador++;
	}
}

if(contador==2) {
printf("El numero es primo\n");
} else {
printf("El numero no es primo\n");
}

 return 0;
}

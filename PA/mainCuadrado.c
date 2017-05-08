#include <stdio.h>

int cuadrado(int n);

int main(int argc, char *argv[]){

	int a = 0;
	printf("dame un valor\n");
	scanf("%d", &a);
	printf("%d\n", cuadrado(a));
}

int cuadrado(int n){
	return n*n;
}



#include <stdio.h>

void map(){
char palabra[50];
  while(scanf("%s", palabra) != EOF) {
    printf("%s 1\n", palabra);
    
  }

}

void reduce(){
	int i =0;
	char line [128];
	char file [10][128];
	FILE *fp;

	fp = fopen("mapfruit.txt", "r");

	while (fgets(file[i], sizeof(file[i]), fp)){
	    i++;
	}

}


int main(){
  
map();
reduce();

}

//cat archivo.txt | ./map


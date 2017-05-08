#include <stdio.h>

void quality(double a, double b, double c){

  double tq= ((b + c - a) *(a + b - c) * (c + a - b)) / (a * b * c);

  if(tq==1){
    printf("Equilateral\n");
  }
  else if(tq > 0.5 && tq < 1){
    printf("Good\n");
  }else{
    printf("Bad\n");
  }

}

int main(){

  int intentos;
  scanf("%d\n", &intentos);
  double a[intentos];
  double b[intentos];
  double c[intentos];

      for (int i = 0; i < intentos; i++) {
          scanf("%lf %lf %lf \n",&a[i], &b[i] , &c[i]);
      }

	for (size_t i = 0; i < intentos; i++) {
	    quality(a[i], b[i], c[i]);
	}


  double resultado = 0;

}

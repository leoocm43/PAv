#include <stdio.h>


int residuo(int a, int b){

if(a<b)
  return a;
else
  return residuo(a-b,b);

}

int main(){
  int a, b;
  printf("Ingresa dos números seprados por un espacio para calcular el residuo\n ");
  scanf("%d %d", &a, &b);
  printf("residuo de dividir %d entre %d es %d\n", a, b, residuo(a, b));
}

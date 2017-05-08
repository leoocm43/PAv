#include <stdio.h>
#include <stdlib.h>

void pr1(int *a){
  *a = 10123;
}

void pr2(int** a){
  *a = (int*) malloc(sizeof(int) * 10);
  **a = 1;

}

int main(){
  int c[] = {5,3,2,10};
  int *a = c;
  printf("%d\n", a[0]);
  pr1(a);
  printf("%d\n", a[0]);
  pr2(&a);//direccion de la direccion, apuntador a un apuntador
printf("%d\n", a[0]);
  return 0;
}

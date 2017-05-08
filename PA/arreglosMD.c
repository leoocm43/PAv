#include <stdio.h>

//este método modifica la casilla de un arreglo
void modifica(int *arr, int columnas, int nuevoValor, int renglon, int columna){

  int casilla = renglon * columnas + columna;
arr[casilla] = nuevoValor;
//*arr + casilla) = nuevoValor;
//*(arr + 120) = 500;
printf ("tamano de int =  %lu\n", sizeof(int));

}

void modifica2(int arr [][3], int nuevoValor, int renglon, int columna){
arr[renglon][columna] = nuevoValor;

}

int main(){

  int arr[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  //int * arr2 = (int *) arr;
  //*(++arr2) = 21;
  printf("%d\n", arr[1][2]);
  modifica((int *)arr, 4, 100, 1, 2);
  printf("%d\n", arr[1][2]);
  modifica2((int (*)[3])arr, 150, 2, 0);
  printf("%d\n", arr[1][2]);


}

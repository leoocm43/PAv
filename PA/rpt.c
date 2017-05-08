#include <stdio.h>

/*int main(int argc, char *argv[]){//arreglo a traves de pointer
  printf("%s\n", argv[1];
}*/

int main(int argc, char **argv){
  //printf("%s\n", *(argv+1)); 
  char* juego2[][2][2][2] = {
        {
            {{"Armando","P"}, {"Dave","T"}},
            {{"Richard", "R"}, {"Michael", "T"}}
        },
        {
            {{"Allen", "T"}, {"Omer", "P"}},
            {{"David E.", "R"}, {"Richard X.", "P"}}
        }
    };
  
  printf("%s\n", juego2[1][0][0][0]);
  char** arr = (char**) juego2;//misma direccion de base donde esta el arreglo. Es un apuntador al apuntador char de juego2. como si tuviera un arr unidimensional a apuntadores a caracteres

  //char (*arr)[] = (char(*) []) juego2;
  //printf("%s\n", arr[8]);
  printf("Hola %s\n", *(arr + 0));
  printf("%s\n", *(arr + 1));
  printf("%s\n", *(arr + 2));
  printf("%s\n", *(arr + 3));
  printf("%s\n", *(arr + 8));

  return 0;
}


//funciones que uso en mi programa epro que no declaré, definidas en otro lado.--Link editor


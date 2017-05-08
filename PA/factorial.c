#include <stdio.h>

int factorial(int n){
  if (n == 0)
    return 1;
  else
  return n* factorial(n-1);

}

int factorial2(int n, int res){
  if(n == 0)
    return res;
  else
  return factorial2(n-1, res * n);
}

int main(int argc, char **argv[]){
  printf("%d\n", factorial(11));
  printf("%d\n", factorial2(11,1));
}

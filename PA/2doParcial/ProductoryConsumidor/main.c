#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define PRODUCTORES 3

char arr[1000];
int tamanio = sizeof(arr) / sizeof(int);
int pos = 0;
int ultima = 0;

void push(char c){
arr[pos] = c;
pos = (pos + 1) % tamanio;
}

char pop(){
 if(ultima != pos){
  char c = arr[ultima];
  ultima = (ultima + 1) % tamanio;
  return c;
 }
 return 0;
}


void* productor(void *arg){
 int id = *(int *) arg;
 for(int i =0; i< 10 ;i++){
  char c = (char) (random() % 32 +26);
  long espera = random();
  //usleep(espera);
  push(c);
  printf("produce %c el productor %dn", c, id);
 }
 return arg;
}

int main(){

  pthread_attr_t attr;
  //pthread_t thread;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  pthread_t productores[PRODUCTORES];

  for(int i =0; i < PRODUCTORES; i++){
   pthread_create(&productores[i], &attr, productor, (void *) &i);
   usleep(5);
  }
  sleep(10);
  return 0;
}

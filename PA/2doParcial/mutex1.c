#include <pthread.h>
#include <stdio.h>


int contador = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *hilo_productor(void *arg){

 printf("hilo productor\n");
 for(int i = 0; i <100 ; i++){
  pthread_mutex_lock(&mutex);
  contador++
  pthread_mutex_unlock(&mutex);
 }

  return NULL;
}

void *hilo_consumidor(void *arg){

 printf("hilo consumidor\n");
 for(int i = 0; i <100 ; i++){
  pthread_mutex_lock(&mutex);
  if(contador > 0)
    contador--;
  printf("del consumidor %d\n", contador);
  pthread_mutex_unlock(&mutex);
 }

  return NULL;
}

int main(){
 pthread_attr_t attr;
 pthread_attr_init(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 pthread_t consumidor, productor;
 int temp = pthread_create((&consumidor, &attr, hilo_consumidor, NULL);
 int temp1 = pthread_create(&productor, &attr, hilo_productor, NULL);
 pthread_join(productor, NULL);
 pthread_join(consumidor, NULL);
 return 0;

}

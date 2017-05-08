#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>

#define THREADS 5
#define MAX_ITER 5

sem_t *tenedor1;
sem_t *tenedor2;
sem_t *tenedor3;
sem_t *tenedor4;
sem_t *tenedor5;


typedef struct{
	char* nombre;
	sem_t *tenedorI;
	sem_t *tenedorD;
	int zurdo;
    
} filosofo;

void filosofar(filosofo* f);

void comer(filosofo* f){
  printf("%s va a comer\n", f->nombre);
  if(f->zurdo) {
    sem_wait(f->tenedorI);
    printf("%s tiene el tenedor izquierdo\n", f->nombre);
    sem_wait(f->tenedorD);
  } else {
    sem_wait(f->tenedorD);
    //sleep(1);
    printf("%s tiene el tenedor derecho\n", f->nombre);
    sem_wait(f->tenedorI);
  }
  printf("%s esta comiendo\n", f->nombre);
  //	sleep(5);
  sem_post(f->tenedorI);
  sem_post(f->tenedorD);
}

void filosofar(filosofo* f)
{
  printf("%s esta filosofando\n", f->nombre);
  //sleep(rand()%7);
}

void* th(void* arg)
{
  filosofo *f = (filosofo*) arg;
  int i;
  for (i = 0; i < MAX_ITER; i++) {
    comer(f);
    filosofar(f);
  }
  
  return arg;
  
}

//extern int errno;

int main()
{
  tenedor1 = sem_open("tenedor1", O_CREAT | O_EXCL ,S_IRWXU,1);
  tenedor2 = sem_open("tenedor2", O_CREAT | O_EXCL,S_IRWXU,1);
  tenedor3 = sem_open("tenedor3", O_CREAT | O_EXCL, S_IRWXU,1);
  tenedor4 = sem_open("tenedor4", O_CREAT | O_EXCL,S_IRWXU,1);
  tenedor5 = sem_open("tenedor5", O_CREAT | O_EXCL,S_IRWXU,1);
  if (errno !=0) {
    sem_close(tenedor1);
    sem_close(tenedor1);
    sem_close(tenedor1);
    sem_close(tenedor1);
    sem_close(tenedor1);
    sem_unlink("tenedor1");
    sem_unlink("tenedor2");
    sem_unlink("tenedor3");
    sem_unlink("tenedor4");
    sem_unlink("tenedor5");
    tenedor1 = sem_open("tenedor1", O_CREAT | O_EXCL ,S_IRWXU,1);
    tenedor2 = sem_open("tenedor2", O_CREAT | O_EXCL,S_IRWXU,1);
    tenedor3 = sem_open("tenedor3", O_CREAT | O_EXCL, S_IRWXU,1);
    tenedor4 = sem_open("tenedor4", O_CREAT | O_EXCL,S_IRWXU,1);
    tenedor5 = sem_open("tenedor5", O_CREAT | O_EXCL,S_IRWXU,1);
  }

  pthread_t threads[THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setscope( &attr, PTHREAD_SCOPE_SYSTEM);
  filosofo descartes;
  descartes.nombre = "descartes";
  descartes.tenedorD = tenedor1;
  descartes.tenedorI = tenedor2;
  descartes.zurdo = 0;
  filosofo socrates;
  socrates.nombre = "socrates";
  socrates.tenedorD = tenedor2;
  socrates.tenedorI = tenedor3;
  socrates.zurdo = 0;
  filosofo aristoteles;
  aristoteles.nombre = "aristoteles";
  aristoteles.tenedorD = tenedor3;
  aristoteles.tenedorI = tenedor4;
  aristoteles.zurdo = 0;
  filosofo arquimedes;
  arquimedes.nombre = "arquimedes";
  arquimedes.tenedorD = tenedor4;
  arquimedes.tenedorI = tenedor5;
  arquimedes.zurdo = 0;
  filosofo kant;
  kant.nombre = "kant";
  kant.tenedorD = tenedor5;
  kant.tenedorI = tenedor1;
  kant.zurdo = 0;
  
  printf("Se crean\n");
  pthread_create(&threads[0], &attr, th, (void*) &descartes);
  pthread_create(&threads[1], &attr, th, (void*) &socrates);
  pthread_create(&threads[2], &attr, th, (void*) &aristoteles);
  pthread_create(&threads[3], &attr, th, (void*) &arquimedes);
  pthread_create(&threads[4], &attr, th, (void*) &kant);
  
  int i = 0;
  for (i = 0; i < 5; i++)
    pthread_join(threads[i], NULL);
  sem_close(tenedor1);
  sem_close(tenedor1);
  sem_close(tenedor1);
  sem_close(tenedor1);
  sem_close(tenedor1);
  sem_unlink("tenedor1");
  sem_unlink("tenedor2");
  sem_unlink("tenedor3");
  sem_unlink("tenedor4");
  sem_unlink("tenedor5");
  
  return 0;
}

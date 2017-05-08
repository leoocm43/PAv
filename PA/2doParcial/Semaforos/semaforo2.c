#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
  // insert code here...
  sem_t *sem = sem_open("semaforo", O_CREAT, S_IRWXU, 1);
  sem_close(sem);
  sem_close(sem);
  sem_unlink("semaforo");
  return 0;
}

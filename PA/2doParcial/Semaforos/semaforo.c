#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <fcntl.h> 
#include <semaphore.h>

sem_t *sem;

int main(int argc, const char * argv[]) {
    // insert code here...
    sem = sem_open("semaforo", O_CREAT, S_IRWXU, 1);
    pid_t pid;
    
    if ((pid = fork()) != 0) {
        /* padre */
        int i;
        for (i = 0; i < 10; i++) {
            sem_wait(sem);
            printf("padre adquiere el semáforo y espera %d \n", i);
            sleep(1);
            sem_post(sem);
            sleep(1);
        }
        sem_close(sem);
        int estado;
        wait(&estado);
        sem_unlink("semaforo");
    }
    else {
        /* hijo */
        int i;
	sleep(1);
        for (i = 0; i < 10; i++) {
            sem_wait(sem);
            printf("hijo adquiere el semáforo y espera tecla\n");
	    char msg[20];
	    fgets(msg, 20, stdin);
            sem_post(sem);
            sleep(1);
        }
        sem_close(sem);
        
    }
    
    return 0;
}

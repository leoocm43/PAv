#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#define SILLAS 2
#define PELUQEROS 1
#define MAX_ITER 10

extern int errno;

sem_t *sem_peluqueria_no_llena;
sem_t *sem_peluqueria_no_vacia;
sem_t *sem_peluquero;
sem_t *sem_peluqero_termino;

/* para memmoria compartida */
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define KEY 1234

typedef struct cliente {
    int no_cliente;
    pid_t pid;
    
} cliente;
int shmid;

void * nuevo_cliente(void *args)
{
    cliente* cl_listo ;
    if ((cl_listo = shmat(shmid, NULL, 0)) == (cliente *) -1) {
        perror("error en productor en shmat");
        exit(0);
    }
    printf("cl_listo %p\n", cl_listo);
    cliente *cl = (cliente*) args;
    printf("El cliente %d entra a la peluquería\n", cl->no_cliente);
    if (!sem_trywait(sem_peluqueria_no_llena)) {
        printf("El cliente %d espera su turno\n", cl->no_cliente);
        sem_wait(sem_peluquero);
        cl_listo->no_cliente = cl->no_cliente;
        sem_post(sem_peluqueria_no_vacia);
        printf("El cliente %d lo están peluqueando\n", cl->no_cliente);
        sem_wait(sem_peluqero_termino);
        printf("El cliente %d abandona la peluquería con su nuevo look\n", cl->no_cliente);
    }
    else
        printf("El cliente %d no encontró lugar\n", cl->no_cliente);
    return args;
}

void * peluquero(void *args)
{
    cliente* cl_listo ;
    if ((cl_listo = shmat(shmid, NULL, 0)) == (cliente *) -1) {
        perror("error en productor en shmat");
        exit(0);
    }
    printf("cl_listo %p\n", cl_listo);
    do {
        printf("El peluquero está durmiendo y listo para el siguiente cliente\n");
        sem_post(sem_peluquero);
        sem_wait(sem_peluqueria_no_vacia);
        sem_post(sem_peluqueria_no_llena);
        printf("El peluquero está peluqueando al cliente %d\n", cl_listo->no_cliente);
        sleep(5 + rand()%4);
        printf("El peluquero termino de peluquear al cliente % d\n", cl_listo->no_cliente );
        sem_post(sem_peluqero_termino);
    } while (1);
    return args;
}
void libera() {
    
    sem_close(sem_peluqueria_no_vacia);
    sem_close(sem_peluquero);
    sem_close(sem_peluqero_termino);
    sem_unlink("sem_peluqueria_no_llena");
    sem_unlink("sem_peluqueria_no_vacia");
    sem_unlink("sem_peluquero");
    sem_unlink("sem_peluqero_termino");
}

int main()
{
    if (( shmid = shmget(KEY, sizeof(cliente), IPC_CREAT | S_IRWXU)) < 0 ) {
        perror("Error en creacion al shmget");
        exit(0);
    }

    srand((unsigned)time(NULL));
    pid_t ptid;
    libera();
    sem_peluqueria_no_llena = sem_open("sem_peluqueria_no_llena", O_CREAT,S_IRWXU,SILLAS);
    sem_peluqueria_no_vacia = sem_open("sem_peluqueria_no_vacia", O_CREAT,S_IRWXU,0);
    sem_peluquero = sem_open("sem_peluquero", O_CREAT,S_IRWXU,0);
    sem_peluqero_termino = sem_open("sem_peluqero_termino", O_CREAT,S_IRWXU,0);
    
    if( (ptid = fork()) == 0)
       //pthread_create(&ptid, NULL,peluquero, NULL))
    {
        peluquero(NULL);
    }
    
    /* Creando los procesos clientes */
    
    cliente clientes[MAX_ITER];
    int i;
    for (i = 0; i < MAX_ITER; i++) {
        clientes[i].no_cliente = i + 1;
        
        if((clientes[i].pid = fork()) == 0 ) {
            nuevo_cliente(&clientes[i]);
            exit(0);
        }
       
        sleep(1 + rand()%5);
    }
    
    for (i = 0; i < MAX_ITER; i++) {
        int estado;
        waitpid(clientes[i].pid, &estado, 0);
    }
    kill(ptid, SIGKILL);
    struct shmid_ds shmid_ds1;
    if (shmctl(shmid, IPC_RMID, &shmid_ds1) < 0) {
        perror("Error en padre al ejecutar shmctl al eliminar el segmento de memoria compartida");
    }
    printf("El peluquero está cerrando el changarro\n");
    libera();
    return 0;
}

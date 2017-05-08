#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <unistd.h>

#define SILLAS 2
#define PELUQEROS 1
#define MAX_ITER 10

extern int errno;

sem_t *sem_peluqueria_no_llena;
sem_t *sem_peluqueria_no_vacia;
sem_t *sem_peluquero;
sem_t *sem_peluqero_termino;

typedef struct cliente {
    int no_cliente;
    pthread_t thread;
    
} cliente;

cliente* cl_listo = NULL;

void * nuevo_cliente(void *args)
{
    cliente *cl = (cliente*) args;
    printf("El cliente %d entra a la peluquería\n", cl->no_cliente);
    if (!sem_trywait(sem_peluqueria_no_llena)) {
        printf("El cliente %d espera su turno\n", cl->no_cliente);
        sem_wait(sem_peluquero);
        cl_listo = cl;
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
    do {
        printf("El peluquero está durmiendo y listo para el siguiente cliente\n");
        sem_post(sem_peluquero);
        sem_wait(sem_peluqueria_no_vacia);
        sem_post(sem_peluqueria_no_llena);
        printf("El peluquero está peluqueando al cliente %d\n", cl_listo->no_cliente);
        sleep(3 + rand()%4);
        printf("El peluquero termino de peluquear al cliente %d\n", cl_listo->no_cliente);
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
    srand((unsigned)time(NULL));
    pthread_t ptid;
    libera();
    sem_peluqueria_no_llena = sem_open("sem_peluqueria_no_llena", O_CREAT,S_IRWXU,SILLAS);
    sem_peluqueria_no_vacia = sem_open("sem_peluqueria_no_vacia", O_CREAT,S_IRWXU,0);
    sem_peluquero = sem_open("sem_peluquero", O_CREAT,S_IRWXU,0);
    sem_peluqero_termino = sem_open("sem_peluqero_termino", O_CREAT,S_IRWXU,0);
    
    if(pthread_create(&ptid, NULL,peluquero, NULL))
    {
        printf("\n ERROR creando thread peluquero\n");
        exit(1);
    }
    
    /* Creando los threads clientes */
    
    cliente clientes[MAX_ITER];
    int i;
    for (i = 0; i < MAX_ITER; i++) {
        clientes[i].no_cliente = i + 1;
        if(pthread_create(&clientes[i].thread, NULL,nuevo_cliente,&clientes[i]))
        {
            printf("\n ERROR creando thread cliente %d\n", i+1);
            exit(1);
        }
        sleep(1 + rand()%5);
    }
    
    for (i = 0; i < MAX_ITER; i++) {
        if(pthread_join(clientes[i].thread, NULL))
        {
            printf("\n ERROR joining thread");
            exit(1);
        }
    }
    
    /*if(pthread_join(ptid, NULL))
     {
     printf("\n ERROR joining thread");
     exit(1);
     }
     */
    pthread_cancel(ptid);
    printf("El peluquero está cerrando el changarro\n");
    libera();
    return 0;
}

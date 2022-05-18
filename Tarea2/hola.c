#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <queue>

int counter;
pthread_mutex_t lock;

void* funcionThread(void *arg)
{
    pthread_mutex_lock(&lock);
    unsigned long i = 0;
    counter += 1;
    printf("\n Inicia job %d \n", counter);
    for(i=0; i<(0xFFFFFFF);i++);
    printf("\n Termina job %d \n", counter);
    for(i=0; i<(0xFFFFFFF);i++);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int transformacion(int dia, int hora){
    int limittime = dia*24 + hora;
    return limittime;
}

int main(void)
{
    int i = 0;
    int k;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n Falla inicializacion de mutex \n");
        return 1;
    }
    printf("Ingrese la cantidad de asignaturas para las que debe estudiar \n");
    scanf("%d",&k);
    pthread_t tid[k];
    int burst[k], limitday[k], limithour[k], deadline[k];

    for(int j = 0; j < k; j++){
        printf("Ingrese la duracion total del estudio semanal de la asignatura Nro: %d\n",(j+1));
        scanf("%d",&burst[j]);
        printf("Ingrese el dia limite de tiempo (0 - 6) \n");
        scanf("%d",&limitday[j] + 1);
        printf("Ingrese la hora limite de termino (0 - 23) \n");
        scanf("%d",&limithour[j] + 1);
        deadline[j] = transformacion(limitday[j], limithour[j]);
    }
    for(int l = 0; l < k; l++){
        printf("CPUburst %d Dia %d Hora %d Tiempo %d \n", burst[l], limitday[l], limithour[l], deadline[l]);
    }

    while(i < k) // Creacion de Threads
    {
        err = pthread_create(&(tid[i]), NULL, &funcionThread, NULL);
        if (err != 0){
            printf("\nNo se puede crear el thread :[%s]", strerror(err));
        }
        i++;
    }
    
    for(int j = 0; j < k; j++){
        pthread_join(tid[j], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    return 0;
}
#include <iostream>
#include <queue>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <queue>

using namespace std;

class Asignatura {

public:
    int id;
	int burst;
    int limitday;
    int limithour;
    int deadline;
	Asignatura(int burst, int limitday, int limithour, int deadline, int id)
		: burst(burst), limitday(limitday), limithour(limithour), deadline(deadline), id(id)
	{
	}
};

bool operator<(const Asignatura& a1, const Asignatura& a2)
{
	return a1.deadline < a2.deadline;
}
int transformacion(int dia, int hora){
    int limittime = dia*24 + hora;
    return limittime;
}

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

int main(){

	priority_queue<Asignatura> A;
    int i = 0;
    int k;

    printf("Ingrese la cantidad de asignaturas para las que debe estudiar \n");
    scanf("%d",&k);
    pthread_t tid[k];
    int burst[k], limitday[k], limithour[k], deadline[k];

    for(int j = 0; j < k; j++){
        printf("Ingrese la duracion total del estudio semanal de la asignatura Nro: %d\n",(j+1));
        scanf("%d",&burst[j]);
        printf("Ingrese el dia limite de tiempo (0 - 6) \n");
        scanf("%d",&limitday[j]);
        printf("Ingrese la hora limite de termino (0 - 23) \n");
        scanf("%d",&limithour[j]);
        deadline[j] = transformacion(limitday[j], limithour[j]);
        A.push(Asignatura(burst[j], limitday[j], limithour[j], deadline[j], j+1));
    }


	while (!A.empty()) {

		Asignatura a = A.top();

		A.pop();
    
		cout << "Asignatura Nro: "<<a.id << " Burst: " <<  a.burst <<" Deadline: "<< a.deadline << "\n";
	}
	return 0;
}

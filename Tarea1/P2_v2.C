#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

int numRandom(int a){
    int b;
    srand(time(0));
    b = rand() % 4;
    return b;
}

int main(void) {

    pid_t pid;
    int n;
    scanf("%d",&n);
    int n2 = numRandom(n); //Zulensky
    // int n2 = 13; //Zulensky
    // printf("%d\n",n2);
    int hijos[n];
    int me = getpid();

    for(int i = 0; i < n; i++){ //Creacion hijos
        pid = fork();
        if(pid == 0){
            break;
        }
        else if(pid != 0){
             hijos[i] = pid;
             printf("Hijo Nro %d -> ID: %d\n", hijos[i]-me,hijos[i]);
        }
    }

    while(1){
        int UbiRand = rand() % n;
        if(pid != 0){
             if(n2 == UbiRand){
                printf("Visito al hijo: %d\n", UbiRand + 1);
                printf("Zulensky esta en el hijo: %d\n", hijos[UbiRand]);
                kill(hijos[UbiRand], 0);
                break;
             }
             else{
                 printf("Visito al hijo: %d\n", UbiRand + 1);
                 printf("Zulensky no esta en el hijo: %d  MUERE\n", hijos[UbiRand]);
                 kill(hijos[UbiRand], 0);
                 hijos[UbiRand] = fork();
             }

        }
        
        if(getpid() != me){ // Hijos vivos
            exit(0);
        }
        
    }
    printf("Genocidio completado \nhttps://www.youtube.com/watch?v=Wl959QnD3lM&ab_channel=lerrific \n");
    
    return 0;
}

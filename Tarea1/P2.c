#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

int numRandom(int a){
    int b;
    srand(a);
    b = rand() % 4;
    return b;
}

int main(void) {

    pid_t pid;
    int n;
    scanf("%d",&n);
    // int n2 = numRandom(n); //Zulensky
    int n2 = 13; //Zulensky
    printf("%d\n",n2);
    int hijos[n];
    int me = getpid();

    for(int i = 0; i < n; i++){
        pid = fork();
        if(pid == 0){
            break;
        }

        if(pid != 0){
            if((pid - me) == n2){
                printf("Encontre a Zulensky en el hijo %d\n",(pid- me));
                break;
            }
            else{
                printf("Zulensky no esta en el hijo %d\n", (pid- me));
                kill(pid,0);
            }
            // hijos[i] = pid;
        }
        


    }
    
    return 0;
}

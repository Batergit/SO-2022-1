#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

    int fd[2];
    int fd2[2];

int hijo(int padre, int fd[2]){

    char input_str[100];

    pid_t pid = fork();
    if(pid == 0){
        if(getppid() != padre){exit(0);}
        else{
        while(1){
            printf("Ingrese su jugada: \n");
            scanf("%s", input_str);
            write(fd[1], input_str, strlen(input_str)+1);
        }
        return getpid();
        } 
    }
    
}

int desicion(char j1[100], char j2[100]){
    printf("Jugada 1: %s\nJugada 2: %s\n",j1,j2);
    int win;
    if(strcmp(j1,"piedra") == 0 && strcmp(j2,"tijeras") == 0){return 0;}

    else if(strcmp(j1,"piedra") == 0 && strcmp(j2,"papel") == 0){return 1;}

    else if(strcmp(j1,"tijeras") == 0 && strcmp(j2,"papel") == 0){return 0;}

    else if(strcmp(j1,"tijeras") == 0 && strcmp(j2,"piedra") == 0){return 1;}

    else if(strcmp(j1,"papel") == 0 && strcmp(j2,"piedra") == 0){return 0;}

    else if(strcmp(j1,"papel") == 0 && strcmp(j2,"tijeras") == 0){return 1;}
    
    else if(strcmp(j1,j2) == 0){return 2;}

}

int main(void) {
    
    char jugada1[100];
    char jugada2[100];
    
    int hijos[2];
    pipe(fd);
    pipe(fd2);
    int me = getpid();
    int ganador = 0;
    hijos[0] = hijo(me, fd);
    hijos[1] = hijo(me, fd2);


    //Juego
  if(getpid() == me){
    while(1){
        
        printf("\nSoy el arbitro\n");
        printf("El padre lee las jugadas [piedra, papel o tijeras]...\n");
        
        read(fd[0], jugada1, 100);
        printf("Jugada Hijo %d: %s\n", hijos[0], jugada1);
        
        read(fd2[0], jugada2, 100);
        printf("Jugada Hijo %d: %s\n", hijos[1] ,jugada2);

        sleep(1);
        ganador = desicion(jugada1,jugada2);
        if(ganador == 2){printf("EMPATE\n");}

        else if(ganador == 0){
            printf("El ganador es el Hijo: %d\n",hijos[0]);
            kill(hijos[1],0);
            hijos[1] = hijo(me, fd);
        }
        else if(ganador == 1){
            printf("El ganador es el Hijo: %d\n",hijos[1]);
            kill(hijos[0],0);
            hijos[0] = hijo(me, fd2);
        }
      }
  }
                          

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char* spliting(char* astr){
        printf("splitting");
}

int main() {   
    char cmd[40];

    //version 1 -- no argument
    //char arg[40];

    while(1) {
        printf(">>");
        scanf("%s",cmd);
        if(strcmp(cmd,"quit")==0){
            exit(0);
        }
        else{
            int pid = fork();
            switch (pid) {
                case 0:
                    execlp(cmd, cmd, NULL);
                default:
                    waitpid(pid, NULL, 0);
                    //printf("This is parent\n");
            }
        }

    }
}

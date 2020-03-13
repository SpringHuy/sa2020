#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

char cmd[100];
int pid;


char* spliting(char* astr){
        printf("splitting");
}

void handler(int signal_num) {
    printf("Signal %d => ", signal_num);
    switch (signal_num) {
        case SIGTSTP:
            printf("terminate child\n");
            kill(pid, SIGTERM);
            exit(0);
        default:
            printf("Signal handler\n");
    }
}

int main() {   
    // ctrl z
    signal(SIGTSTP, handler);

    //version 1 -- no argument
    //char arg[40];

    while(1) {
        printf(">>");
        scanf("%s",cmd);
        if(strcmp(cmd,"quit")==0){
            exit(0);
        }
        else{            
            switch (pid = fork()) {
                case 0:
                    execlp(cmd, cmd, NULL);
                default:
                    waitpid(pid, NULL, 0);
                    printf("This is parent\n");
            }
        }

    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int n) {
    pid_t pid;
    pid = fork();
    for(int i=0; i<n;n++){
        if(pid==0){
            printf("Hello from child [%d - %d]\n", pid, i);
        }
        else if(pid<=-1){
            return 1;
        } else printf("Hello from parent [%d - %d]\n", pid, i);
    }
    printf("\n");
    return 0;
}

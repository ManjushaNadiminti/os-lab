#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 

int main() {
    pid_t pid, pid1, pid2;

    pid = fork();  
    if (pid == -1) {
        printf("Error in process creation\n");
        exit(1);
    }

    if (pid != 0) {  
        pid1 = getpid();
        printf("\nThe parent process ID is %d\n", pid1);
    } else { 
        pid2 = getpid();
        printf("\nThe child process ID is %d\n", pid2);
    }

    return 0;
}

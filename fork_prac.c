#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == 0){
        printf("The process id of the child process is: %d\n ", getpid());
    }
    else if (child_pid > 0){
        printf("The process id of the parent process is: %d\n  The process id of the child process is: %d\n ", getpid(), child_pid);
    }
    else{
        perror("Fork failed");
    }

    return 0;
}
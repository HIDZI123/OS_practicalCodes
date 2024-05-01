#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t child_process;

    child_process = fork();

    if(child_process == 0){
        printf("The process id of the child process is: %d", getpid());
    }
    if (child_process > 0){
        printf("The process id of the child process is: %d\n  The process id of the parent process is: %d\n", child_process,getpid());
    }
    else{
        perror("The fork failed");
    }
    return 0;
}
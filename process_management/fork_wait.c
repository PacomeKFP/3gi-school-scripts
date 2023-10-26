#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", getppid());
    if(fork() == 0)
        printf("HC: hello from child %d\n", getpid());
    else{
        printf("HP: Hello from parent by child, %d\n", getpid());
        wait(NULL); //we can comment this line
        printf("CT: Child has terminated %d\n", getpid());
    }
    printf("Bye %d\n", getpid());
    return 0;
}

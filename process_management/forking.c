#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    printf("Hello guys %d\n", getpid());
    if (pid == -1)
    {
        fprintf(stderr, "Fork failed\n");
        exit(-1);
    }
    if (pid == 0)
    {
        printf("I'm the parent %d\n", getpid());
        exit(0);
    }
    if (pid > 0)
    {
        pid_t pidd = fork();
        if (pidd == -1)
            fprintf(stderr, "Fork failed\n");
        if (pidd > 0)
            printf("Je suis le petit fils %d\n", pidd);
        printf("I'm the child , my pid is %d\n", pid);
        exit(0);
    }
    printf("Yo %d\n", getpid());
    return 0;
}

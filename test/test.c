#include "header.h"

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid < 0)
        printf("Fork error");
    if (pid == 0)
    {
        execl("/usr/bin/gedit", "/usr/bin/gedit", "file");
        clrscr();
    }
    if (pid > 0)
    {
        string val = (string)malloc(sizeof(char));
        printf("yo");
        scanf("%s", val);
        printf("%s", val);
    }

    return 0;
}

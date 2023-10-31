#include "header.h"

void run_command(string *command)
{

    printf("running command: %s\n", command[0]);
    if (strcmp(command[0], "echo") == 0)
        echo(command);

    else if (strcmp(command[0], "clear") == 0)
        system("clear");

    else if (strcmp(command[0], "cat") == 0)
        cat(command);

    else if (strcmp(command[0], "exit") == 0)
    {
        printf("Exiting...\n");
        exit(0);
    }

    else
        printf("This command does not exist\n");
}
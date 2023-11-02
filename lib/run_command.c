#include "header.h"

void run_command(string command)
{
    if (n_compare(command, "echo"))
        echo(command + 5);

    else if (n_compare(command, "clear"))
        clear();

    else if (n_compare(command, "cat"))
        cat(command);

    else if (n_compare(command, "ps"))
        ps();

    else if (n_compare(command, "exit"))
        close_shell();
    else
        call_extern(command, false);
}
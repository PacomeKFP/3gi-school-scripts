#include "header.h"

void echo(string str)
{
    printf("%s\n", str);
}
void close_shell()
{
    printf("Exiting...\n");
    exit(0);
}
void clear()
{
    system("clear");
}
void cat(string file_path)
{
    if (strlen(file_path) < 5 || !FILE_EXISTS(file_path, F_OK))
    {
        printf("This file_path does not exist.\n");
        return;
    }
    file_path += 4;
    FILE *file = fopen(file_path, "r");
    // TODO print the file content
    while (!feof(file))
    {
        char c = fgetc(file);
        printf("%c", c);
    }
    printf("\n");
    fclose(file);
}
/**
 * Calls an external command. This can be managed using the system function or not.
 * Then we let the opportunity to the user to choose if the command should be executed using the system function or not
 *
 * @param command The command to be executed.
 * @param system_managed Flag indicating if the command should be executed using the system function.
 */
void call_extern(string command, bool system_managed)
{
    // Check if the command should be executed using the system function
    if (system_managed)
    {
        echo("Executing command from system\n");
        system(command);
        return;
    }

    printf("the command is %s\n", command);
    // extract the path to the binary matching with the command
    bool launch_as_background_task = command[strlen(command) - 1] == '&';
    string binary_path = strtok(command, " ");

    // TODO: Analyse the command to extract the bin path and all the args

    printf("the binary path[%d - %c]: %s\n", launch_as_background_task, command[strlen(command) - 1], binary_path);

    // check if the binary really exists
    if (!file_exists(binary_path))
    {
        printf("This command does not exist.\n");
        return;
    }

    //--> The binary exist, we can launch it bu before, create the list of process childs to manage them
    pid_t pid = fork();
    int status;

    if (pid < 0)
    {
        printf("Failed to launch the command. Try again later....\n");
        return;
    }
    if (pid == 0) // Child process point of view
    {
        // TODO: Launch the command with args after extracting them from the command
        execl(binary_path, binary_path, (char *)NULL);
    }
    if (pid > 0) // Parent process point of view
    {
        // add the process to the list of running process
        // INIT_CHILD_PROCESS(pid, command, child_process);
        // add_process(child_process);

        // Launch process in foreground (blocking the parent) if necessary
        if (!launch_as_background_task)
            waitpid(pid, &status, WUNTRACED);

        

        return;
    }
}



void ps(){

}

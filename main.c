#include "header.h"

int main(int argc, char const *argv[])
{
    string command;
    string input = (string)malloc(sizeof(char));
    while (1)
    {
        command = (string)malloc(sizeof(char));
        printf(">> ");
        scanf(SCAN_STR_REG, input);
        trim(input, command);
        clear_buffer();
        run_command(command);
        free(command);
    }

    return 0;
}

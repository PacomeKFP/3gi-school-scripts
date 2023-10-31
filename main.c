#include "header.h"

int main(int argc, char const *argv[])
{
    string *command, input, temp;
    do
    {
        command = (string *)malloc(sizeof(string));
        input = (string)malloc(sizeof(char));
        temp = (string)malloc(sizeof(char));
        printf(">> ");
        fgets(input, 100, stdin);
        trim(input, temp);
        split(temp, command, ' ');

        run_command(command);

        free(command);
        free(input);
        free(temp);

    } while (1);

    return 0;
}
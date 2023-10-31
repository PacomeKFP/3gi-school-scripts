#include "header.h"
void splits(string str, string *result, char separator)
{
    char *token = strtok(str, &separator);
    while (token != NULL)
    {
        printf("%d ", size_of_string_list(result));
        result[size_of_string_list(result)] = token;
        token = strtok(NULL, &separator);
    }
}

int main(void)
{
    string *command;
    char *str = (string)malloc(sizeof(char));
    while (1)
    {
        printf(">> ");
        scanf(SCAN_STR_REG, str);
        command = (string *)malloc(sizeof(string));
        splits(str, command, ' ');
        run_command(command);
        clear_buffer();
    }

    return 0;
}

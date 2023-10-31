#include "header.h"

void echo(string *command)
{
    string str = (string)malloc(sizeof(char));
    for (int i = 1; i < size_of_string_list(command); i++)
        strcat(str, command[i]);

    printf("%s\n", str);
    return;
}
void cat(string *command)
{
    FILE *f = fopen(command[1], "r");
    // TODO print the file content
    while (!feof(f))
    {
        char c = fgetc(f);
        printf("%c", c);
    }
    fclose(f);
    return;
}
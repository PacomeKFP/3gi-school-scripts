#include "header.h"

bool n_compare(string str1, string str2)
{
    if (strlen(str1) < strlen(str2))
        return false;
    return strncmp(str1, str2, strlen(str2)) == 0;
}


bool file_exists(string file_path)
{
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
        return false;

    fclose(file);
    return true;
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void trim(string str, string result)
{
    int start = 0, end = strlen(str) - 1;
    while (start < end && str[start] == ' ')
        start++;

    while (end > start && str[end] == ' ')
        end--;

    for (int i = start; i <= end; i++)
        result[i - start] = str[i];
}
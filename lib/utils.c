#include "header.h"

int size_of_string_list(string *string_list)
{
    int size = 0;
    while (string_list[size++])
        ;
    return --size;
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void merge_strings(string *string_list, string result)
{
    for (int i = 0; i < size_of_string_list(string_list); i++)
        strcat(result + strlen(result), string_list[i]);
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
void split(string str, string *result, char separator)
{
    char *token = strtok(str, &separator);
    while (token != NULL)
    {
        result[size_of_string_list(result)] = (string)malloc(sizeof(char));
        strcpy(result[size_of_string_list(result)], token);
        token = strtok(NULL, &separator);
    }
}
bool str_equal(string str1, string str2)
{
    int size = strlen(str1);
    if (size != strlen(str2))
        return false;
    for (int i = 0; i < size; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}
void spliter(string str, string *result, char separator)
{
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        int size = size_of_string_list(result);
        if (str[i] == separator)
        {
            result[size] = (string)malloc(sizeof(char));
            j = 0;
        }
        else if (i == 0)
            *(result + size) = (string)malloc(sizeof(char));
        else
            *(*(result + size) + strlen(*(result + size))) = *(str + i);
    }
}
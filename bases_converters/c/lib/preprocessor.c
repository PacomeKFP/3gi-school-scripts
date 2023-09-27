#include <header.h>

void str_to_number_list(char *str, int *numbers, char *separator, int *size)
{
    *size = 0;
    char *token = strtok(str, separator);
    while (token != NULL)
    {
        numbers[*size] = atoi(token);
        printf("%d", numbers[*size]);
        token = strtok(NULL, separator);
        *size += 1;
    }
    if (*size == -1)
        *size = 0;
}
void check_number_validity(int * initial_number, int number_len, int initial_base){
    for(int index = 0;)
}


void display_list_content(int *list, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %d ", list[i]);

    printf("]");
}
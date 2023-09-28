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
Bool check_number_validity(int *initial_number, int number_len, int initial_base)
{
    for (int index = 0; index < number_len; index++)
    {
        if (initial_number[index] >= initial_base)
        {
            printf("[❌] Desolé le nombre que vous avez entré n'est pas valide dans cette base");
            return false;
        }
    }
    printf("[✅] Le nombre est bien valide dans la base entrée");
    return true;
}

void display_list_content(int *list, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %d ", list[i]);

    printf("]\n");
}

void duplicate_number(int *original_number, int *number_copy, int number_len)
{
    for (int index = 0; index < number_len; index++)
        number_copy[index] = original_number[index];
}
void push_front(int *number, int *len, int new_element)
{
    int temp = number[0];
    int save;
    for (int i = 1; i < *len + 1; i++)
    {
        save = number[i];
        number[i] = temp;
        temp = save;
    }
    number[0] = new_element;
    (*len)++;
}
Bool verify_conversion(int *initial_number, int initial_number_len, int initial_base, int *final_number, int final_number_len, int final_base)
{
    //convert the initial number in base 10

    //convert the final number in base 10


    //compare the results
    return true;
}

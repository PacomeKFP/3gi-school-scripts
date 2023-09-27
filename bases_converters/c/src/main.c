#include "header.h"

int main(int argc, char const *argv[])
{
    char *separator = "-+*/";
    int *initial_number =(int*) malloc(sizeof(int));
    int initial_base = 10;
    int final_base = 2;
    int number_len = 0;
    char *input = (char *)malloc(MAX_NUMBER_LEN * 2 * sizeof(char));
    printf("Veuillez entrer le nombre dans votre base (separatuer de chiffres: %s )\n", separator);
    scanf("%s", input);
    printf("Veuillez entrer la base initiale\n", separator);
    scanf("%d", initial_base);
    printf("Veuillez entrer la base finale\n", separator);
    scanf("%s", final_base);
    // TODO process the input and transform it into a list of numbers
    str_to_number_list(input, initial_number, separator, &number_len);
    // TODO check if the number is valid
    check_number_validity(initial_number, initial_base);

    for (int i = 0; i < number_len; i++){
        printf(" %d ", initial_number[i]);
    }
    display_list_content(initial_number, number_len);

    return 0;
}

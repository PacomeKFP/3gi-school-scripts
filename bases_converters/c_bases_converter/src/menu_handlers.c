#include "header.h"

typedef enum
{
    WEAK,
    MEDIUM,
    HARD
} ConvertionType;

void get_data(string info, string number_example, int *initial_base, array initial_number, int *final_base, ConvertionType type)
{
    string number;
    Bool exist_in_base = true;
    printf("Veuillez entrer la base de depart: ");
    scanf("%d", initial_base);
    do
    {
        if (!exist_in_base)
            printf("Le nombre que vous avez entré n'est pas valide dans la base choisie\nVerifiez à nouveau la descriptions des nombres de cette base suivant le type de conversion que vous avez choisi au menu principal.\n Exemple: %s\n Essayez à nouveau.", number_example);

        printf("Veuillez entrer le nombre que vous souhaitez convertir: ");
        scanf("%s", number);
        str_to_number_list(number, initial_number)
        check_number_validity(initial_number);
    } while (!exist_in_base);

    printf("Veuillez entrer la base de finale: ");
    scanf("%d", final_base);
}
void weak_conversion_handler()
{
}
void medium_conversion_handler() {}
void hard_conversion_handler() {}
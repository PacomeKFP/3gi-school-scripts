#include "header.h"

void get_data(string info, string number_example, int *initial_base, array initial_number, int *final_base, int *intitial_number_len, ConversionType conversion_type)
{
    INIT_SEPARATOR(separator);
    string number = (string)malloc(sizeof(char));
    Bool exist_in_base = true;
    printf("Veuillez entrer la base de depart: ");
    scanf("%d", initial_base);
    do
    {
        if (!exist_in_base)
            printf("\nLe nombre que vous avez entre n'est pas valide dans la base choisie.\nVerifiez a nouveau la descriptions des nombres de cette base suivant le type de conversion que vous avez choisi au menu principal.\n Exemple: %s\n\nEssayez a nouveau. ", number_example);

        printf("\nVeuillez entrer le nombre que vous souhaitez convertir: ");
        scanf("%s", number);
        str_to_number_list(number, initial_number, separator, intitial_number_len, conversion_type);
        exist_in_base = check_number_validity(initial_number, *intitial_number_len, *initial_base);
    } while (!exist_in_base);

    printf("Veuillez entrer la base de finale: ");
    scanf("%d", final_base);
}
void weak_conversion_handler()
{
    string info, number_example = "5AEf8 (base 16) ici F et f valent la meme chose";
    array initial_number = (int *)malloc(sizeof(int)), final_number = (int *)malloc(sizeof(int));
    int initial_base, final_base, initial_number_len, final_number_len;
    get_data(info, number_example, &initial_base, initial_number, &final_base, &initial_number_len, WEAK_CONVERSION);

    convert_to_base(initial_number, initial_number_len, initial_base, final_number, &final_number_len, final_base);

    string result = (string)malloc(sizeof(char));
    number_list_to_str(final_number, final_number_len, result);
    printf("Le resultat est %s", result);
}
void medium_conversion_handler()
{

    string info, number_example = "5AEfX8e (base 52) -- les miniscules et majuscules sont non confondues";
    array initial_number = (int *)malloc(sizeof(int)), final_number = (int *)malloc(sizeof(int));
    int initial_base, final_base, initial_number_len, final_number_len;
    get_data(info, number_example, &initial_base, initial_number, &final_base, &initial_number_len, MEDIUM_CONVERSION);

    convert_to_base(initial_number, initial_number_len, initial_base, final_number, &final_number_len, final_base);

    string result = (string)malloc(sizeof(char));
    number_list_to_str(final_number, final_number_len, result);
    printf("Le resultat est %s", result);
}
void hard_conversion_handler()
{

    string info, number_example = "78-56-23-12-46 (base 80)";
    array initial_number = (int *)malloc(sizeof(int)), final_number = (int *)malloc(sizeof(int));
    int initial_base, final_base, initial_number_len, final_number_len;
    get_data(info, number_example, &initial_base, initial_number, &final_base, &initial_number_len, HARD_CONVERSION);

    convert_to_base(initial_number, initial_number_len, initial_base, final_number, &final_number_len, final_base);

    string result = (string)malloc(sizeof(char));
    number_list_to_str(final_number, final_number_len, result);
    printf("Le resultat est %s", result);
}
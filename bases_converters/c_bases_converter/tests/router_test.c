#include "header.h"

void hello()
{
    printf("Yo");
}
int main(int argc, char const *argv[])
{
    INIT_MENU(menu);
    MenuOption *options;

    MenuOption weak_conversion;
    weak_conversion.label = "Faire une conversion avec des petites bases ( <=36 )";
    weak_conversion.description = "Il s'agit d'une conversion dans des bases allant jusqu'à 36\n Dans ces bases, les chiffres vont de 0 à Z selon les besoins de la base choisie\n (minuscules et majuscules sont egales) ";
    weak_conversion.menu_option_handler_callcack = &hello;

    MenuOption hard_conversion;
    hard_conversion.label = "Faire une conversion avec des bases quelconques";
    hard_conversion.description = "Il s'agit d'une conversion dans les bases quelconques (meme superieures à 36).\n Ici on utilise pas de lettres, les chiffres utilisés sont les equivalent en base 10 et les chiffres sont separes des tirets '-' \n Exemples: \n\t5EC (base 16) --> '5-14-12',\n\t '78-30-90' (base 100) --> (78 * 100 + 30) * 100 + 90 (base 10) \n\n";
    hard_conversion.menu_option_handler_callcack = &hello;


    add_option_to_menu(&menu, &weak_conversion);
    add_option_to_menu(&menu, &hard_conversion);
    router(menu);

    return 0;
}

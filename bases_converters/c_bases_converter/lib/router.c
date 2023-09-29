#include "header.h"
void router(Menu menu)
{
    int user_choice;
    int choosed_option_index;
    Bool is_valid_choice = false;
    printf("\n===========================\n\n");
    printf("%s \n", menu.label);
    for (int i = 0; i < menu.size; i++)
        printf("\t[%d] - %s \n", menu.options[i].id, menu.options[i].label);

    printf("  [0] Pour quitter l'application");
    printf("\n--------------------------\nChoisissez une instruction: ");
    scanf("%d", &user_choice);
    printf("\n===========================\n");

    if (user_choice == 0)
        close_the_app("Merci bien pour votre participation, j'espere que vous avez été satisfait");
        for (int i = 0; i < menu.size; i++)
        {
            if (user_choice == menu.options[i].id)
            {
                is_valid_choice = true;
                choosed_option_index = i;
                break;
            }
        }
    if (is_valid_choice == false)
    {
        printf("\n\n[!!] Option invalide veuillez prendre un choix parmi les numeros entre crochets");
        return router(menu);
    }
    // launch the menu option callback
    menu.options[choosed_option_index].menu_option_handler_callcack();
    return router(menu);
}

void add_option_to_menu(Menu *menu, MenuOption *option)
{
    option->id = ++menu->size;
    menu->options[menu->size - 1] = *option;
};

void presentation(){
    printf("\n\n\n\tCe programme permet de mettre en application \
    \n\t Les notions de representation de l'information et de changement de base \
     \n\n\t\t\t AUTHOR : KENGALI FEGUE PACOME - 21P027 - 3GI \n\t ARCHITECTURE DES ORDINATEURS - ENSPY \n"); 
}
void close_the_app(char *message){
    printf("%s", message);
    presentation();
    system("pause");
}
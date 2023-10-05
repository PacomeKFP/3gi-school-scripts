#ifndef TYPES_H
#define TYPES_H

typedef unsigned long long int u64;
typedef char *string;
typedef int *array;
typedef enum
{
    false,
    true
} Bool;

typedef struct Number
{
    array digits;
    int base;
    int len;
} Number;

typedef struct MenuOption
{
    int id;
    string label;
    string description;
    // The callback method used in seclect case
    void (*menu_option_handler_callcack)();
} MenuOption;

typedef struct Menu
{
    string label;
    int size;
    MenuOption *options;
} Menu;

typedef enum
{
    WEAK_CONVERSION,
    MEDIUM_CONVERSION,
    HARD_CONVERSION
} ConversionType;


#define INIT_MENU(menu) Menu menu = {.label = "Menu Principal", .size = 0, .options = (MenuOption *)malloc(sizeof(MenuOption))}

#endif

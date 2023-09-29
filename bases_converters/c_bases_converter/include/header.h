#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "types.h"

void display_list_content(array list, int size, Bool br);
void str_to_number_list(string str, array numbers, string separator, array size);
Bool check_number_validity(array initial_number, int number_len, int initial_base);
void duplicate_number(array original_number, array number_copy, int number_len);
void push_front(array number, int *len, int new_element);
void reverse_array(array array, int array_size);

void convert_to_base(array initial_number, int initial_number_len, int initial_base, array final_number, int *final_number_len, int final_base);
Bool verify_conversion(array initial_number, int initial_number_len, int initial_base, array final_number, int final_number_len, int final_base);

// Arithmetic in custom base
void add(array number1, int size_1, array number2, int size_2, array result, int base);

// Menu
void router(Menu menu);
void preqentation();
void close_the_app(string msg);
void add_option_to_menu(Menu *menu, MenuOption *option);
#endif

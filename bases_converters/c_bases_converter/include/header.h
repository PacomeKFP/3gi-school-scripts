#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "types.h"

// Preprocessor: Utils functions used to preprocess data before starting the conversion process
char int_to_ascii_char(int value);
void ascii_char_to_int(char ascii, Bool case_sensible, int *answer);
void display_list_content(array list, int size, Bool br);
void str_to_number_list(string str, array numbers,const string separator, int *size, ConversionType conversion_type);
Bool check_number_validity(array initial_number, int number_len, int initial_base);
void duplicate_number(array original_number, array number_copy, int number_len);
void push_front(array number, int *len, int new_element);
void reverse_array(array array, int array_size);
Bool verify_conversion(array initial_number, int initial_number_len, int initial_base, array final_number, int final_number_len, int final_base);

// Converter: functions that directly help for convertion
void convert_to_base(array initial_number, int initial_number_len, int initial_base, array final_number, int *final_number_len, int final_base);

// Menu
void router(Menu menu);
void presentation();
void close_the_app(string msg);
void add_option_to_menu(Menu *menu, MenuOption *option);

// Menu Option handlers
void weak_conversion_handler();
void medium_conversion_handler();
void hard_conversion_handler();
void get_data(string info, string number_example, int *initial_base, array initial_number, int *final_base, int *intitial_number_len, ConversionType conversion_type);

void number_list_to_str(array number, int number_len, string result);
#endif

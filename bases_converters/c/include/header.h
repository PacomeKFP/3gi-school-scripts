#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "types.h"

void display_list_content(int *list, int size);
void str_to_number_list(char *str, int *numbers, char *separator, int *size);
Bool check_number_validity(int *initial_number, int number_len, int initial_base);
void duplicate_number(int *original_number, int *number_copy, int number_len);
void push_front(int *number, int *len, int new_element);
void convert_to_base(int *initial_number, int initial_number_len, int initial_base, int *final_number, int *final_number_len, int final_base);
Bool verify_conversion(int *initial_number, int initial_number_len, int initial_base, int *final_number, int final_number_len, int final_base);


#endif

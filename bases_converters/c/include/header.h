#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "types.h"

void display_list_content(int *list, int size);
void str_to_number_list(char *str, int *numbers, char *separator, int *size);
void check_number_validity(int * initial_number,int initial_base);
#endif 

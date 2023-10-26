#ifndef STRING_H
#define STRING_H

#include "types.h"

uint16 str_lenght(string str){
    uint16 len = 1;
    while(str[len++]);
    return --len;
}

#endif
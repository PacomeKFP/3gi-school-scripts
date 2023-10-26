#ifndef STRING_H
#define STRING_H

#include "types.h"

uint16 str_lenght(string str)
{
    uint16 len = 1;
    while (str[len++])
        ;
    return --len;
}
bool str_equal(string str_1, string str_2)
{
    uint16 len_1 = str_lenght(str_1);
    if (len_1 != str_lenght(str_2))
        return false;
    for (uint16 i = 0; i < len_1; i++)
        if (str_1[i] != str_2[i])
            return false;
    
    return true;
}

#endif
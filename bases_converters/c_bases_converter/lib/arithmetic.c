#include "header.h"
void add(array number1, int size_1, array number2, int size_2, array result, int base)
{

    if (size_1 < size_2)
        return add(number2, size_2, number1, size_1, result,
         base);
    
    int rest = 0;

    for (int i = size_2-1; i >= 0; i--)
    {
        result[i] = (number1[i] + number2[i] + rest);
    }


}
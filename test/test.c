#include "../include/types.h"
#include "../include/system.h"
#include "../include/string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char a = (char)97;
    printf("%c", a);
    int n = -8;
    int sign;
    if (sign = (n < 0))
        n = -n;
    printf("%d", sign);
    return 0;
}

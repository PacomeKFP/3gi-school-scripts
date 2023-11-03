#include <stdio.h>
#include "hmm.h"

int main(int argc, char const *argv[])
{

    printf("Hello, World!\n");
    int *p = xmalloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        *(p + i) = i * i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}

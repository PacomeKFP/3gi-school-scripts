#include "hmm.h"
#define SIZE 10

int main(int argc, char const *argv[])
{

    // create a table, fill it with some data
    int *table = (int *)xmalloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = i;
    }



    // print the content of the table
    for (int i = 0; i < 2 * SIZE; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");


    return 0;
}

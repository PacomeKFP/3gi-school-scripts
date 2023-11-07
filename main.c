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

    // use realloc to add elements to the table
    table = xrealloc(table, 2 * SIZE * sizeof(int));
    for (int i = SIZE; i < SIZE * 2; i++)
    {
        table[i] = i;
    }

    // print the content of the table
    for (int i = 0; i < 2 * SIZE; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    xfree(table);

    return 0;
}

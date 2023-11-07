#include "hmm.h"

#define MAX_BLOC_NUMBER 256

typedef struct MemBlock
{
    void *address;
    size_t size;
} MemBlock;

MemBlock blocs[MAX_BLOC_NUMBER];
int nb_blocs = 0;

void *xmalloc(size_t size)
{

    void *address = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (address == MAP_FAILED)
    {
        printf("Error on mmap");
        return NULL;
    }
    blocs[nb_blocs].address = address;
    blocs[nb_blocs].size = size;
    nb_blocs++;
    return address;
}

void *xrealloc(void *ptr, size_t size)
{
    void *address = mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (address == MAP_FAILED)
    {
        printf("Error on reallocation");
        return NULL;
    }
    return address;
}

void xfree(void *adress)
{
    for (int i = 0; i < nb_blocs; i++)
        if (blocs[i].address == adress)
            munmap(adress, blocs[i].size);
}
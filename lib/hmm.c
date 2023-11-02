#include <sys/mman.h>

#include "hmm.h"

void *init()
{
    void *adress = mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    Heap my_heap = {
        .first_address = adress,
        .heap_size = HEAP_SIZE,
        .n_used_bytes = 0,
    };
}

void *xmalloc(size_t n_bytes)
{
}
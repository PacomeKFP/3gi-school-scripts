#include <stdio.h>
#include <sys/mman.h>
#include "hmm.h"

static Heap heap;
static bool is_initialized = false;

void init()
{
    // Force the heap creation
    do
    {
        heap.first_adress = mmap(NULL, sizeof(Heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    } while (heap.first_adress == NULL);
    heap.prt = heap.first_adress;
}

void *xmalloc(size_t n_bytes)
{
    if (!is_initialized)
    {
        init();
        is_initialized = true;
    }
    if (heap.first_adress + HEAP_SIZE < heap.prt + n_bytes)
    {
        printf("Allocation fail cause by memory overflow");
        return NULL;
    }
    heap.prt += n_bytes;
    return heap.prt;
}
// In the more simple approach of Heap management, on mem_free, we don't do nothing.
void xfree(void *address){
    // Do nothing.
}
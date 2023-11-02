#ifndef __HMM_H__
#define __HMM_H__

#define HEAP_SIZE 0x1000

typedef enum
{
    false,
    true
} bool;

typedef struct Heap
{
    void *first_address; // the first address returned by the mmap syscall
    size_t heap_size;
    size_t n_used_bytes;
    MemoryChunkList chunks;
} Heap;
typedef struct MemoryChunk
{
    void *first_adress;
    int size;
    bool is_in_use;
} MemoryChunk;

typedef struct MemoryChunkList
{
    MemoryChunk first_chunk;
    MemoryChunk *next_chunk;
};


void *init();
void *xmalloc(size_t);
void xfree(size_t);

#endif // __HMM_H__
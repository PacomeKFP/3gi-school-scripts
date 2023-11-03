#ifndef __HMM_H__
#define __HMM_H__

#define HEAP_SIZE 0x1000
#include "types.h"


// funtions for memory allocation
void init();
void *xmalloc(size_t);
void xfree(size_t);

// // Functions for the memory chunks linked List
// void add_chunk_to_list(MemoryChunkList *chunk_list, MemoryChunk *chunk);
// void remove_chunk_from_list(MemoryChunkList *chunk_list, MemoryChunk *chunk);


#endif // __HMM_H__
#ifndef __TYPES_H__
#define __TYPES_H__
#include "hmm.h"

typedef enum
{
    false,
    true
} bool;

typedef struct Heap
{
    void *first_adress; // the adress of the first adress (Heap address)
    void *prt;          // the place where where we are allocating from
} Heap;

#endif // __TYPES_H__

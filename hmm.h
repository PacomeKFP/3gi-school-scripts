#ifndef _HMM_
#define _HMM_
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>

void *xmalloc(size_t size);
void *xrealloc(void *ptr, size_t size);
void xfree(void *ptr);

#endif // _HMM_
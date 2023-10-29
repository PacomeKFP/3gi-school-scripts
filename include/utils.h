#ifndef _UTILS_H_
#define _UTILS_H_

#include "header.h"

void memory_copy(char *source, char * dest , int n_bytes);
void memory_set(uint8 *dest, uint8 val, uint32 len);
void int_to_ascii(int n, string str);

#endif // MACRO

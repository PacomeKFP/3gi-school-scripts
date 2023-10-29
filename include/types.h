#ifndef TYPES_H
#define TYPES_H

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int int16;
typedef unsigned short int uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long int int64;
typedef unsigned long int uint64;

typedef char *string;

typedef enum bool
{
    false,
    true
} bool;

#define low_16(adress) (uint16)((adress) & 0xFFFF)
#define high_16(adress) (uint16)((adress >> 16) & 0xFFFF)

#endif
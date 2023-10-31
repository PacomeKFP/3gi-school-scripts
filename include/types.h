#ifndef TYPES_H
#define TYPES_H

typedef char *string;
typedef struct StringList
{
    int size;
    string *strings;
} StringList;

#define INIT_STRING_LIST(X) \
    X = StringList { .size = 0 }

#endif // TYPES_H
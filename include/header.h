#ifndef _HEADER_H
#define _HEADER_H

#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef struct deque_bloc
{
    pid_t pid;
    struct deque_bloc *next;
} deque_bloc;

typedef struct deque
{
    deque_bloc *first;
    deque_bloc *last;
} deque;

void handle_client_create(int, siginfo_t *, void *);
void push_front(pid_t, deque *);
void display_deque(deque *);

#define INIT_DEQUE_BLOC(pid, bloc)                               \
    deque_bloc *bloc = (deque_bloc *)malloc(sizeof(deque_bloc)); \
    *bloc = {.pid = (pid_t)pid, .next = NULL};
#define INIT_DEQEUE(X) deque *X;
#define print(x) \
    printf(x);   \
    printf("\n")

#endif // _HEADER_H
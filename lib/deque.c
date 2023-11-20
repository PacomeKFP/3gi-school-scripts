#include "header.h"

void push_front(pid_t pid, deque *deq)
{
    deque_bloc *bloc = (deque_bloc *)malloc(sizeof(deque_bloc));
    bloc->pid = pid;

    if (deq->first == NULL && deq->last == NULL)
    { // cas d'une liste initialement vide
        bloc->next = NULL;
        deq->first = bloc;
        deq->last = bloc;
    }
    else
    { // Dans ce cas la liste contient deja au moins un element
        bloc->next = deq->first;
        deq->first = bloc;
    }
}

void display_deque(deque *dq)
{
    deque_bloc *b = dq->first;
    printf("[");
    while (b != NULL)
    {
        printf("%d, ", b->pid);
        b = b->next;
    }
    print("]");
}
#include "header.h"

#define CREATE_CLIENT 1

int count = 0;
INIT_DEQEUE(dq)

void handle_client_create(int signum, siginfo_t *info, void *context)
{
    printf("handle_client_create : %d - %d- %p \n", info->si_pid, signum, context);
    sleep(6);
    push_front(((pid_t)info->si_pid), dq);
    printf("Signal Handled with succes %d\n", info->si_pid);
}

int main(void)
{
    struct sigaction signal;
    dq = (deque *)malloc(sizeof(deque));

    if (dq == NULL)
    {
        perror("malloc");
        exit(1);
    }
    dq->first = NULL;
    dq->last = NULL;

    signal.sa_sigaction = handle_client_create;
    sigemptyset(&signal.sa_mask);
    // sa_mask c'est pour preciser les signaux qui doivent etre masqués pendant l'execution du handler
    // sa_flags c'est pour preciser les options de l'action du signal
    signal.sa_flags = SA_SIGINFO;
    sigaction(CREATE_CLIENT, &signal, NULL);

    for (;;)
    {
        display_deque(dq);
        sleep(5);
    }

    return 0;
}

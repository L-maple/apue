#include "apue.h"

static void sig_int(int);

int
main()
{
    sigset_t newmask, oldmask, waitmask;

    printf("program start");
    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal(SIGINT) error");
    }

    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");

    printf("in critical region\n");
    
    if (sigsuspend(&waitmask) != -1)
        err_sys("sigsuspend error");

    printf("after return from sigsuspend\n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");

    printf("program exit: ");
    exit(0);
}

static void
sig_int(int signo)
{
    printf("\nin sig_int: \n");
}

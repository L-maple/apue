#include "apue.h"

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;

static void
sig_usr(int signo) {
    sigflag = 1;
}

void TELL_WAIT(void);
void TELL_PARENT(pid_t pid);
void WAIT_PARENT(void);
void TELL_CHILD(pid_t pid);
void WAIT_CHILD(void);

int main() {
    TELL_WAIT();
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        WAIT_PARENT();
        printf("I am a child, first print.\n");
        TELL_PARENT(getppid());
//      WAIT_PARENT();
 //     printf("I am a child, second print.\n");

        exit(0);
    } 
    printf("I am parent, first print.\n");
    TELL_CHILD(pid);
    WAIT_CHILD();
 // printf("I am parent, second print.\n");
    
    exit(0);
}


void
TELL_WAIT()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR1) error");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR2) error");
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");
}

void 
TELL_PARENT(pid_t pid)
{
    kill(pid, SIGUSR2);
}

void
WAIT_PARENT(void)
{
    while (sigflag == 0)
    {
        sigsuspend(&zeromask);
    }
    sigflag = 0;
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

void 
TELL_CHILD(pid_t pid)
{
    kill(pid, SIGUSR1);
}

void
WAIT_CHILD(void)
{
    while (sigflag == 0)
        sigsuspend(&zeromask);
    sigflag = 0;

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

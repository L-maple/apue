#include "apue.h"
#include <sys/wait.h>

int 
main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        err_sys("fork failed");
    else if (pid == 0)
    {
        sleep(2);
        printf("process id: %d, parent process id: %d\n", getpid(), getppid());
        exit(0);
    }

    if (waitid(P_PID, pid, NULL, WEXITED) < 0)
    {
        err_sys("waitid error");
    }

    exit(0);
}

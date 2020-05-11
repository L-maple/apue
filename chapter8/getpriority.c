#include "apue.h"
#include <sys/resource.h>
#include <stdio.h>

int
main()
{
    printf("before nice, priority: %d\n", getpriority(PRIO_PROCESS, 0));
    printf("before nice, priority: %d\n", getpriority(PRIO_PROCESS, getpid()));

    nice(100);
    printf("after nice, priority: %d\n", getpriority(PRIO_PROCESS, 0));
    exit(0);
}

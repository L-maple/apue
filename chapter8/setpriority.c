#include "apue.h"
#include<sys/resource.h>

int
main()
{
    setpriority(PRIO_PROCESS, 0, 12);
    printf("priority: %d\n", getpriority(PRIO_PROCESS, getpid()));

    return 0;
}

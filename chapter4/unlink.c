#include "apue.h"
#include<fcntl.h>

int
main(void)
{
    if (open("test", O_RDWR) < 0)
    {
        err_sys("open error");
    }

    if (unlink("test") < 0)
    {
        err_sys("unlink error");
    }

    printf("file unlinked\n");
    sleep(60);
    printf("done\n");

    exit(0);
}

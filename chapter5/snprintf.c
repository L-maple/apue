#include<stdio.h>
#include<apue.h>

int
main(void)
{
    char buf[10];

    if(snprintf(buf, 10, "%d is a really big number.", 10) < 0)
        err_ret("snprintf has characters more than n-1.");

    printf("buf: %s\n", buf);
    return 0;
}


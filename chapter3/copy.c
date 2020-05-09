#include"apue.h"
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 4

int
main(void)
{
    int fd, n;
    char buf[BUFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
        if((n = write(STDOUT_FILENO, buf, n)) < 0)
            err_sys("write error!");

    if (n < 0)
        err_sys("read error!");
    exit(0);
}

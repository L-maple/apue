#include "apue.h"
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

long 
open_max()
{
    if (openmax == 0)   
    {
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
        {
            if (errno == 0)
                openmax = OPEN_MAX_GUESS;
            else
                err_sys("sysconf error for _SC_OPEN_MAX");
        }
    }

    return openmax;
}

int dup2(int fd, int fd2)
{
    if (fd == fd2) 
        return fd;
    
    // if fd not opened, sys_error
    if (!fcntl(fd, F_GETFL))
    {
        return -1;
    }
    // if fd2 has opened, close it
    if (fcntl(fd2, F_GETFL) > 0)
    {
        close(fd2);
    }
    // fd2 not opened
    int fdmax = open_max();
    int* buffer = (int*)malloc(sizeof(int) * fdmax);

    int newfd;
    int bindex = 0;
    while (bindex < fdmax)
    {
        if((newfd = dup(fd)) < 0)
        {
            for (int i = 0; i < bindex; ++i)
            {
                close(buffer[bindex]);
            }
            free(buffer);
            err_sys("dup error!");
        }
        
        if (newfd == fd2)
        {
            for (int i = 0; i < bindex; ++i)
            {
                close(buffer[bindex]);
            }
            free(buffer);
            return fd2;
        }
        else
        {
            buffer[bindex++] = newfd;
        }
    }

    return -1;
}


int
main(void)
{
    int fd = dup2(1, 15);
    char buf[] = "Hello, world!";

    if (write(fd, buf, strlen(buf)) < 0)
        err_sys("write error!");

    close(fd);

    exit(0);
}

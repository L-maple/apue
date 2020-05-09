#include"apue.h"
#include<unistd.h>
#include<fcntl.h>

int 
main(void)
{
    int fd, n;
    char buf[] = "qwert";

    if ((fd = open("hello", O_RDWR, FILE_MODE)) < 0)
        err_sys("open error!");
    
    if((n = write(fd, buf, strlen(buf)) < 0))
        err_sys("write error!");

    exit(0);
}

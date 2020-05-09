#include "apue.h"
#include <unistd.h>
#include<fcntl.h>

int 
main(void)
{
    char buf[] = "abcdefghij";
    int n, fd;
    
    if ((fd = open("hello", O_RDWR | O_CREAT, FILE_MODE)) < 0)
        err_sys("open error");
    if ((n = write(fd, buf, 10)) < 0)
        err_sys("write error!");
    /*offset is 10*/

    lseek(fd, 0, SEEK_SET);
    if ((n = write(fd, buf+5, 5)) < 0)
        err_sys("write error!");
    /*offset is 5*/

    return 0;
}

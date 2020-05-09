#include"apue.h"
#include<unistd.h>
#include<fcntl.h>
#include<time.h>

int
main(void)
{
    int fd = open("/dev/fd/0", O_RDWR, FILE_MODE);

    printf("fd: %d\n", fd);
    
    sleep(100);

    return 0;
}

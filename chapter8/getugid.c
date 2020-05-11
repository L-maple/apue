#include "apue.h"

int
main(void)
{
    setuid(1000);
    // setuid(-1000);
    printf("ruid: %ld, rgid: %ld, euid: %ld, egid: %ld\n", (long)getuid(), (long)getgid(), (long)geteuid(), (long)getegid());

    return 0;
}

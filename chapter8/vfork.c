#include "apue.h"

int globvar = 6;

int
main(void)
{
    int var, count;
    char buf[10];
    pid_t pid;

    var = 88;
    printf("before vfork\n"); /*we don't flush stdio*/
    if ((pid = vfork()) < 0)
        err_sys("vfork error");
    else if (pid == 0)
    {
        globvar++;
        var++;
        //close(1);
        fclose(stdout);
        exit(0);
        //close(1);
    }

    /*parent continues here*/
    count = printf("pid=%ld, glob=%d, var=%d\n", (long)getpid(), globvar, var);
    sprintf(buf, "%d\n", count);
    write(STDOUT_FILENO, buf, strlen(buf));

    exit(0);
}


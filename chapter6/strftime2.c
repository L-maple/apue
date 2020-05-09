#include "apue.h"
#include <time.h>

int
main(void)
{
    time_t caltime;
    struct tm *tmp;
    char line[MAXLINE];

    if ((caltime = time(NULL)) == -1)
        err_sys("time error");
    if ((tmp = localtime(&caltime)) == NULL)
        err_sys("localtime error");
    if (strftime(line, MAXLINE, "%a %b %d %X %Z, %Y\n", tmp) == 0)
        err_sys("strftime error");

    fputs(line, stdout);
    exit(0);
}

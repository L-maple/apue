#include "apue.h"

int
main(void)
{
    char buf[10];

    while (fgets(buf, 10, stdin) != NULL)
    {
        if (fputs(buf, stdout) == EOF)
            err_sys("output error");
    }

    if (ferror(stdin))
        err_sys("input error");

    if (feof(stdin))
        printf("end-of-file.\n");

    exit(0);
}


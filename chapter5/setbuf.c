#include "apue.h"
#include <stdio.h>

int
is_linebuffered(FILE* fp)
{
    return (fp->_flags & _IOLBF);
}

int mysetbuf(FILE* fp, char* buf)
{
    if (fp == NULL)
        err_sys("fp is NULL");

    if (buf == NULL)
    {
        return setvbuf(fp, NULL, _IONBF, 0);
    }
    else if (is_linebuffered(fp))
    {
        return setvbuf(fp, buf, _IOLBF, sizeof(buf));
    }
    else
    {
        return setvbuf(fp, buf, _IOFBF, sizeof(buf));
    }
}

int main()
{
    FILE* fp = fopen("hello", "w+");
    char buf[100];
    mysetbuf(fp, buf);

    return 0;
}

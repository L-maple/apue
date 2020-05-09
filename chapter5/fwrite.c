#include "apue.h"
#include <stdio.h>

int
main(void)
{
    float data[4] = {1.0, 2.0, 4.0, 8.0};
    float copy[4];
    FILE* fp = fopen("hello", "wb+");
    fpos_t pos;

    fgetpos(fp, &pos);
    if (fwrite(data, sizeof(float), 4, fp) != 4)
        err_sys("fwrite error!");

    fsetpos(fp, &pos);

    if (fread(copy, sizeof(float), 4, fp) != 4)
        err_sys("fread error");

    for (int i = 0; i < 4; ++i)
    {
        printf("%f\t", copy[i]);
    }
    printf("\n");

    return 0;
}

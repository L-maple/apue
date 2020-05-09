#include "apue.h"
#include<stdio.h>

int
main(void)
{
    if (printf("") == 0)
        printf("Only empty string printed.");
    
    return 0;
}

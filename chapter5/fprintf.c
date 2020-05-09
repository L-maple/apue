#include "apue.h"
#include <stdio.h>

int
main(void)
{
    fprintf(stdout, "left-justify with '-': %-5.2d, right-justify default: %5.2d\n", 1, 1);
    
    fprintf(stdout, "signed with '+': %+d, signed without '+': %d\n", 12, 12);

    fprintf(stdout, "specify fldwidth & precision with *: %*.*f\n", 20, 3, 20.4);
    
    return 0;
}


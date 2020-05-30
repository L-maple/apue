#include "apue.h"
#include <signal.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
    char str[BUFSIZE];
    if(sig2str(3, str) >= 0)
    {
        printf("str: %s\n", str);
    }
    
    return 0;
}

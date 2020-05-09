#include "apue.h"
#include <shadow.h>

int main(int argc, char* argv[])
{
    struct spwd* spp;

    //if (argc != 2)
    //   sys_err("usage: ./a.out username");
    
    setspent();
    while ((spp = getspent()) != NULL)
    {
        printf("%s: %s\n", spp->sp_namp, spp->sp_pwdp);
    }
    endspent();

    return 0;
}

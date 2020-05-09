#include"apue.h"
#include<dirent.h>
#include<limits.h>

typedef int Myfunc(const char*, const struct stat*, int);

static Myfunc myfunc;
static int myftw(char*, Myfunc*);
static int dopath(Myfunc*);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int 
main(int argc, char* argv[])
{
    int ret;

    if (argc != 2)
        err_quit("usage: ftw <starting-pathname>");

    ret = myftw(argv[1], myfunc);

    ntot = nreg + nblk + nchr + nfifo + nslink + nsock + ntot;

    if (ntot == 0)
        ntot = 1;
    printf("regular files      = %7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
    printf("directories        = %7ld, %5.2f %%\n", ndir, ndir * 100.0 / ntot);
    printf("block special      = %7ld, %5.2f %%\n", nblk, nblk * 100.0 / ntot);
    printf("character special  = %7ld, %5.2f %%\n", nchr, nchr * 100.0 / ntot);
    printf("FIFO               = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0 /ntot);
    printf("symbolic links     = %7ld, %5.2f %%\n", nslink, nslink * 100.0 / ntot);
    printf("sockets            = %7ld, %5.2f %%\n", nsock, nsock * 100.0 % ntot);

    return 0;
}

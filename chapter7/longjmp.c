#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int
main(void)
{
    int          autoval;
    register int regival;
    volatile int volaval;
    static   int staval;

    globval = 1; autoval = 2; regival = 3; volaval = 4; staval = 5;

    if (setjmp(jmpbuffer) != 0)
    {
        printf("after longjmp:\n");
        printf("globval = %d, autoval = %d, regival = %d, volaval = %d, staval = %d\n", globval, autoval, regival, volaval, staval);
        exit(0);
    }

    /*
    ** change variables after setjmp, but before longjmp
    **
    */
    globval = 95; autoval = 96; regival = 97; volaval = 98; staval = 99;

    f1(autoval, regival, volaval, staval);

    exit(0);
}

static void
f1(int i, int j, int k, int l)
{
    printf("in f1():\n");
    printf("globval = %d, autoval = %d, regival = %d, volaval = %d, staval = %d\n", globval, i, j, k, l);

    f2();
}

static void
f2(void)
{
    longjmp(jmpbuffer, 1);
}

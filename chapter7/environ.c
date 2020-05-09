#include "apue.h"

int
main(int argc, char* argv[])
{
    for (int i = 0; __environ[i] != NULL; ++i)
    {
        printf("%s\n", __environ[i]);
    }

    return 0;
}

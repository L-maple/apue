#include "apue.h"
#include <time.h>
#include <sys/time.h>

int
main()
{
    struct timeval us;
    struct timespec tsp;

    printf("time(): %ld\n", time(NULL));
    
    clock_getres(CLOCK_REALTIME, &tsp);
    printf("realtime resolution: seconds:%ld, nanoseconds: %ld\n", tsp.tv_sec, tsp.tv_nsec);

    clock_getres(CLOCK_MONOTONIC, &tsp);
    printf("monotonic time resolution: seconds: %ld, nanoseconds: %ld\n", tsp.tv_sec, tsp.tv_nsec);

    clock_gettime(CLOCK_REALTIME, &tsp);
    printf("clock_gettime(): seconds: %ld, nanoseconds: %ld\n", tsp.tv_sec, tsp.tv_nsec);

    gettimeofday(&us, NULL);
    printf("gettimeofday(): seconds: %ld, microseconds: %ld\n", us.tv_sec, us.tv_usec);

    return 0;
}




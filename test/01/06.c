#include <stdio.h>
#include <time.h>

int main() {
    struct timespec start_time;
    clock_gettime(CLOCK_REALTIME, &start_time);
    printf("Start time: %ld seconds, %ld nanoseconds\n", start_time.tv_sec, start_time.tv_nsec);
    return 0;
}

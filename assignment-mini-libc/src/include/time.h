#ifndef TIME_H
#define TIME_H

#include <stddef.h>

typedef long time_t;
typedef long clock_t;
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

time_t time(time_t* tloc);
double difftime(time_t time1, time_t time0);
char* ctime_r(const time_t* timer);
struct timespec* localtime_r(const time_t* timer);
clock_t clock(void);
int nanosleep(struct timespec *t, struct timespec *r);

#endif

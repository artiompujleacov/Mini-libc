#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int nanosleep(struct timespec *req, struct timespec *rem) {
  int ret = syscall(__NR_nanosleep, req, rem);
  if (ret < 0) {
    return -1;
  }
  return ret;
}

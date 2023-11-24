#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <unistd.h>

int sleep(unsigned int seconds) {
  struct timespec t, r;
  t.tv_sec = seconds;
  r.tv_nsec = 0;
  t.tv_nsec = 0;
  if (nanosleep(&t, &r) < 0) {
    return -1;
  }
  return 0;
}

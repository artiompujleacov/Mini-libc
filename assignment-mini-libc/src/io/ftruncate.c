#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length) {
  int ret = syscall(__NR_ftruncate, fd, length);
  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}

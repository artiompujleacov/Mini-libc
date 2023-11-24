#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st) {
  int ret = syscall(__NR_fstat, fd, st);
  if (ret < 0) {
    errno = -ret;
    return -1;
  }
  return ret;
}

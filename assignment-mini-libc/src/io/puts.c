#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *str) {
  int len = strlen(str);
  int ret = write(__NR_write, str, len);
  write(1, "\n", 1);
  if (ret < 0) {
    errno = -ret;
    return -1;
  }
  return ret;
}

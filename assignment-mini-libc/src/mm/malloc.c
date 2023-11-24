#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
  void *memory = mmap(NULL, size + 4, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (memory == MAP_FAILED) {
    return NULL;
  }
  ((size_t *)memory)[0] = size;
  return (int *)memory + 1;
}

void *calloc(size_t nmemb, size_t size) {
  void *memory = mmap(NULL, nmemb * size + 4, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  ((size_t *)memory)[0] = size;
  memset((int *)memory + 1, 0, nmemb*size);
  return (int *)memory + 1;
}

void free(void *ptr) {
  size_t size = *((int *)ptr - 1);
  munmap((int *)ptr - 1, size + sizeof(int));
}

void *realloc(void *ptr, size_t size) {
  void *new_memory = mmap(NULL, size + 4, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  size_t old_size = *((int *)ptr - 1);
  memcpy(new_memory, ptr, old_size);
  free(ptr);
  return new_memory;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  void *new_memory = mmap(NULL, nmemb * size + 4, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  size_t old_size = *((int *)ptr - 1);
  memcpy(new_memory, ptr, old_size);
  free(ptr);
  return new_memory;
}

#include <stdio.h>

char *strcpy(char *destination, const char *source) {
  if (sizeof(destination) >= sizeof(source)) {
    int n = strlen(source);
    for (int i = 0; i < n; i++) {
      destination[i] = source[i];
    }
    destination[n] = '\0';
  }
  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  if (sizeof(destination) >= sizeof(source)) {
    for (size_t i = 0; i < len; i++) {
      if (source[i] == '\0') {
        for (; i < len; i++) {
          destination[i] = '\0';
        }
        break;
      } else {
        destination[i] = source[i];
      }
    }
  }
  return destination;
}

char *strcat(char *destination, const char *source) {
  int n = strlen(destination), m = strlen(source);
  for (int i = 0; i < m; i++) {
    destination[n + i] = source[i];
  }
  destination[n + m] = '\0';
  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  int n = strlen(destination);
  size_t i;
  for (i = 0; i < len; i++) {
    destination[n + i] = source[i];
  }
  destination[n + i] = '\0';
  return destination;
}

int strcmp(const char *str1, const char *str2) {
  int n = strlen(str1), m = strlen(str2), eq = 0;
  if (n > m) {
    return 1;
  } else if (m > n) { 
    return -1;
  } else {
    for (int i = 0; i < n; i++) {
      if (str1[i] != str2[i]) {
        if (str1[i] > str2[i]) {
          return 1;  
        } else if (str1[i] < str2[i]) {
          return -1;
        }
        break;
      } else {
        eq++; //
      }
    }
  }
  return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  size_t eq = 0;
  for (size_t i = 0; i < len; i++) {
    if (str1[i] != str2[i]) {
      if (str1[i] > str2[i]) {
        return 1;
      } else if (str1[i] < str2[i]) {
        return -1;
      }
      break; 
    } else {
      eq++;
    }
  }
  if (eq == len) {
    return 0;
  }
  return 0;
}

size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++)
    ;

  return i;
}

char *strchr(const char *str, int c) {
  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    if (c == str[i]) {
      const char *addr = &str[i];
      return (char *)addr;
    }
  }
  return NULL;
}

char *strrchr(const char *str, int c) {
  int n = strlen(str);
  const char *last = NULL;
  for (int i = 0; i < n; i++) {
    if (c == str[i]) {
      last = &str[i];
    }
  }
  return (char *)last;
}

char *strstr(const char *haystack, const char *needle) {
  const char *position = NULL;
  size_t chars = 0;
  for (size_t i = 0; i < strlen(haystack); i++) {
    if (haystack[i] == needle[0]) {
      position = &haystack[i];
      for (size_t j = 0; j < strlen(needle); j++) {
        if (haystack[i + j] == needle[j]) {
          chars++;
        }
      }
      if (chars == strlen(needle)) {
        return (char *)position;
        break;
      }
    }
  }

  return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  int n = strlen(haystack);
  int m = strlen(needle);
  for (int i = n - m; i >= 0; i--) {
    int chars = 0;
    for (int j = 0; j < m; j++) {
      if (haystack[i + j] == needle[j]) {
        chars++;
      } else {
        break;
      }
    }
    if (chars == m) {
      return (char *)&haystack[i];
    }
  }
  return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
  for (size_t i = 0; i < num; i++) {
    ((char *)destination)[i] = ((const char *)source)[i];
  }
  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  char temp;
  for (size_t i = 0; i < num; i++) {
    temp = ((const char *)source)[i];
    ((char *)destination)[i] = temp;
  }
  ((char *)destination)[num] = '\0';
  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  for (size_t i = 0; i < num; i++) {
    if (((char *)ptr1)[i] != ((char *)ptr2)[i]) {
      return (((char *)ptr1)[i] > ((char *)ptr2)[i]) ? 1 : -1;
    }
  }
  return 0;
}

void *memset(void *source, int value, size_t num) {
  for (size_t i = 0; i < num; i++) {
    ((unsigned char *)source)[i] = ((unsigned char)value);
  }
  return source;
}

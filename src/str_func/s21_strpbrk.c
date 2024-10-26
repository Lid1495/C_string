#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  for (const char *p = str1; *p; p++) {
    for (const char *p1 = str2; *p1; p1++) {
      if (*p == *p1) {
        return (void *)p;
      }
    }
  }
  return NULL;
}
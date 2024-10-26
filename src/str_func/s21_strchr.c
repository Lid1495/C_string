#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (const char *p = str; *p; p++) {
    if (*p == c) {
      return (char *)p;
    }
  }
  return s21_NULL;
}
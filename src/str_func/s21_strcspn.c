#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int SUB = 0;
  for (const char *p = str1; *p; p++) {
    for (const char *p1 = str2; *p1; p1++) {
      if (*p == *p1) {
        SUB = 1;
      }
    }
    if (SUB) {
      break;
    }
    len++;
  }
  return len;
}
#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  s21_size_t count = 1;
  while (*str1 == *str2 && *str1 != '\0' && count < n) {
    str1++;
    str2++;
    count++;
  }
  if (*str1 == *str2) {
    result = 0;
  } else if (*str1 > *str2) {
    result = 1;
  } else {
    result = -1;
  }
  return result;
}
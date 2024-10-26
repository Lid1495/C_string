#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int sub = 0;
  int check_empty = 0;

  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src)) {
    return s21_NULL;
  }

  if (s21_strncmp(str, "", s21_strlen(str)) == 0) {
    check_empty = 1;
  }

  s21_size_t len = s21_strlen(src) + s21_strlen(str) + 1;
  char *newStr = malloc(len * sizeof(char));
  if (newStr == s21_NULL) {
    return s21_NULL;
  }
  const char *p1 = src;
  const char *p2 = str;
  for (s21_size_t i = 0; i < len; i++) {
    if (i == start_index && !check_empty) {
      sub = 1;
    }
    if (!sub) {
      newStr[i] = *p1++;
    } else {
      newStr[i] = *p2++;
      if (*p2 == '\0') {
        sub = 0;
      }
    }
  }
  newStr[len - 1] = '\0';
  return newStr;
}

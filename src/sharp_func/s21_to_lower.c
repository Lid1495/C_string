#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  char *newStr = malloc((s21_strlen(str) + 1) * sizeof(str[0]));
  if (newStr == s21_NULL) {
    return s21_NULL;
  }
  char *p1 = newStr;
  for (const char *p = str; *p != '\0'; p++, p1++) {
    if (*p >= 'A' && *p <= 'Z') {
      *p1 = *p + ('a' - 'A');
    } else {
      *p1 = *p;
    }
  }
  newStr[s21_strlen(str)] = '\0';
  return newStr;
}

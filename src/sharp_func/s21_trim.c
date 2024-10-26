#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) return s21_NULL;
  s21_size_t start = 0;
  s21_size_t end = s21_strlen(src);

  while (src[start] && s21_strchr(trim_chars, src[start]) != s21_NULL) {
    start++;
    // printf("%s\n", s21_strchr(trim_chars, src[start]));
  }
  // printf("%lu", start);
  while (end > start && s21_strchr(trim_chars, src[end - 1]) != s21_NULL) {
    end--;
  }

  s21_size_t new_len = end - start;
  // printf("%lu-%lu", start, end);
  char *newStr = (char *)malloc((new_len + 1) * sizeof(char));
  if (newStr == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < new_len; i++) {
    newStr[i] = src[start + i];
  }
  newStr[new_len] = '\0';

  return newStr;
}
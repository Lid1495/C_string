#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t size_main_str = 0;
  size_main_str = s21_strlen(dest);  //для проверки хватит ли места в строке
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) dest[size_main_str + i] = src[i];
  dest[size_main_str + i] = '\0';
  return dest;
}
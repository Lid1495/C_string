/**
 * Функция memset(void *str, int c, size_t n):
 *  копирует символ c (беззнаковый тип) в первые n символов строки, на которую
 * указывает аргумент str.
 */

#include "../s21_string.h"

void* s21_memset(void* str, int c, s21_size_t n) {
  unsigned char* ch = (unsigned char*)str;

  for (s21_size_t i = 0; i < n; i++) {
    ch[i] = (unsigned char)c;
  }
  return ch;
}

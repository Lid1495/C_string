/**
 * Функция char *strstr(const char *haystack, const char *needle):
 * Находит первое вхождение всей строки needle (не включая завершающий нулевой
 * символ), которая появляется в строке haystack. Функция возвращает АДРЕС
 * первой найденной строки.
 */

#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len_n = 0;
  len_n = s21_strlen(needle);

  s21_size_t len_h = 0;
  len_h = s21_strlen(haystack);

  int rez = -1;
  long unsigned int count_sovp =
      0;  // чтобы поиск остановился на первом найденном совпадении

  if (len_n == 0) rez = 0;

  for (s21_size_t i = 0; i < len_h; i++) {
    if ((haystack[i] == needle[0]) && (count_sovp != len_n)) {
      rez = i;
      for (s21_size_t j = 0; j < len_n; j++) {
        if (haystack[j + i] != needle[j]) {
          rez = -1;
          count_sovp = 0;
          break;
        } else {
          count_sovp++;
        }
      }
    }
  }

  char *rez2;

  if (rez != -1) {
    rez2 = (char *)haystack + rez;
  } else {
    rez2 = (char *)s21_NULL;
  }
  return rez2;
}
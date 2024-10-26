/**
 * Функция memcmp cравнивает первые n байтов str1 и str2.
 * Для переменных типа char: const - неизменяемая величина, unsigned
 * (беззнаковый) - символьные переменные принимают значения от 0 до 255. Для
 * переменных типа int: signed - целочисленные как минимум из диапазона [−32767,
 * +32767], в зависимости от разрядности системы
 */

#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  signed int result = 0;
  const unsigned char *ch1 = (const unsigned char *)str1;
  const unsigned char *ch2 = (const unsigned char *)str2;

  for (s21_size_t i = 0; i < n; i++) {
    if (ch1[i] != ch2[i]) {
      result = (int)ch1[i] - (int)ch2[i];
      break;
    }
  }
  return result;
}
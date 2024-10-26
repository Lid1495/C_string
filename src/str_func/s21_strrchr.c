#include "../s21_string.h"

char* s21_strrchr(const char* str, int c) {
  char* result = s21_NULL;
  for (char* temp = (char*)str + s21_strlen(str); temp >= str; temp--) {
    if (*temp == c) {
      result = temp;
      break;
    }
  }
  return result;
}
#include "../s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* tokenString = s21_NULL;
  char* result = s21_NULL;
  char* newString = s21_NULL;
  if (str != s21_NULL) {
    tokenString = str;
  }
  if (tokenString != s21_NULL) {
    newString = s21_strstr(tokenString, delim);
  }
  if (newString != s21_NULL) {
    s21_size_t size = newString - tokenString;
    result = (char*)malloc(sizeof(char) * size);
    s21_strncpy(result, tokenString, size);
    tokenString = newString + s21_strlen(delim);
  } else if (tokenString != s21_NULL) {
    result = tokenString;
    tokenString = s21_NULL;
  }
  return result;
}
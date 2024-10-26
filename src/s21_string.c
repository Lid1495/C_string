#include "s21_string.h"

#include "string.h"
void test() {
  char* src = s21_NULL;
  char ch = 'l';
  s21_size_t size = 3;
  char* res2 = memchr(src, ch, size);
  printf("%s", res2);
}

int main() { test(); }

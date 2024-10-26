#include "testing.h"

START_TEST(char_string) {
  char str1[] = "Hello world";
  char str2[] = "Hello world";
  int c = 'n';
  s21_size_t n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(int_string) {
  int str1[] = {88005, 5535, 35};
  int str2[] = {88005, 5535, 35};
  int c = 'g';
  s21_size_t n = 11;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq((char *)str1, (char *)str2);
}
END_TEST

START_TEST(char_string_one_zamena) {
  char str1[] = "1234567";
  char str2[] = "1234567";
  int c = 'Z';
  s21_size_t n = 1;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_string_slash_n) {
  char str1[] = "\n";
  char str2[] = "\n";
  int c = 'q';
  s21_size_t n = 1;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_string_term_zero) {
  char str1[] = "\0";
  char str2[] = "\0";
  int c = '1';
  s21_size_t n = 1;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_string_term_zero2) {
  char str1[] = "\0\0";
  char str2[] = "\0\0";
  int c = '@';
  s21_size_t n = 1;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_string_slash_n2) {
  char str1[] = "a\n\0";
  char str2[] = "a\n\0";
  int c = '\n';
  s21_size_t n = 2;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_string_slash_n3) {
  char str1[] = " \n\0";
  char str2[] = " \n\0";
  int c = '\0';
  s21_size_t n = 2;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_s21_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("tc_memset");

  tcase_add_test(tc, char_string);
  tcase_add_test(tc, int_string);
  tcase_add_test(tc, char_string_one_zamena);
  tcase_add_test(tc, char_string_slash_n);
  tcase_add_test(tc, char_string_term_zero);
  tcase_add_test(tc, char_string_term_zero2);
  tcase_add_test(tc, char_string_slash_n2);
  tcase_add_test(tc, char_string_slash_n3);

  suite_add_tcase(s, tc);
  return s;
}
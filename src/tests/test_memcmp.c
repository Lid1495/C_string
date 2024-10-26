#include "testing.h"

START_TEST(equal_strings) {
  char str1[] = "Hello world";
  char str2[] = "Hello world";
  s21_size_t n = 11;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(not_equal_strings) {
  char str1[] = "Hello world";
  char str2[] = "Hello wor";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(string_and_int_array) {
  char str1[] = "123lo world";
  int str2[] = {1, 2, 3};
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(zero_bytes_compare) {
  char str1[] = "Hello world";
  char str2[] = "Hell";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(char_and_float_array) {
  char str1[] = "1.488";
  float str2[] = {3.14159265, 3.15, 6.6666};
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(char_and_long_int_array) {
  char str1[] = "3.14";
  long long int str2[] = {314159265358979384, 66666666666666666};
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(term_null) {
  char str1[] = "\0";
  char str2[] = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(term_null_2) {
  char str1[] = "\0\0";
  char str2[] = "\0";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(term_null_3) {
  char str1[] = "\0\n";
  char str2[] = "\0\n\n";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(term_null_4) {
  char str1[] = "\n\0";
  char str2[] = "\n\0\n";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *suite_s21_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("tc_memcmp");

  tcase_add_test(tc, equal_strings);
  tcase_add_test(tc, not_equal_strings);
  tcase_add_test(tc, string_and_int_array);
  tcase_add_test(tc, zero_bytes_compare);
  tcase_add_test(tc, char_and_float_array);
  tcase_add_test(tc, char_and_long_int_array);
  tcase_add_test(tc, term_null);
  tcase_add_test(tc, term_null_2);
  tcase_add_test(tc, term_null_3);
  tcase_add_test(tc, term_null_4);

  suite_add_tcase(s, tc);
  return s;
}
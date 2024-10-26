#include "testing.h"

START_TEST(test_s21_strtok_1) {
  char str[] = "hello world";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str[] = "abc,def,ghi";
  const char delim[] = ",";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str[] = "1234567890";
  const char delim[] = "5";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str[] = "a-b-c-d-e-f";
  const char delim[] = "-";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char str[] = "apple.orange.banana.grape";
  const char delim[] = ".";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

Suite *suite_s21_strtok(void) {
  Suite *s = suite_create("suite_s21_strtok");
  TCase *tc = tcase_create("tc_s21_strtok");

  tcase_add_test(tc, test_s21_strtok_1);
  tcase_add_test(tc, test_s21_strtok_3);
  tcase_add_test(tc, test_s21_strtok_5);
  tcase_add_test(tc, test_s21_strtok_7);
  tcase_add_test(tc, test_s21_strtok_9);

  suite_add_tcase(s, tc);
  return s;
}

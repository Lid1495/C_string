#include "testing.h"

START_TEST(strncpy_1) {
  char test_1[10] = "abcde";
  char test_2[10] = "fghij";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(test_1, test_2, n), strncpy(test_1, test_2, n));
}
END_TEST

START_TEST(strncpy_2) {
  char test_3[10] = "";
  char test_4[] = "abcde";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(test_3, test_4, n), strncpy(test_3, test_4, n));
}
END_TEST

START_TEST(strncpy_3) {
  char test_5[] = "abcde";
  char test_6[10] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(test_5, test_6, n), strncpy(test_5, test_6, n));
}
END_TEST

START_TEST(strncpy_4) {
  char test_7[10] = "abcde";
  char test_8[10] = "fghij";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncpy(test_7, test_8, n), strncpy(test_7, test_8, n));
}
END_TEST

START_TEST(strncpy_5) {
  char test_9[8] = "";
  char test_10[] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(test_9, test_10, n),
                   strncpy(test_9, test_10, n));
}
END_TEST

START_TEST(strncpy_6) {
  char test_11[10] = " ";
  char test_12[] = " ";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(test_11, test_12, n),
                   strncpy(test_11, test_12, n));
}
END_TEST

Suite *suite_s21_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("tc_strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);

  suite_add_tcase(s, tc);
  return s;
}

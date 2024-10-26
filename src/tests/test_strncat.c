#include "testing.h"

START_TEST(strncat_1) {
  char test_1[5] = "<<<";
  char test_2[2] = "5";
  char test_3[5] = "<<<";
  char test_4[2] = "5";
  s21_size_t n = 1;
  ck_assert_str_eq(strncat(test_1, test_2, n), strncat(test_3, test_4, n));
}
END_TEST

START_TEST(strncat_2) {
  char test_3[4] = "5";
  char test_4[2] = "";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(test_3, test_4, n), strncat(test_3, test_4, n));
}
END_TEST

START_TEST(strncat_3) {
  char test_5[5] = "";
  char test_6[5] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncat(test_5, test_6, n), strncat(test_5, test_6, n));
}
END_TEST

START_TEST(strncat_4) {
  char test_7[9] = " ";
  char test_8[9] = " ";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(test_7, test_8, n), strncat(test_7, test_8, n));
}
END_TEST

START_TEST(strncat_5) {
  char test_9[9] = "abcde";
  char test_10[9] = "fgh";
  char test_11[9] = "abcde";
  char test_12[9] = "fgh";
  s21_size_t n = 2;
  ck_assert_str_eq(s21_strncat(test_9, test_10, n),
                   strncat(test_11, test_12, n));
}
END_TEST

Suite *suite_s21_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("tc_strncat");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);

  suite_add_tcase(s, tc);
  return s;
}

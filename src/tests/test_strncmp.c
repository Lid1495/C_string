#include "testing.h"

START_TEST(test_s21_strncmp_1) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), 0);
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char str1[] = "abc";
  char str2[] = "def";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) < 0, 1);
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char str1[] = "def";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) > 0, 1);
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char str1[] = "abc";
  char str2[] = "abcd";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4) < 0, 1);
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char str1[] = "abcd";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4) > 0, 1);
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), 0);
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char str1[] = "";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1) < 0, 1);
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1) > 0, 1);
}
END_TEST

Suite *suite_s21_strncmp(void) {
  Suite *s = suite_create("suite_s21_strncmp");
  TCase *tc = tcase_create("tc_s21_strncmp");

  tcase_add_test(tc, test_s21_strncmp_1);
  tcase_add_test(tc, test_s21_strncmp_2);
  tcase_add_test(tc, test_s21_strncmp_3);
  tcase_add_test(tc, test_s21_strncmp_4);
  tcase_add_test(tc, test_s21_strncmp_5);
  tcase_add_test(tc, test_s21_strncmp_6);
  tcase_add_test(tc, test_s21_strncmp_7);
  tcase_add_test(tc, test_s21_strncmp_8);
  tcase_add_test(tc, test_s21_strncmp_9);
  tcase_add_test(tc, test_s21_strncmp_10);

  suite_add_tcase(s, tc);
  return s;
}

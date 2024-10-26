#include "testing.h"

START_TEST(strchr_1) {
#line 1461
  char str1[] = "abc";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_2) {
#line 1466
  char str1[] = "abc";
  int n = 'd';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_3) {
#line 1471
  char str1[] = "abc";
  int n = '1';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_4) {
#line 1476
  char str1[] = "abc";
  int n = '\\';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_5) {
#line 1481
  char str1[] = "";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_6) {
#line 1486
  char str1[] = " ";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_7) {
#line 1491
  char str1[] = " ";
  int n = ' ';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_8) {
#line 1496
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_9) {
#line 1501
  char str1[] = "021";
  int n = '0';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(strchr_10) {
#line 1506
  char str1[] = "ab\nc";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

Suite *suite_s21_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("tc_strchr");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);

  suite_add_tcase(s, tc);
  return s;
}
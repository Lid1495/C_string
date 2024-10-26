#include "testing.h"

START_TEST(strrchr_1) {
#line 2749
  char str1[] = "abc";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_2) {
#line 2754
  char str1[] = "abc";
  int n = 'd';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_3) {
#line 2759
  char str1[] = "abc";
  int n = '1';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_4) {
#line 2764
  char str1[] = "abc";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_5) {
#line 2769
  char str1[] = "";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_6) {
#line 2774
  char str1[] = " ";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_7) {
#line 2779
  char str1[] = " ";
  int n = ' ';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_8) {
#line 2784
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

Suite *suite_s21_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("tc_strrchr");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);

  suite_add_tcase(s, tc);
  return s;
}
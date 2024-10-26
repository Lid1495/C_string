#include "testing.h"

START_TEST(strcspn_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *suite_s21_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("tc_strcspn");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  //   tcase_add_test(tc, strcspn_5);
  //   tcase_add_test(tc, strcspn_6);
  //   tcase_add_test(tc, strcspn_7);
  //   tcase_add_test(tc, strcspn_8);
  //   tcase_add_test(tc, strcspn_9);
  //   tcase_add_test(tc, strcspn_10);
  //   tcase_add_test(tc, strcspn_11);
  //   tcase_add_test(tc, strcspn_12);
  //   tcase_add_test(tc, strcspn_13);
  //   tcase_add_test(tc, strcspn_14);

  suite_add_tcase(s, tc);
  return s;
}

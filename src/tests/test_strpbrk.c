#include "testing.h"

START_TEST(strpbrk_1) {
#line 2549
  char str1[] = "this is a test";
  char str2[] = "this";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
#line 2554
  char str1[] = "this is a test";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
#line 2559
  char str1[] = "abc";
  char str2[] = "ccc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
#line 2564
  char str1[] = "abc123";
  char str2[] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
#line 2569
  char str1[] = "abglk1erw233c";
  char str2[] = "321";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
#line 2574
  char str1[] = "ab\nc";
  char str2[] = "\n";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
#line 2579
  char str1[] = "a8yuoiytu5u6rtyfkguhubc";
  char str2[] = "123i6t5";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
#line 2584
  char str1[] = "a77777bc";
  char str2[] = "177723";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_s21_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);

  suite_add_tcase(s, tc);
  return s;
}
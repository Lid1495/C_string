#include "testing.h"

START_TEST(memcpy_1) {
  char test_1[10] = "12345";
  char test_2[] = " ";
  s21_size_t n = 2;
  ck_assert_str_eq(s21_memcpy(test_1, test_2, n), memcpy(test_1, test_2, n));
}
END_TEST

START_TEST(memcpy_2) {
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  s21_size_t n = 6;
  ck_assert_str_eq(s21_memcpy(test_3, test_4, n), memcpy(test_3, test_4, n));
}
END_TEST

START_TEST(memcpy_3) {
  char test_5[30] = "";
  char test_6[] = "4444";
  s21_size_t n = 4;
  ck_assert_str_eq(s21_memcpy(test_5, test_6, n), memcpy(test_5, test_6, n));
}
END_TEST

START_TEST(memcpy_4) {
  char test_5[30] = "";
  char test_7[] = "123\0123";
  s21_size_t n = 6;
  ck_assert_str_eq(s21_memcpy(test_5, test_7, n), memcpy(test_5, test_7, n));
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("tc_memcpy");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);

  suite_add_tcase(s, tc);
  return s;
}

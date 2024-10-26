#include "testing.h"

START_TEST(normal_string) {
  char* str = "hello!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(start_nullterm) {
  char* str = "\0dqwdq!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(middle_nullterm) {
  char* str = "qdwdq\0dwq!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(chaos_string) {
  char* str = "\n0\n\\n\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite* suite_s21_strlen(void) {
  Suite* s = suite_create("suite_strlen");
  TCase* tc = tcase_create("tc_strlen");

  tcase_add_test(tc, normal_string);
  tcase_add_test(tc, start_nullterm);
  tcase_add_test(tc, middle_nullterm);
  tcase_add_test(tc, chaos_string);

  suite_add_tcase(s, tc);

  return s;
}

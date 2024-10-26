#include "testing.h"

START_TEST(trim_probels) {
  char* src = "  Hello  ";
  char* trim_chars = " ";
  char* rez = "Hello";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_nothing_to_trim) {
  char* src = "Hello";
  char* trim_chars = " ";
  char* rez = "Hello";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_other_symbol) {
  char* src = "-----Hello-----";
  char* trim_chars = "-";
  char* rez = "Hello";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_nothing_to_trim_from_left) {
  char* src = "   Hello";
  char* trim_chars = " ";
  char* rez = "Hello";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_nothing_to_trim_from_right) {
  char* src = "Hello ";
  char* trim_chars = " ";
  char* rez = "Hello";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_nothing_trim_char_not_included) {
  char* src = "  Hello ";
  char* trim_chars = "-";
  char* rez = "  Hello ";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_empty_trim_chars) {
  char* src = "  Hello ";
  char* trim_chars = "";
  char* rez = "  Hello ";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_everything_will_be_trimed) {
  char* src = "@@@@@@@@@@";
  char* trim_chars = "@";
  char* rez = "";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_symbol_in_the_middle) {
  char* src = "baby baby baby oooob";
  char* trim_chars = "b";
  char* rez = "aby baby baby oooo";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(trim_null_src) {
  char* src = s21_NULL;
  char* trim_chars = " ";
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

START_TEST(trim_null_trim_chars) {
  char* src = "bobaba";
  char* trim_chars = s21_NULL;
  char* rez_s21 = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

Suite* suite_s21_trim(void) {
  Suite* s = suite_create("suite_trim");
  TCase* tc = tcase_create("tc_trim");

  tcase_add_test(tc, trim_probels);
  tcase_add_test(tc, trim_nothing_to_trim);
  tcase_add_test(tc, trim_other_symbol);
  tcase_add_test(tc, trim_nothing_to_trim_from_left);
  tcase_add_test(tc, trim_nothing_to_trim_from_right);
  tcase_add_test(tc, trim_nothing_trim_char_not_included);
  tcase_add_test(tc, trim_empty_trim_chars);
  tcase_add_test(tc, trim_everything_will_be_trimed);
  tcase_add_test(tc, trim_symbol_in_the_middle);
  tcase_add_test(tc, trim_null_src);
  tcase_add_test(tc, trim_null_trim_chars);

  suite_add_tcase(s, tc);

  return s;
}

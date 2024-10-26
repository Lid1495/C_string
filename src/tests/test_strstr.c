#include "testing.h"

START_TEST(test_sovpadenie) {
  char haystack[] = "Hello world";
  char needle[] = "ld";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_net_sovpadeniya) {
  char haystack[] = "Hello world";
  char needle[] = "ququshka";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);

  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_term_null) {
  char haystack[] = "Hello world";
  char needle[] = "\0";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_term_null_2) {
  char haystack[] = "Hello world\0\0";
  char needle[] = "\0";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_term_null_3) {
  char haystack[] = "\0\0";
  char needle[] = "\0";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_slash_n) {
  char haystack[] = "\n\0";
  char needle[] = "\0";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_slash_n2) {
  char haystack[] = "perenos\n\0";
  char needle[] = "\n\0";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_sovpadenie_neskolko) {
  char haystack[] = "perenos perenos perenos";
  char needle[] = "perenos";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_empty_needle) {
  char haystack[] = "bububu bababarashka";
  char needle[] = "";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_empty_haystack) {
  char haystack[] = "";
  char needle[] = "gde?";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_neddle_more_than_haystack) {
  char haystack[] = "a tut malo informacii";
  char needle[] = "a tut slishkom mnogo vsego sobrano hahahaha";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

START_TEST(test_needle_with_term_null) {
  char haystack[] = "hello world";
  char needle[] = "hello\0world";

  char *rez1 = s21_strstr(haystack, needle);
  char *rez2 = strstr(haystack, needle);
  ck_assert_ptr_eq(rez1, rez2);
}
END_TEST

Suite *suite_s21_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("tc_strstr");

  tcase_add_test(tc, test_sovpadenie);
  tcase_add_test(tc, test_net_sovpadeniya);
  tcase_add_test(tc, test_term_null);
  tcase_add_test(tc, test_term_null_2);
  tcase_add_test(tc, test_term_null_3);
  tcase_add_test(tc, test_slash_n);
  tcase_add_test(tc, test_slash_n2);
  tcase_add_test(tc, test_sovpadenie_neskolko);
  tcase_add_test(tc, test_empty_needle);
  tcase_add_test(tc, test_empty_haystack);
  tcase_add_test(tc, test_neddle_more_than_haystack);
  tcase_add_test(tc, test_needle_with_term_null);

  suite_add_tcase(s, tc);
  return s;
}

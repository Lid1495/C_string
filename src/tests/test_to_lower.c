/*
код с# для проверки оригинальной функции ToLower
using System;
class HelloWorld {
  static void Main() {

    string text = "abcDeE!443 HedUU6ZSl0";
    string text2 = text.ToLower();

Console.WriteLine(text2);
  }
}
*/

#include "testing.h"

START_TEST(lower_string) {
  char* str1 = "pupu ququ";
  char* str2 = "pupu ququ";

  char* str3 = s21_to_lower(str1);

  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(upper_string) {
  char* str1 = "BARA BARA BERE BERE";
  char* str2 = "bara bara bere bere";
  char* str3 = s21_to_lower(str1);

  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(different_string) {
  char* str1 = "abcDeE!443 HedUU6ZSl0";
  char* str2 = "abcdee!443 heduu6zsl0";
  char* str3 = s21_to_lower(str1);

  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(empty_string) {
  char* str1 = "";
  char* str2 = "";
  char* str3 = s21_to_lower(str1);

  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(null_string) {
  char* str1 = s21_NULL;
  char* str3 = s21_to_lower(str1);

  ck_assert_ptr_eq(str3, s21_NULL);
}
END_TEST

Suite* suite_s21_to_lower(void) {
  Suite* s = suite_create("suite_to_lower");
  TCase* tc = tcase_create("tc_to_lower");

  tcase_add_test(tc, lower_string);
  tcase_add_test(tc, upper_string);
  tcase_add_test(tc, different_string);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, null_string);

  suite_add_tcase(s, tc);
  return s;
}

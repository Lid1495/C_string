/*
код для с# компилятора:
using System;
class HelloWorld {
  static void Main() {
    string text = "Hello";
string substring = "World";

text = text.Insert(0, substring);

Console.WriteLine(text);
  }
}
 */

#include "testing.h"

START_TEST(insert_to_end) {
  char* src = "Hello";
  char* str = "World";
  char* rez = "HelloWorld";
  s21_size_t index = 5;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_to_begin) {
  char* src = "Hello";
  char* str = "World";
  char* rez = "WorldHello";
  s21_size_t index = 0;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_to_middle) {
  char* src = "Hello";
  char* str = "World";
  char* rez = "HelWorldlo";
  s21_size_t index = 3;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_empty_str) {
  char* src = "Hello";
  char* str = "";
  char* rez = "Hello";
  s21_size_t index = 2;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_empty_src) {
  char* src = "";
  char* str = "World";
  char* rez = "World";
  s21_size_t index = 0;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_all_empty) {
  char* src = "";
  char* str = "";
  char* rez = "";
  s21_size_t index = 0;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_str_eq(rez_s21, rez);
}
END_TEST

START_TEST(insert_null_str) {
  char* src = "Hello";
  char* str = s21_NULL;
  s21_size_t index = 3;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

START_TEST(insert_null_src) {
  char* src = s21_NULL;
  char* str = "World";
  s21_size_t index = 3;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

START_TEST(insert_all_null) {
  char* src = s21_NULL;
  char* str = s21_NULL;
  s21_size_t index = 0;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

START_TEST(insert_too_high_index) {
  char* src = "Hello";
  char* str = "World";
  s21_size_t index = 15;
  char* rez_s21 = s21_insert(src, str, index);

  ck_assert_ptr_eq(rez_s21, s21_NULL);
}
END_TEST

Suite* suite_s21_insert(void) {
  Suite* s = suite_create("suite_insert");
  TCase* tc = tcase_create("tc_insert");

  tcase_add_test(tc, insert_to_end);
  tcase_add_test(tc, insert_to_begin);
  tcase_add_test(tc, insert_to_middle);
  tcase_add_test(tc, insert_empty_str);
  tcase_add_test(tc, insert_empty_src);
  tcase_add_test(tc, insert_all_empty);
  tcase_add_test(tc, insert_null_str);
  tcase_add_test(tc, insert_null_src);
  tcase_add_test(tc, insert_all_null);
  tcase_add_test(tc, insert_too_high_index);

  suite_add_tcase(s, tc);

  return s;
}

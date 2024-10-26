#include "testing.h"

START_TEST(test1) {
  char* src = "123456";
  char ch = '4';
  s21_size_t size = 6;
  char* res1 = s21_memchr(src, ch, size);
  char* res2 = memchr(src, ch, size);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test2) {
  char* src = "123456";
  char ch = '7';
  s21_size_t size = 6;
  char* res1 = s21_memchr(src, ch, size);
  char* res2 = memchr(src, ch, size);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(test3) {
  char* src = "hello/\0";
  char ch = 'h';
  s21_size_t size = 6;
  char* res1 = s21_memchr(src, ch, size);
  char* res2 = memchr(src, ch, size);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test4) {
  char* src = "hello/\0";
  char ch = '/';
  s21_size_t size = 6;
  char* res1 = s21_memchr(src, ch, size);
  char* res2 = memchr(src, ch, size);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite* suite_s21_memchr(void) {
  Suite* s =
      suite_create("suite_memchr");  // формулировка suite_НАЗВАНИЕФУНКЦИИ
  TCase* tc = tcase_create("tc_memchr");  //  формулировка tc_НАЗВАНИЕФУНКЦИИ

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);

  suite_add_tcase(s, tc);
  return s;
}
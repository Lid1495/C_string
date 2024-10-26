#include "testing.h"

START_TEST(test_s21_strerror_normal) {
  for (int i = 0; i < 40; i++) {
    char *s21_error = s21_strerror(i);
    char *std_error = strerror(i);
    ck_assert_str_eq(s21_error, std_error);
  }
}
END_TEST

Suite *suite_s21_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, test_s21_strerror_normal);

  suite_add_tcase(s, tc);
  return s;
}
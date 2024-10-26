#include "testing.h"

int test(Suite *function) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = function;
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(void) {
  Suite *fuctions[] = {suite_s21_memchr(),    // ok
                       suite_s21_memcmp(),    // ok |
                       suite_s21_memcpy(),    // ok
                       suite_s21_memset(),    // ok
                       suite_s21_sprintf(),   // ok
                       suite_s21_strerror(),  // ok
                       suite_s21_strchr(),    // ok
                       suite_s21_strcspn(),   // ok
                       suite_s21_strlen(),    // ok
                       suite_s21_strncat(),   // ok
                       suite_s21_strncmp(),   // ok
                       suite_s21_strncpy(),   // ok
                       suite_s21_strpbrk(),   // ok
                       suite_s21_strrchr(),   // ok
                       suite_s21_strstr(),    // ok
                       suite_s21_strtok(),    // ok
                       suite_s21_insert(),    // ok
                       suite_s21_to_lower(),  // ok |
                       suite_s21_to_upper(),  // ok |
                       suite_s21_trim(),      // ok
                       NULL};
  int count = 0;
  for (Suite **current_test = fuctions; *current_test != NULL; current_test++) {
    if (test(*current_test) == EXIT_FAILURE) {
      printf("Test %d failed\n", count + 1);
    }
    count++;
  }
  return 0;
}
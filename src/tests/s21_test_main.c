#include "./s21_test_main.h"

int main() {
  int failed = 0;
  Suite *s21_test_main[] = {test_is_equal(),
                            test_is_not_equal(),
                            test_is_greater(),
                            test_comparision_other(),
                            test_floor(),
                            test_round(),
                            test_truncate(),
                            test_negate(),
                            test_s21_from_int_to_decimal(),
                            test_s21_from_float_to_decimal(),
                            test_s21_from_decimal_to_int(),
                            test_s21_from_decimal_to_float(),
                            test_s21_add(),
                            test_s21_sub(),
                            test_s21_mul(),
                            test_s21_div(),
                            NULL};
  for (int i = 0; s21_test_main[i] != NULL; i++) {
    printf("\033[46m/start\033[0m ");
    SRunner *sr = srunner_create(s21_test_main[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return 0;
}

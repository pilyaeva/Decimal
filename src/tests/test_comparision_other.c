#include "./s21_test_main.h"

START_TEST(is_less) {
  s21_decimal value_1 = {{0x00000034, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000055, 0x00000000, 0x00000000, 0x00000000}};
  int res = s21_is_less(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal) {
  s21_decimal value_1 = {{0x00000034, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000034, 0x00000000, 0x00000000, 0x00000000}};
  int res = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal) {
  s21_decimal value_1 = {{0x00000034, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000034, 0x00000000, 0x00000000, 0x00000000}};
  int res = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_comparision_other(void) {
  Suite *s = suite_create("\033[44m-=S21_COMPARISION_OTHER=-\033[0m");
  TCase *tc = tcase_create("s21_eq_decimal_tc");

  tcase_add_test(tc, is_less);
  tcase_add_test(tc, is_less_or_equal);
  tcase_add_test(tc, is_greater_or_equal);

  suite_add_tcase(s, tc);
  return s;
}

#include "./s21_test_main.h"

START_TEST(is_not_equal_1) {
  s21_decimal value_1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int res = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal value_1 = {{0x00000000, 0xF0F00000, 0xFF000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000000, 0xF0F00000, 0xF0000000, 0x00000000}};
  int res = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("\033[44m-=S21_IS_NOT_EQUAL=-\033[0m");
  TCase *tc = tcase_create("s21_eq_decimal_tc");

  tcase_add_test(tc, is_not_equal_1);
  tcase_add_test(tc, is_not_equal_2);

  suite_add_tcase(s, tc);
  return s;
}

#include "./s21_test_main.h"

START_TEST(is_greater_1) {
  s21_decimal value_1 = {{0x00000056, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000056, 0x00000000, 0x00000000, 0x00000000}};
  int res = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal value_1 = {{0x90000057, 0x00000000, 0x00000000, 0x00040000}};
  s21_decimal value_2 = {{0x90000056, 0x00000000, 0x00000000, 0x00040000}};
  int res = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal value_1 = {{0x90000057, 0x00000000, 0x00000000, 0x00050000}};
  s21_decimal value_2 = {{0x90000056, 0x00000000, 0x00000000, 0x00040000}};
  int res = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal value_1 = {{0x90000057, 0x00000000, 0x00000000, 0x80050000}};
  s21_decimal value_2 = {{0x90000056, 0x00000000, 0x00000000, 0x80040000}};
  int res = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal value_1 = {{0x00000057, 0x00000000, 0x00000000, 0x00050000}};
  s21_decimal value_2 = {{0x00000056, 0x00000000, 0x00000000, 0x80040000}};
  int res = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_is_greater(void) {
  Suite *s = suite_create("\033[44m-=S21_IS_GREATER=-\033[0m");
  TCase *tc = tcase_create("s21_eq_decimal_tc");

  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);

  suite_add_tcase(s, tc);
  return s;
}

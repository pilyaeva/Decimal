#include "./s21_test_main.h"

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal expected = {{9, 0, 0, 0}};
  s21_set_sign(&expected, 1);
  s21_set_exp(&expected, 1);
  float src = -0.9;
  int returned = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(s21_is_equal(expected, dst), TRUE);
  ck_assert_int_eq(returned, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};
  s21_set_exp(&expected, 1);
  float src = 0.1;
  int returned = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(s21_is_equal(expected, dst), TRUE);
  ck_assert_int_eq(returned, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal expected = {{5, 0, 0, 0}};
  s21_set_exp(&expected, 5);
  float src = 0.00005;
  int returned = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(s21_is_equal(expected, dst), TRUE);
  ck_assert_int_eq(returned, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal expected = {{5, 0, 0, 0}};
  s21_set_exp(&expected, 5);
  float src = 0.5;
  s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(s21_is_equal(expected, dst), FALSE);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  float src = 0.5;
  int returned = s21_from_float_to_decimal(src, NULL);
  ck_assert_int_eq(returned, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int returned = s21_from_float_to_decimal((float)NAN, &dst);
  ck_assert_int_eq(returned, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int returned = s21_from_float_to_decimal((float)INFINITY, &dst);
  ck_assert_int_eq(returned, 1);
}
END_TEST

Suite *test_s21_from_float_to_decimal() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[44m-=S21_Float_to_Decimal=-\033[0m");
  tc_core = tcase_create("s21_from_float_to_decimal");
  tcase_add_test(tc_core, s21_from_float_to_decimal_1);
  tcase_add_test(tc_core, s21_from_float_to_decimal_2);
  tcase_add_test(tc_core, s21_from_float_to_decimal_3);
  tcase_add_test(tc_core, s21_from_float_to_decimal_4);
  tcase_add_test(tc_core, s21_from_float_to_decimal_5);
  tcase_add_test(tc_core, s21_from_float_to_decimal_6);
  tcase_add_test(tc_core, s21_from_float_to_decimal_7);
  suite_add_tcase(s, tc_core);
  return s;
}

#include "./s21_test_main.h"

START_TEST(negativ) {
  s21_decimal src = {{9, 0, 0, 0}};
  s21_set_sign(&src, MINUS);
  s21_set_exp(&src, 1);
  float result;
  float expected = -0.9;
  int returned = s21_from_decimal_to_float(src, &result);
  ck_assert_float_eq(result, expected);
  ck_assert_int_eq(returned, OK_CONVERSATION);
}
END_TEST

START_TEST(positiv) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_set_exp(&src, 1);
  float result;
  float expected = 0.1;
  int returned = s21_from_decimal_to_float(src, &result);
  ck_assert_float_eq(result, expected);
  ck_assert_int_eq(returned, OK_CONVERSATION);
}
END_TEST

START_TEST(small) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_set_exp(&src, 5);
  float result;
  float expected = 0.00001;
  int returned = s21_from_decimal_to_float(src, &result);
  ck_assert_float_eq(result, expected);
  ck_assert_int_eq(returned, OK_CONVERSATION);
}
END_TEST

START_TEST(null) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_set_exp(&src, 1);
  int returned = s21_from_decimal_to_float(src, NULL);
  ck_assert_int_eq(returned, CONVERTION_ERROR);
}
END_TEST

Suite *test_s21_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[44m-=S21_Decimal_to_Float=-\033[0m");
  tc_core = tcase_create("s21_from_decimal_to_float");
  tcase_add_test(tc_core, negativ);
  tcase_add_test(tc_core, positiv);
  tcase_add_test(tc_core, small);
  tcase_add_test(tc_core, null);
  suite_add_tcase(s, tc_core);
  return s;
}

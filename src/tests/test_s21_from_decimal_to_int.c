#include "./s21_test_main.h"

START_TEST(test_positive) {
  s21_decimal src = {{21, 0, 0, 0}};
  int result;
  int res = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result, 21);
}
END_TEST

START_TEST(test_negative) {
  s21_decimal src = {{21, 0, 0, 0x80000000}};
  int result;
  int res = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result, -21);
}
END_TEST

START_TEST(test_zero) {
  s21_decimal src = {{0, 0, 0, 0}};
  int result;
  int res = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_null) {
  s21_decimal src = {{21, 0, 0, 0}};
  int res = s21_from_decimal_to_int(src, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_s21_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[44m-=S21_Decimal_to_Int=-\033[0m");
  TCase *tc = tcase_create("s21_from_decimal_to_int");

  tcase_add_test(tc, test_positive);
  tcase_add_test(tc, test_negative);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_null);

  suite_add_tcase(s, tc);
  return s;
}

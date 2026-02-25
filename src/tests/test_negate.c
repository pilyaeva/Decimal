#include "./s21_test_main.h"

START_TEST(negate_positive_to_negative) {
  s21_decimal value = {{0b1011001100110, 0x00000000, 0x00000000, 12 << 16}};
  s21_decimal actual_result;
  s21_negate(value, &actual_result);
  s21_decimal expected_result = {
      {0b1011001100110, 0x00000000, 0x00000000, (1 << 31) | (12 << 16)}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

START_TEST(negate_negative_to_positive) {
  s21_decimal value = {
      {0b1011001100110, 0x00000000, 0x00000000, (1 << 31) | (12 << 16)}};
  s21_decimal actual_result;
  s21_negate(value, &actual_result);
  s21_decimal expected_result = {
      {0b1011001100110, 0x00000000, 0x00000000, 12 << 16}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("\033[44m-=S21_NEGATE=-\033[0m");
  TCase *tc = tcase_create("s21_negate_decimal_tc");

  tcase_add_test(tc, negate_positive_to_negative);
  tcase_add_test(tc, negate_negative_to_positive);

  suite_add_tcase(s, tc);
  return s;
}
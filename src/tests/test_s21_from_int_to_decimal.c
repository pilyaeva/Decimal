#include "./s21_test_main.h"

START_TEST(test_positive) {
  s21_decimal result;
  int res = s21_from_int_to_decimal(21, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(result.bits[0], 21);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_negative) {
  s21_decimal result;
  int ret = s21_from_int_to_decimal(-21, &result);
  ck_assert_int_eq(ret, 0);
  uint32_t expected_bits[4] = {21, 0, 0, 0x80000000};
  ck_assert_mem_eq(result.bits, expected_bits, sizeof(expected_bits));
}
END_TEST

START_TEST(test_zero) {
  s21_decimal result;
  int res = s21_from_int_to_decimal(0, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_max_int) {
  s21_decimal result;
  int res = s21_from_int_to_decimal(2147483647, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(result.bits[0], 2147483647);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_min_int) {
  s21_decimal result;
  int res = s21_from_int_to_decimal(-2147483648, &result);
  ck_assert_int_eq(res, 0);
  uint32_t expected_bits[4] = {2147483648, 0, 0, 0x80000000};
  ck_assert_mem_eq(result.bits, expected_bits, sizeof(expected_bits));
}
END_TEST

START_TEST(test_null) {
  int res = s21_from_int_to_decimal(21, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_s21_from_int_to_decimal(void) {
  Suite *s = suite_create("\033[44m-=S21_Int_to_Decimal=-\033[0m");
  TCase *tc = tcase_create("s21_from_int_to_decimal");

  tcase_add_test(tc, test_positive);
  tcase_add_test(tc, test_negative);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_max_int);
  tcase_add_test(tc, test_min_int);
  tcase_add_test(tc, test_null);

  suite_add_tcase(s, tc);
  return s;
}
#include "./s21_test_main.h"

START_TEST(round_174129448123701dot2475184625_to_174129448123701_positive) {
  s21_decimal value = {{0xA05285F1, 0xC3524F80, 0x170BB, 10 << 16}};
  s21_decimal actual_result;
  s21_round(value, &actual_result);
  s21_decimal expected_result = {{0xABE67D35, 0x9E5E, 0, 0}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

START_TEST(round_174129448123701dot2475184625_to_174129448123701_negative) {
  s21_decimal value = {
      {0xA05285F1, 0xC3524F80, 0x170BB, (1 << 31) | (10 << 16)}};
  s21_decimal actual_result;
  s21_round(value, &actual_result);
  s21_decimal expected_result = {{0xABE67D35, 0x9E5E, 0, 1 << 31}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

START_TEST(round_174129448123701dot5475184625_to_174129448123702_positive) {
  s21_decimal value = {{0x5322E3F1, 0xC3524F81, 0x170BB, 10 << 16}};
  s21_decimal actual_result;
  s21_round(value, &actual_result);
  s21_decimal expected_result = {{0xABE67D36, 0x9E5E, 0, 0}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

START_TEST(round_174129448123701dot5475184625_to_174129448123702_negative) {
  s21_decimal value = {
      {0x5322E3F1, 0xC3524F81, 0x170BB, (1 << 31) | (10 << 16)}};
  s21_decimal actual_result;
  s21_round(value, &actual_result);
  s21_decimal expected_result = {{0xABE67D36, 0x9E5E, 0, 1 << 31}};
  ck_assert_mem_eq(&actual_result, &expected_result, sizeof(s21_decimal));
}
END_TEST

Suite *test_round(void) {
  Suite *s = suite_create("\033[44m-=S21_ROUND=-\033[0m");
  TCase *tc = tcase_create("s21_round_decimal_tc");

  tcase_add_test(
      tc, round_174129448123701dot2475184625_to_174129448123701_positive);
  tcase_add_test(
      tc, round_174129448123701dot2475184625_to_174129448123701_negative);
  tcase_add_test(
      tc, round_174129448123701dot5475184625_to_174129448123702_positive);
  tcase_add_test(
      tc, round_174129448123701dot5475184625_to_174129448123702_negative);

  suite_add_tcase(s, tc);
  return s;
}
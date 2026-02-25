#include "./s21_test_main.h"

START_TEST(s21_decimal_div_1) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal value_2 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  ck_assert_uint_eq(DELETE_BY_ZERO, s21_div(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_div_2) {
  s21_decimal value_1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_3) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00000005, 0x00000000, 0x00000000, 0x80010000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_4) {
  s21_decimal value_1 = {{0x0000A000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0x50000000, 0x36B90BE5, 0xA18F07D7, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_5) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_6) {
  s21_decimal value_1 = {{0x55555555, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000}};
  s21_decimal res;
  s21_decimal predict = {{0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_int_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_7) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0X79CD9001, 0X0000082F, 0X00000000, 0x800D0000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_LOW, s21_div(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_div_8) {
  s21_decimal value_1 = {{0xFFFFFFF, 0x0, 0x0, 0x00000}};
  s21_decimal value_2 = {{0x2, 0x0, 0x0, 0x00000}};
  s21_decimal res;
  s21_decimal predict = {{0x4FFFFFFB, 0x0, 0x0, 0x010000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_int_eq(res.bits[0], predict.bits[0]);
  ck_assert_int_eq(res.bits[1], predict.bits[1]);
  ck_assert_int_eq(res.bits[2], predict.bits[2]);
  ck_assert_int_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_9) {
  s21_decimal value_1 = {{0x7, 0x0, 0x0, 0x1C0000}};
  s21_decimal value_2 = {{0x7, 0x0, 0x0, 0x00000}};
  s21_decimal res;
  s21_decimal predict = {{0x1, 0x0, 0x0, 0x01C0000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_int_eq(res.bits[0], predict.bits[0]);
  ck_assert_int_eq(res.bits[1], predict.bits[1]);
  ck_assert_int_eq(res.bits[2], predict.bits[2]);
  ck_assert_int_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_10) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X1, 0X0, 0X0, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_div(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_div_11) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X1, 0X0, 0X0, 0x801C0000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_div(value_1, value_2, &res));
}
END_TEST

Suite *test_s21_div(void) {
  Suite *s = suite_create("\033[44m-=S21_DIV=-\033[0m");
  TCase *tc = tcase_create("s21_div_decimal_tc");

  tcase_add_test(tc, s21_decimal_div_1);
  tcase_add_test(tc, s21_decimal_div_2);
  tcase_add_test(tc, s21_decimal_div_3);
  tcase_add_test(tc, s21_decimal_div_4);
  tcase_add_test(tc, s21_decimal_div_5);
  tcase_add_test(tc, s21_decimal_div_6);
  tcase_add_test(tc, s21_decimal_div_7);
  tcase_add_test(tc, s21_decimal_div_8);
  tcase_add_test(tc, s21_decimal_div_9);
  tcase_add_test(tc, s21_decimal_div_10);
  tcase_add_test(tc, s21_decimal_div_11);

  suite_add_tcase(s, tc);
  return s;
}
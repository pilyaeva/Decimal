#include "./s21_test_main.h"

START_TEST(s21_decimal_add_1) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00003000, 0x00000000, 0x00000000, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_2) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00003000, 0x00000000, 0x00000000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_3) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF8, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_4) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X0, 0X0, 0X0, 0x001B0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_5) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFE8, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_6) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFE8, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_7) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF8, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_8) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_LOW, s21_add(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_add_9) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_add(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_add_10) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0X0, 0X0, 0X0, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_add_11) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0X0, 0X0, 0X0, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_add(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

Suite *test_s21_add(void) {
  Suite *s = suite_create("\033[44m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("s21_add_decimal_tc");

  tcase_add_test(tc, s21_decimal_add_1);
  tcase_add_test(tc, s21_decimal_add_2);
  tcase_add_test(tc, s21_decimal_add_3);
  tcase_add_test(tc, s21_decimal_add_4);
  tcase_add_test(tc, s21_decimal_add_5);
  tcase_add_test(tc, s21_decimal_add_6);
  tcase_add_test(tc, s21_decimal_add_7);
  tcase_add_test(tc, s21_decimal_add_8);
  tcase_add_test(tc, s21_decimal_add_9);
  tcase_add_test(tc, s21_decimal_add_10);
  tcase_add_test(tc, s21_decimal_add_11);

  suite_add_tcase(s, tc);
  return s;
}

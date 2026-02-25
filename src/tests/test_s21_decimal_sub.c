#include "./s21_test_main.h"

START_TEST(s21_decimal_sub_1) {
  s21_decimal value_1 = {{0x00003000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00001000, 0x00000000, 0x00000000, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_2) {
  s21_decimal value_1 = {{0x00003000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00001000, 0x00000000, 0x00000000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_3) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFE8, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_4) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X0, 0X0, 0X0, 0x001B0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_5) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF8, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_6) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFF8, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_7) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFE8, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_8) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0X0, 0X0, 0X0, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_9) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0X0, 0X0, 0X0, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_sub(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_sub_10) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;

  ck_assert_uint_eq(TOO_LOW, s21_sub(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_sub_11) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_sub(value_1, value_2, &res));
}
END_TEST

Suite *test_s21_sub(void) {
  Suite *s = suite_create("\033[44m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("s21_sub_decimal_tc");

  tcase_add_test(tc, s21_decimal_sub_1);
  tcase_add_test(tc, s21_decimal_sub_2);
  tcase_add_test(tc, s21_decimal_sub_3);
  tcase_add_test(tc, s21_decimal_sub_4);
  tcase_add_test(tc, s21_decimal_sub_5);
  tcase_add_test(tc, s21_decimal_sub_6);
  tcase_add_test(tc, s21_decimal_sub_7);
  tcase_add_test(tc, s21_decimal_sub_8);
  tcase_add_test(tc, s21_decimal_sub_9);
  tcase_add_test(tc, s21_decimal_sub_10);
  tcase_add_test(tc, s21_decimal_sub_11);

  suite_add_tcase(s, tc);
  return s;
}

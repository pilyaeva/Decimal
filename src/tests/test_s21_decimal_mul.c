#include "./s21_test_main.h"

START_TEST(s21_decimal_mul1) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal value_2 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul2) {
  s21_decimal value_1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul3) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x02000000, 0x00000000, 0x00000000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul4) {
  s21_decimal value_1 = {{0x00001000, 0x00000000, 0x00000001, 0x00000000}};
  s21_decimal value_2 = {{0x00002000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal res;
  s21_decimal predict = {{0x02000000, 0x00000000, 0x00002000, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul5) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_LOW, s21_mul(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_mul6) {
  s21_decimal value_1 = {{0XFFFFFFF0, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x801C0000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_mul(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_mul7) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X79CD9001, 0X0000082F, 0X00000000, 0x800D0000}};
  s21_decimal res;
  s21_decimal predict = {{0XCEAFDCE7, 0X66828C28, 0XE6666666, 0x00000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul8) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_mul(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_mul9) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  ck_assert_uint_eq(TOO_HIGH, s21_mul(value_1, value_2, &res));
}
END_TEST

START_TEST(s21_decimal_mul10) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X1, 0X0, 0X0, 0x00000000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

START_TEST(s21_decimal_mul11) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0X1, 0X0, 0X0, 0x801C0000}};
  s21_decimal res;
  s21_decimal predict = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  ck_assert_uint_eq(OK_OPERATION, s21_mul(value_1, value_2, &res));
  ck_assert_uint_eq(res.bits[0], predict.bits[0]);
  ck_assert_uint_eq(res.bits[1], predict.bits[1]);
  ck_assert_uint_eq(res.bits[2], predict.bits[2]);
  ck_assert_uint_eq(res.bits[3], predict.bits[3]);
}
END_TEST

Suite *test_s21_mul(void) {
  Suite *s = suite_create("\033[44m-=S21_MUL=-\033[0m");
  TCase *tc = tcase_create("s21_mul_decimal_tc");

  tcase_add_test(tc, s21_decimal_mul1);
  tcase_add_test(tc, s21_decimal_mul2);
  tcase_add_test(tc, s21_decimal_mul3);
  tcase_add_test(tc, s21_decimal_mul4);
  tcase_add_test(tc, s21_decimal_mul5);
  tcase_add_test(tc, s21_decimal_mul6);
  tcase_add_test(tc, s21_decimal_mul7);
  tcase_add_test(tc, s21_decimal_mul8);
  tcase_add_test(tc, s21_decimal_mul9);
  tcase_add_test(tc, s21_decimal_mul10);
  tcase_add_test(tc, s21_decimal_mul11);

  suite_add_tcase(s, tc);
  return s;
}

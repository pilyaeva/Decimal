#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = TRUE;
  int flag = 1;
  for (int i = 0; i < 4 && flag; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      status = FALSE;
      flag = 0;
    }
  }
  if (value_1.bits[0] == 0 && value_2.bits[0] == 0 && value_1.bits[1] == 0 &&
      value_2.bits[1] == 0 && value_1.bits[2] == 0 && value_2.bits[2] == 0) {
    status = TRUE;
  }
  return status;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_greater_or_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1, big_value_2;
  s21_convert_decimal_to_big_decimal(value_1, &big_value_1);
  s21_convert_decimal_to_big_decimal(value_2, &big_value_2);
  return s21_big_is_greater(big_value_1, big_value_2);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_greater(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_equal(value_1, value_2) || s21_is_greater(value_1, value_2));
}

int s21_big_is_greater(s21_big_decimal big_value_1,
                       s21_big_decimal big_value_2) {
  int status = FALSE;
  int sign_1 = big_value_1.sign, sign_2 = big_value_2.sign;
  if (sign_1 != sign_2) {
    status = !sign_1;
  } else if (sign_1 == MINUS && sign_2 == MINUS) {
    big_value_1.sign = PLUS;
    big_value_2.sign = PLUS;
    status = s21_big_is_greater(big_value_2, big_value_1);
  } else {
    s21_big_decimal_scale_eq(&big_value_1, &big_value_2);
    int stop_flag = 0;
    for (int i = 5; i >= 0 && !stop_flag; i--) {
      if (big_value_1.bits[i] != big_value_2.bits[i]) {
        status = big_value_1.bits[i] > big_value_2.bits[i];
        stop_flag = 1;
      }
    }
  }
  return status;
}
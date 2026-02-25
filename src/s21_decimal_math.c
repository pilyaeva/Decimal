#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char status = OK_OPERATION;

  char sign_1 = s21_get_sign(value_1);
  char sign_2 = s21_get_sign(value_2);

  if (sign_1 == sign_2) {
    s21_big_decimal value_big_1, value_big_2, big_result = {0, 0, {0}};
    s21_convert_decimal_to_big_decimal(value_1, &value_big_1);
    s21_convert_decimal_to_big_decimal(value_2, &value_big_2);

    s21_big_decimal_add(value_big_1, value_big_2, &big_result);
    status = s21_convert_big_decimal_to_decimal(result, big_result);
  } else {
    if (sign_1 < sign_2) {
      s21_set_sign(&value_2, 0);
      status = s21_sub(value_1, value_2, result);
    } else {
      s21_set_sign(&value_1, 0);
      status = s21_sub(value_2, value_1, result);
    }
  }

  return status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char status = OK_OPERATION;
  char sign_1 = s21_get_sign(value_1);
  char sign_2 = s21_get_sign(value_2);

  if (sign_1 == sign_2) {
    if (s21_is_less(s21_abs(value_1), s21_abs(value_2))) {
      s21_decimal temp = value_1;
      value_1 = value_2;
      value_2 = temp;
      s21_set_sign(&value_1, !sign_1);
      s21_set_sign(&value_2, !sign_2);
    }
    s21_big_decimal value_big_1, value_big_2, big_result = {0, 0, {0}};
    s21_convert_decimal_to_big_decimal(value_1, &value_big_1);
    s21_convert_decimal_to_big_decimal(value_2, &value_big_2);
    s21_big_decimal_sub(value_big_1, value_big_2, &big_result);
    status = s21_convert_big_decimal_to_decimal(result, big_result);
  } else {
    if (sign_1 < sign_2) {
      s21_set_sign(&value_2, 0);
      status = s21_add(value_1, value_2, result);
    } else {
      s21_set_sign(&value_2, 1);
      status = s21_add(value_2, value_1, result);
    }
  }

  return status;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal value_big_1, value_big_2, big_result;
  s21_convert_decimal_to_big_decimal(value_1, &value_big_1);
  s21_convert_decimal_to_big_decimal(value_2, &value_big_2);
  s21_big_decimal_mult(value_big_1, value_big_2, &big_result);
  int status = s21_convert_big_decimal_to_decimal(result, big_result);
  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK_OPERATION, zero_div = 0;
  if (s21_is_null(value_2)) status = DELETE_BY_ZERO;
  if (s21_is_null(value_1)) {
    *result = value_1;
    zero_div = 1;
    s21_set_sign(result, s21_get_sign(value_1) ^ s21_get_sign(value_2));
  }
  if (!status && !zero_div) {
    s21_big_decimal value_big_1, value_big_2, big_result = {0, 0, {0}};
    s21_convert_decimal_to_big_decimal(value_1, &value_big_1);
    s21_convert_decimal_to_big_decimal(value_2, &value_big_2);
    s21_big_decimal_div(value_big_1, value_big_2, &big_result);
    status = s21_convert_big_decimal_to_decimal(result, big_result);
  }
  return status;
}

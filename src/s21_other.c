#include "s21_decimal.h"

void shift_to_right(s21_decimal value, s21_decimal *result);

int s21_floor(s21_decimal value, s21_decimal *result) {
  *result = value;

  if (s21_get_exp(*result) != 0) {
    s21_decimal shifted_result;
    shift_to_right(*result, &shifted_result);

    *result = shifted_result;

    s21_set_exp(result, 0);

    if (s21_get_sign(*result) == 1) {
      s21_decimal zero = {{0, 0, 0, 0}};
      s21_decimal difference;
      s21_sub(value, *result, &difference);

      if (!s21_is_equal(difference, zero)) {
        s21_decimal minus_one = {{1, 0, 0, 1 << 31}};
        s21_decimal sub_result;
        s21_add(*result, minus_one, &sub_result);
        *result = sub_result;
      }
    }
  }

  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  *result = value;

  s21_decimal shifted_result;
  shift_to_right(*result, &shifted_result);

  *result = shifted_result;

  s21_set_exp(result, 0);

  s21_decimal difference;
  s21_sub(value, *result, &difference);

  s21_decimal half = {{5, 0, 0, 1 << 16}};

  if (s21_is_greater_or_equal(s21_abs(difference), half)) {
    s21_decimal round_result;
    if (s21_get_sign(value) == 1) {
      s21_decimal minus_one = {{1, 0, 0, 1 << 31}};
      s21_add(*result, minus_one, &round_result);
    } else {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_add(*result, one, &round_result);
    }
    *result = round_result;
  }

  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  *result = value;

  s21_decimal shifted_result;
  shift_to_right(*result, &shifted_result);

  *result = shifted_result;

  s21_set_exp(result, 0);

  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;

  s21_set_sign(result, !s21_get_sign(*result));

  return 0;
}

void shift_to_right(s21_decimal value, s21_decimal *result) {
  unsigned int intermediate_result[3];

  for (int i = 0; i < 3; i++) {
    intermediate_result[i] = (unsigned int)value.bits[i];
  }

  *result = value;

  int scale = s21_get_exp(value);

  int remainder = 0;

  for (int i = 0; i < scale; i++) {
    unsigned long long int temp = 0;
    for (int j = 2; j >= 0; j--) {
      remainder = (intermediate_result[j] | temp) % 10;
      intermediate_result[j] =
          (unsigned long long int)(intermediate_result[j] + temp) / 10;
      temp = ((unsigned long long int)remainder) << 32;
    }
  }

  for (int i = 0; i < 3; i++) {
    result->bits[i] = intermediate_result[i];
  }
}

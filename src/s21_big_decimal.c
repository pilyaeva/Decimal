#include "s21_decimal.h"

void s21_convert_decimal_to_big_decimal(s21_decimal decimal,
                                        s21_big_decimal* result) {
  s21_big_decimal_null(result);
  for (int i = 0; i < 3; i++) {
    result->bits[i] = decimal.bits[i];
  }

  result->scale = s21_get_exp(decimal);
  result->sign = s21_get_sign(decimal);
}

int s21_convert_big_decimal_to_decimal(s21_decimal* decimal,
                                       s21_big_decimal big_decimal) {
  s21_big_decimal_bank_round(&big_decimal);

  int error = s21_big_decimal_error(big_decimal);
  for (int i = 0; i < 3 && !error; i++) {
    decimal->bits[i] = big_decimal.bits[i];
  }
  if (!error) s21_set_exp(decimal, big_decimal.scale);
  if (!error) s21_set_sign(decimal, big_decimal.sign);
  return error;
}

void s21_big_decimal_null(s21_big_decimal* big_decimal) {
  for (int i = 0; i < 6; i++) {
    big_decimal->bits[i] = 0;
  }
  big_decimal->scale = 0;
  big_decimal->sign = 0;
}

int s21_big_decimal_error(s21_big_decimal big_decimal) {
  int res = OK_OPERATION;
  for (int i = 3; i < 6; i++) {
    if (big_decimal.bits[i]) {
      res = big_decimal.sign ? TOO_LOW : TOO_HIGH;
    }
  }
  return res;
}

void s21_big_decimal_scale_up(s21_big_decimal* big_decimal, int num) {
  if (num) big_decimal->scale += num;
  while (num--) {
    unsigned long long int temp = 0;
    for (int i = 0; i < 6; i++) {
      temp = (unsigned long long int)big_decimal->bits[i] * 10 + temp;
      big_decimal->bits[i] = (int)temp;
      temp = ((temp >> 32) & 0xFFFFFFFF);
    }
  }
}

void s21_big_decimal_scale_eq(s21_big_decimal* big_decimal_1,
                              s21_big_decimal* big_decimal_2) {
  if (big_decimal_1->scale > big_decimal_2->scale) {
    s21_big_decimal_scale_up(big_decimal_2,
                             big_decimal_1->scale - big_decimal_2->scale);
  } else if (big_decimal_1->scale < big_decimal_2->scale) {
    s21_big_decimal_scale_up(big_decimal_1,
                             big_decimal_2->scale - big_decimal_1->scale);
  }
}

int s21_big_decimal_scale_down(s21_big_decimal* big_decimal, int num) {
  int remainder = 0;
  if (num) big_decimal->scale -= num;
  while (num--) {
    unsigned long long int temp = 0;

    for (int i = 5; i >= 0; i--) {
      remainder = (big_decimal->bits[i] | temp) % 10;
      big_decimal->bits[i] =
          (unsigned long long int)(big_decimal->bits[i] + temp) / 10;
      temp = ((unsigned long long int)remainder) << 32;
    }
  }
  return remainder;
}

void s21_big_decimal_add(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result) {
  s21_big_decimal_null(result);
  s21_big_decimal_scale_eq(&big_decimal_1, &big_decimal_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 6; i++) {
    temp += (unsigned long long)big_decimal_1.bits[i] +
            (unsigned long long)big_decimal_2.bits[i];

    result->bits[i] = temp & 0xFFFFFFFF;
    temp >>= 32;
  }
  result->scale = big_decimal_1.scale;

  result->sign = big_decimal_1.sign;
}

void s21_big_decimal_sub(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result) {
  s21_big_decimal_scale_eq(&big_decimal_1, &big_decimal_2);
  s21_big_decimal_null(result);
  unsigned long long temp = 0;
  for (int i = 0; i < 6; i++) {
    unsigned long long sub = (unsigned long long)big_decimal_1.bits[i] -
                             (unsigned long long)big_decimal_2.bits[i] - temp;
    if ((unsigned long long)big_decimal_1.bits[i] <
        ((unsigned long long)temp +
         (unsigned long long)big_decimal_2.bits[i])) {
      temp = 1;
    } else {
      temp = 0;
    }
    result->bits[i] = sub;
  }
  result->scale = big_decimal_1.scale;

  result->sign = big_decimal_1.sign;
}

void s21_big_decimal_bank_round(s21_big_decimal* big_decimal) {
  s21_big_decimal big_copy;
  s21_big_copy(*big_decimal, &big_copy);

  int reminder = 0;

  if (big_copy.scale) s21_big_decimal_scale_down(&big_copy, 1);
  while (
      (!s21_big_decimal_is_null(*big_decimal) && big_decimal->scale > 28) ||
      ((big_decimal->bits[3] || big_decimal->bits[4] || big_decimal->bits[5]) &&
       big_decimal->scale)) {
    int number = s21_big_decimal_scale_down(big_decimal, 1);
    reminder = s21_big_decimal_scale_down(&big_copy, 1);
    if (number > 5 || (number == 5 && reminder % 2)) {
      s21_big_decimal_add(*big_decimal,
                          s21_big_one(big_decimal->sign, big_decimal->scale),
                          big_decimal);
    }
  }
}

void s21_big_copy(s21_big_decimal big_decimal,
                  s21_big_decimal* big_decimal_copy) {
  for (int i = 0; i < 6; i++) {
    big_decimal_copy->bits[i] = big_decimal.bits[i];
  }
  big_decimal_copy->scale = big_decimal.scale;
  big_decimal_copy->sign = big_decimal.sign;
}

int s21_big_decimal_is_null(s21_big_decimal big_decimal) {
  return (big_decimal.bits[0] == 0 && big_decimal.bits[1] == 0 &&
          big_decimal.bits[2] == 0 && big_decimal.bits[3] == 0 &&
          big_decimal.bits[4] == 0 && big_decimal.bits[5] == 0);
}

s21_big_decimal s21_big_one(int sign, int scale) {
  s21_big_decimal num = {0, 0, {0}};
  num.bits[0] = 1;
  num.scale = scale;
  num.sign = sign;
  return num;
}

void s21_big_decimal_mult(s21_big_decimal big_decimal_1,
                          s21_big_decimal big_decimal_2,
                          s21_big_decimal* result) {
  s21_big_decimal_null(result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (big_decimal_1.bits[i] && big_decimal_2.bits[j]) {
        unsigned long long mult = (unsigned long long)big_decimal_1.bits[i] *
                                  (unsigned long long)big_decimal_2.bits[j];
        mult += result->bits[i + j];
        result->bits[i + j] = mult;
        mult >>= 32;
        result->bits[i + j + 1] += mult;
      }
    }
  }
  result->sign = big_decimal_1.sign ^ big_decimal_2.sign;
  result->scale = big_decimal_1.scale + big_decimal_2.scale;
}

void s21_big_decimal_div(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result) {
  s21_big_decimal temp, temp_res, copy_1, copy_2;
  s21_big_decimal *temp_p = &temp, *temp_res_p = &temp_res;
  s21_big_decimal_null(result);
  int big_scale = big_decimal_1.scale;
  s21_big_decimal_scale_up(&big_decimal_1, big_decimal_2.scale);
  big_decimal_1.scale = big_scale;
  big_decimal_2.scale = 0;
  s21_big_copy(big_decimal_1, &copy_1);
  s21_big_copy(big_decimal_2, &copy_2);
  copy_1.scale = 0;
  copy_2.scale = 0;
  copy_1.sign = 0;
  copy_2.sign = 0;
  int scale = 0;
  int status = 1;

  do {
    s21_big_decimal_null(temp_p);
    s21_big_decimal_null(temp_res_p);
    int i = 192;
    while (!s21_big_get_bit(copy_1, i) && i--) {
    }
    for (; i >= 0; i--) {
      s21_big_left_shift(temp_p, 1);
      if (s21_big_get_bit(copy_1, i)) {
        s21_big_set_bit(temp_p, 0);
      }

      if (!s21_big_is_greater(copy_2, temp)) {
        s21_big_decimal_sub(temp, copy_2, &temp);

        s21_big_set_bit(temp_res_p, i);
      }
    }

    s21_big_decimal_add(*result, temp_res, result);
    if (s21_big_decimal_is_null(temp) || result->bits[3] != 0) {
      result->scale = big_decimal_1.scale + scale;
      status = 0;
    } else {
      s21_big_copy(temp, &copy_1);
      big_scale = copy_1.scale;
      s21_big_decimal_scale_up(&copy_1, 1);
      copy_1.scale = big_scale;
      big_scale = result->scale;
      s21_big_decimal_scale_up(result, 1);
      result->scale = big_scale;

      scale++;
    }
  } while (status);
  result->sign = big_decimal_1.sign ^ big_decimal_2.sign;
}

void s21_big_left_shift(s21_big_decimal* value, int shift) {
  for (int i = 5; i >= 0; i--) {
    value->bits[i] = (value->bits[i] << shift);
    if (i) value->bits[i] |= (value->bits[i - 1] >> (32 - shift));
  }
}

void s21_big_set_bit(s21_big_decimal* value, int num) {
  value->bits[num / 32] |= (1 << (num % 32));
}

int s21_big_get_bit(s21_big_decimal value, int bit) {
  return (value.bits[bit / 32] & (1 << (bit % 32))) ? 1 : 0;
}

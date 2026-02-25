#include "s21_decimal.h"

void s21_decimal_null(s21_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = OK_CONVERSATION;
  if (!dst) {
    result = CONVERTION_ERROR;
  } else {
    s21_decimal_null(dst);

    if (src < 0) {
      s21_set_sign(dst, 1);
      src = -src;
    }
    dst->bits[0] = (unsigned int)src;
  }
  return result;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = OK_CONVERSATION;
  if (isnan(src) || isinf(src)) {
    result = CONVERTION_ERROR;
  }
  if (dst != NULL && !result) {
    s21_decimal_null(dst);
    int sign = PLUS;
    if (src < 0) {
      sign = MINUS;
      src = -src;
    }
    int temp = (int)src;
    int scale = 0;
    int max = 7;
    while (scale < max && src - ((float)temp / (int)(pow(10, scale))) != 0) {
      scale++;
      temp = src * (int)(pow(10, scale));
    }
    s21_from_int_to_decimal(temp, dst);
    if (sign == MINUS) {
      s21_set_sign(dst, 1);
      src = -src;
    }
    s21_set_exp(dst, scale);
  } else {
    result = CONVERTION_ERROR;
  }
  return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = OK_CONVERSATION;
  if (dst) {
    s21_decimal int_src;
    s21_decimal_null(&int_src);
    s21_truncate(src, &int_src);

    if (s21_get_bit(src, 127) == MINUS) {
      *dst = -1 * (int)(int_src.bits[0]);
    } else {
      *dst = (int)(int_src.bits[0]);
    }
  } else {
    status = CONVERTION_ERROR;
  }
  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = OK_CONVERSATION;
  if (dst == NULL) {
    status = CONVERTION_ERROR;
  } else {
    *dst = 0;
    for (int i = 0; i < 96; i++) {
      if (s21_get_bit(src, i)) {
        *dst += pow(2, i);
      }
    }
    *dst = *dst * pow(10, -s21_get_exp(src));
    if (s21_get_bit(src, 127)) {
      *dst = -*dst;
    }
  }
  return status;
}

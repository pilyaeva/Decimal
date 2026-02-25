#include "s21_decimal.h"

int s21_get_bit(s21_decimal num, int bit) {
  return (num.bits[bit / 32] & (1 << bit % 32)) ? 1 : 0;
}

int s21_get_exp(s21_decimal num) { return (num.bits[3] >> 16) & 0xff; }

void s21_set_exp(s21_decimal* num, int bit) {
  num->bits[3] &= ~(0x7FFFFFFF);
  num->bits[3] |= ((bit & 0xff) << 16);
}

int s21_get_sign(s21_decimal num) { return num.bits[3] < 0; }

void s21_set_sign(s21_decimal* num, int bit) {
  num->bits[3] =
      bit ? (num->bits[3] | 0x80000000) : (num->bits[3] & ~(0x80000000));
}

int s21_is_null(s21_decimal value) {
  int status = 0;
  if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
    status = 1;
  }
  return status;
}

s21_decimal s21_abs(s21_decimal source) {
  s21_set_sign(&source, 0);
  return source;
}
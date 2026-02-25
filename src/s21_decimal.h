#ifndef S21_DECIMAL
#define S21_DECIMAL
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int sign;
  int scale;
  unsigned int bits[6];
} s21_big_decimal;

typedef enum {
  OK_OPERATION,
  TOO_HIGH,
  TOO_LOW,
  DELETE_BY_ZERO
} S21_OPERATION_STATUS;

typedef enum { FALSE, TRUE } S21_COMPARE_STATUS;

typedef enum { OK_CONVERSATION, CONVERTION_ERROR } S21_CONVERSATION_STATUS;

typedef enum { PLUS, MINUS } S21_DECIMAL_SIGN;

int s21_get_bit(s21_decimal num, int bit);
int s21_decimal_get_bit(s21_decimal decimal, int position);
void s21_set_bit(s21_decimal* num, int bit);
void s21_reset_bit(s21_decimal* num, int bit);
int s21_get_exp(s21_decimal num);
void s21_set_exp(s21_decimal* num, int bit);
int s21_get_sign(s21_decimal num);
void s21_set_sign(s21_decimal* num, int bit);
s21_decimal s21_abs(s21_decimal big_decimal);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_is_null(s21_decimal value);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_big_is_greater(s21_big_decimal big_value_1,
                       s21_big_decimal big_value_2);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

void s21_convert_decimal_to_big_decimal(s21_decimal decimal,
                                        s21_big_decimal* result);
int s21_convert_big_decimal_to_decimal(s21_decimal* decimal,
                                       s21_big_decimal big_decimal);
void s21_big_decimal_null(s21_big_decimal* big_decimal);
int s21_big_decimal_error(s21_big_decimal big_decimal);
void s21_big_decimal_scale_up(s21_big_decimal* big_decimal, int num);
void s21_big_decimal_scale_eq(s21_big_decimal* big_decimal_1,
                              s21_big_decimal* big_decimal_2);
int s21_big_decimal_scale_down(s21_big_decimal* big_decimal, int num);
void s21_big_decimal_add(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result);
void s21_big_decimal_sub(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result);
void s21_big_decimal_mult(s21_big_decimal big_decimal_1,
                          s21_big_decimal big_decimal_2,
                          s21_big_decimal* result);
void s21_big_decimal_div(s21_big_decimal big_decimal_1,
                         s21_big_decimal big_decimal_2,
                         s21_big_decimal* result);
int s21_big_decimal_is_null(s21_big_decimal big_decimal);
void s21_big_copy(s21_big_decimal big_decimal,
                  s21_big_decimal* big_decimal_copy);
s21_big_decimal s21_big_one(int sign, int scale);
void s21_big_decimal_bank_round(s21_big_decimal* big_decimal);

void s21_big_left_shift(s21_big_decimal* value, int shift);
int s21_big_get_bit(s21_big_decimal value, int bit);
void s21_big_set_bit(s21_big_decimal* value, int num);
s21_big_decimal s21_big_decimal_mult_by_ten(s21_big_decimal value, int num);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
void s21_decimal_set_pow(s21_decimal* decimal, int pow);
int s21_decimal_get_pow(s21_decimal value);
int s21_decimal_get_bit(s21_decimal decimal, int position);
#endif
#ifndef S21_STRING_TEST_H
#define S21_STRING_TEST_H

#include <check.h>

#include "../s21_decimal.h"

Suite *test_is_equal(void);
Suite *test_is_not_equal(void);
Suite *test_is_greater(void);
Suite *test_comparision_other(void);
Suite *test_floor(void);
Suite *test_round(void);
Suite *test_negate(void);
Suite *test_truncate(void);
Suite *test_s21_from_int_to_decimal(void);
Suite *test_s21_from_float_to_decimal(void);
Suite *test_s21_from_decimal_to_int(void);
Suite *test_s21_from_decimal_to_float(void);
Suite *test_s21_add(void);
Suite *test_s21_sub(void);
Suite *test_s21_mul(void);
Suite *test_s21_div(void);

#endif

/*
 * Copyright (c) 2025 Maciej
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/ztest.h>

#include "include/math_lib.h"

ZTEST_SUITE(math_lib, NULL, NULL, NULL, NULL, NULL);

ZTEST(math_lib, test_add) {
  zassert_equal(add(1, 1), 2, "1 + 1 should be 2");
  zassert_equal(add(-1, 1), 0, "-1 + 1 should be 0");
  zassert_equal(add(0, 0), 0, "0 + 0 should be 0");
}

ZTEST(math_lib, test_subtract) {
  zassert_equal(subtract(1, 1), 0, "1 - 1 should be 0");
  zassert_equal(subtract(-1, 1), -2, "-1 - 1 should be -2");
  zassert_equal(subtract(0, 0), 0, "0 - 0 should be 0");
}

ZTEST(math_lib, test_multiply) {
  zassert_equal(multiply(2, 3), 6, "2 * 3 should be 6");
  zassert_equal(multiply(-2, 3), -6, "-2 * 3 should be -6");
  zassert_equal(multiply(0, 5), 0, "0 * 5 should be 0");
}

ZTEST(math_lib, test_divide) {
  zassert_within(divide(6, 3), 2.0, 0.0001, "6 / 3 should be 2.0");
  zassert_within(divide(1, 2), 0.5, 0.0001, "1 / 2 should be 0.5");
  zassert_equal(divide(1, 0), 0.0,
                "1 / 0 should return 0.0 to avoid division by zero");
}

ZTEST(math_lib, test_square) {
  zassert_equal(square(2), 4, "2^2 should be 4");
  zassert_equal(square(-2), 4, "(-2)^2 should be 4");
  zassert_equal(square(0), 0, "0^2 should be 0");
}

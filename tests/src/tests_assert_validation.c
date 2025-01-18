/*
 * Copyright (c) 2025 Maciej
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/ztest.h>

ZTEST_SUITE(tests_assert_validation, NULL, NULL, NULL, NULL, NULL);

ZTEST(tests_assert_validation, test_assert_1) {
  zassert_true(1, "1 was false");
  zassert_false(0, "0 was true");
  zassert_is_null(NULL, "NULL was not NULL");
}

ZTEST(tests_assert_validation, test_assert_2) {
  zassert_not_null("foo", "\"foo\" was NULL");
  zassert_equal(1, 1, "1 was not equal to 1");
  zassert_equal_ptr(NULL, NULL, "NULL was not equal to NULL");
}

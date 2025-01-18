/*
 * Copyright (c) 2025 Maciej
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

ZTEST(template, test_template) {
  zassert_true(true, "Some test failed");
  printk("test finished!\n");
}

ZTEST(template, test_assert) {
  zassert_true(1, "1 was false");
  printk("test finished!\n");
}

ZTEST(template, test_assert2) {
  zassert_true(1, "1 was false");
  printk("test finished!\n");
}

ZTEST_SUITE(template, NULL, NULL, NULL, NULL, NULL);

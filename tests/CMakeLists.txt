cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(unit-tests)

target_sources(app PRIVATE ../app/src/math_lib.c)
target_sources(app PRIVATE src/tests_math_lib.c)

target_include_directories(app PRIVATE ../app)

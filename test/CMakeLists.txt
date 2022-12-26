cmake_minimum_required(VERSION 3.24)
project(OJ)

add_executable(test test.c)

add_library(myadd SHARED myadd.c)

target_link_libraries(test myadd)

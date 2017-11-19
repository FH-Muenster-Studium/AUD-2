cmake_minimum_required(VERSION 3.8)
project(AUD_2)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c aud-2.c aud-2.h)
add_executable(AUD_2 ${SOURCE_FILES})
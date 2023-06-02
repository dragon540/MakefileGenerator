cmake_minimum_required(VERSION 3.24)
project(MakefileGenerator C)

set(CMAKE_C_STANDARD 11)

add_executable(MakefileGenerator src/main.c src/macro.h src/macro.c src/comm_line.h src/comm_line.c src/makefile_generate.c src/makefile_generate.h src/reqfuncs.c src/reqfuncs.h)

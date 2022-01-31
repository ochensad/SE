#!/bin/sh
rm ./*.exe ./*.o
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -O0 --coverage main.c io.c translation.c file_func.c -o app.exe


cd func_tests

./all_test.sh

cd ..

echo "....COVERAGE...."

gcov main.c io.c translation.c
rm -f out.txt
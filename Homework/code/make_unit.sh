rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -c unit_test.c
gcc -Wall -Werror -Wpedantic -Wextra -c translation.c

gcc translation.o unit_test.o -o app_unit.exe

./app_unit.exe
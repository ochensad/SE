rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -c translation.c
gcc -Wall -Werror -Wpedantic -Wextra -c io.c
gcc -Wall -Werror -Wpedantic -Wextra -c file_func.c

gcc main.o translation.o io.o file_func.o -o app.exe
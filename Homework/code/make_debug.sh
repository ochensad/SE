rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c translation.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c io.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c file_func.c

gcc main.o translation.o io.o file_func.o -o app.exe
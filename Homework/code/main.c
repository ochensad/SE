#include "translation.h"
#include "io.h"
#include "errors.h"
#include "file_func.h"

int main(int argc, char **argv)
{
    FILE *f;
    FILE *f_out;

    char str_input[MAX_LEN + 1];
    char str_copy[MAX_LEN + 1];
    char str_output[MAX_LEN + 1];

    int exit_code = OK;

    if (argc != 3)
        return OK;
  
    f = fopen(argv[1], "r");
    f_out = fopen(argv[2], "w");
    
    if (f == NULL || f_out == NULL)
    {
        exit_code = NO_FILE;
        if (f_out != NULL)
            fclose(f_out);
        if (f != NULL)
            fclose(f);
        return exit_code;
    }
    
    exit_code = size_check(f);

    while (read_num(f, str_input) == OK && exit_code == OK)
    {
        trim(str_input, str_copy);
        if (check_num(str_copy) == 1)
        {
            translate_num(str_copy, str_output);
            print_num(f_out, str_output);
        }
        else
            print_num(f_out, " ");
    }
    fclose(f);
    fclose(f_out);
    return exit_code;
}
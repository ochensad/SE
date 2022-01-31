#include "io.h"
#include "errors.h"

int read_num(FILE *f, char *num)
{
    char *error;
    error = fgets(num, MAX_LEN, f);
    if (error == NULL)
    {
        return ERROR_READING;
    }
    return OK;
}

int print_num(FILE *f, const char *s)
{
    int error;
    error = fprintf(f, "%s\n", s);
    if (error != 1)
        return ERROR_PRINT;
    return OK;
}
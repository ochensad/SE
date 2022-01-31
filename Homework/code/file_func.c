#include "file_func.h"
#include "errors.h"
int size_check(FILE *f)
{
    if (fseek(f, 0, SEEK_END))
        return ERROR_READING;
    if (ftell(f) == 0)
        return EMPTY_FILE;
    if (fseek(f, 0, SEEK_SET))
        return ERROR_READING;
    return OK;
}
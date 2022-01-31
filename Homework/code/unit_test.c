#include <string.h>
#include "translation.h"
#include "errors.h"
#include "io.h"
int main(void)
{
    char test_trim[10][MAX_LEN] = {
        "    101010    ", 
        "   1010   1010   ", 
        "    234   3345   ", 
        "  2345   ", 
        "   hgjk   ", 
        "   gjjd    hjfk ", 
        "\t101010\t", 
        "\n101010\n", 
        "\r101010\r", 
        "\t         \t" 
        };

    char ans_trim[10][MAX_LEN] = {
        "101010", 
        "1010   1010", 
        "234   3345", 
        "2345", "hgjk", 
        "gjjd    hjfk", 
        "101010", 
        "101010", 
        "101010", 
        "" 
        };

    printf("\n...TRIM...\n");
    for (size_t i = 0; i < 10; i++)
    {
        char s_test[MAX_LEN];
        trim(test_trim[i], s_test);
        if (strcmp(s_test, ans_trim[i]) == 0)
            printf("\nTEST %zu [PASSED]\n", i);
        else
            printf("\nTEST %zu [FAILED]\n", i);
    }

    char test_check[10][MAX_LEN] = {
        "1010101", 
        "101001 1010", 
        "hjghj jfj", 
        "1010\t1010", 
        "111111", 
        "101010\n10", 
        "23445", 
        "2324 455", 
        "1111121110", 
        ""
        };
    int ans_check[10] = {1,0,0,0,1,0,0,0,0,0};

    printf("\n...CHECK_NUM...\n");
    for (size_t j = 0; j < 10; j++)
    {
        int ans;
        ans = check_num(test_check[j]);
        if (ans == ans_check[j])
            printf("\nTEST %zu [PASSED]\n", j);
        else
            printf("\nTEST %zu [FAILED]\n", j);
    }

    char test_translate[10][MAX_LEN] = {
        "1111", 
        "01", 
        "1010", 
        "10101111", 
        "11000", 
        "111", 
        "11111", 
        "10101", 
        "10", 
        "100000"
        };
    char ans_translate[10][MAX_LEN] = {
        "F", 
        "1", 
        "A", 
        "AF", 
        "18", 
        "7", 
        "1F", 
        "15", 
        "2", 
        "20"
        };

    printf("\n...TRANSLATE...\n");
    for (size_t k = 0; k < 10; k++)
    {
        char s[MAX_LEN];
        translate_num(test_translate[k], s);
        if (strcmp(s, ans_translate[k]) == 0)
            printf("\nTEST %zu [PASSED]\n", k);
        else
            printf("\nTEST %zu [FAILED]\n", k);
    }
    return OK;
}
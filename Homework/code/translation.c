#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "translation.h"
#include "errors.h"

/*!
    \brief Удаляет пробелы в начале и в конце строки
    \param s_srs указатель на исходную строку
    \param s_dst указатель на копию исходной строки без пробелов

    Функция ищет начало и конец участка, который ограничивают пробелы, \n
    затем копирует его в s_dst
    \return возвращает код ошибки.

*/
int trim(const char *s_src, char *s_dst)
{
    size_t left = 0;
    size_t right = strlen(s_src) - 1;

    
    while (isspace((int)s_src[left]) != 0 && s_src[left] != '\0')
        left +=1;
  
    while (isspace((int)s_src[right]) != 0 && right != 0)
        right--;
  
    size_t i_dst = 0;
    size_t i_src;

    for (i_src = left; i_src <= right; i_src++)
    {
        s_dst[i_dst] = s_src[i_src];
        i_dst++;
    }
    s_dst[i_dst] = '\0';

    return OK;
}

/*!
    \brief Проверяет, является ли строка двоичным числом
    \param str указатель на строку

    Функция проходится по всей строке, сравнивая каждый символ с "0" и "1". \n
    Если условие не выполняется, то цикл завершается.

    \return "1", если число является двоичным, и  "0" - если нет.

*/
int check_num(const char *str)
{
    int flag = 1;
    size_t i = 0;
    if (str[i] == '\0')
        flag = 0;
    while (str[i] != '\0' && flag != 0)
    {
        if (str[i] != '1' && str[i] != '0')
            flag = 0;
        i++;
    }
    return flag;
}

/*!
    \brief Переводит строку, содержащую двоичное число в строку, содержащую шестнадцатиричное число.
    \param str указатель на исходную строку
    \param num16 указатель на строку с ответом

    \warning функция имеет неопределенное поведение, если отправить в нее некоректные данные
    
    Функция сравнивает каждые 4 элемента строки str с массивами-словарями и по индексу находит значение \n
    в 16-ой системе

    \return возвращает код ошибки.

*/
int translate_num(const char *str, char *num16)
{
    char bin_dict[16][5] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
        };
    char hex_dict[16][2] = {
        "0","1","2","3",
        "4","5","6","7",
        "8","9","A","B",
        "C","D","E","F"
        };

    char str_copy[MAX_LEN + 1];

    size_t len = strlen(str);
    size_t count = len % 4;

    if (count != 0)
    {
        size_t i;

        for (i = 0; i < 4 - count; i++)
            str_copy[i] = '0';
        str_copy[i] = '\0';

        strcat(str_copy, str);
    }
    else
        strcpy(str_copy, str);

    size_t i_2 = 0;

    char num2[5] = "0000";
    num16[0] = '\0';

    while (str_copy[i_2] != '\0')
    {

        strncpy(num2, str_copy + i_2, 4);

        i_2 += 4;
        size_t j = 0;
        int flag = 1;

        while(flag == 1)
        {
            if (strcmp(bin_dict[j], num2) == 0)
                flag = 0;
            else
                j++;
        }
        
        strcat(num16, hex_dict[j]);
    }
    return OK;
}
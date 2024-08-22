#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "flag.h"
//функция, которая анализирует аргументы командной строки
//в ней считается, что аргумент - это строка из двух символов, первый из которых - '-'
int analyse_flags(const char* flag, const char* all_flags, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (all_flags[i] == flag[1] && flag[0] == '-')
            return flag[1];
    }
    return -1;
}

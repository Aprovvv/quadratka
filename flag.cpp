/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "flag.h"
/**
 * функция, которая анализирует аргументы командной строки
 * в ней считается, что аргумент - это строка из двух символов, первый из которых - '-'
 * \param flag {обрабатываемые аргумент командной строки (arg_v[i]).}
 * \param all_flags {строка содержащая все возможные флаги (например, "hf" для функции с флагами -h и -f).}
 * \param size {длина строки all_flags.}
 */
int analyse_flag(const char* flag, const char* all_flags, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        if (all_flags[i] == flag[1] && flag[0] == '-')
            return flag[1];
    }
    return flag[1];
}

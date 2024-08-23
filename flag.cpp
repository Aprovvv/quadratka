/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "flag.h"

int analyse_flag(const char* flag, const char* all_flags, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        if (all_flags[i] == flag[1] && flag[0] == '-')
            return flag[1];
    }
    return flag[1];
}

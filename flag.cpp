/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "flag.h"
/**
 * Как эта шняга работает.
 * Строка с флагами должна выглядеть примерно так:
 * "h/help;f/filetest/test/t;e/eng/english"
 * Через ; записаны разные флаги, через / - синонимы. Т.е. -f -filetest и -test это одно и то же
*/
int analyse_flag(const char* flag, const char* all_flags, size_t size)
{
    if (flag[0] != '-')
        return 0;

    char* read_flag = (char*)calloc(size, 1);//а вот тут у меня вопрос. Как задать размер массива? read_flag[size] - это VLA
    read_flag[0] = '-';//От безысходности фиганул динамическую память. Но может можно как-то по-умному?
    size_t all_flags_index = 0, read_flag_index =1;
    int current_flag = all_flags[0];

    while(all_flags_index < size-1)
    {
        read_flag[read_flag_index] = all_flags[all_flags_index];
        read_flag[read_flag_index + 1] = '\0';
        //printf("%s\n", read_flag);
        switch(all_flags[all_flags_index+1])
        {
        case '\0':
            if (strcmp(flag, read_flag) == 0)
            {
                free(read_flag);
                return current_flag;
            }
            else
            {
                free(read_flag);
                return 0;
            }
        case ';':
            if (strcmp(flag, read_flag) == 0)
            {
                free(read_flag);
                return current_flag;
            }
            current_flag = all_flags[all_flags_index+2];
            all_flags_index+=2;
            read_flag_index = 1;
            read_flag[1] = '\0';
            break;
        case '/':
            if (strcmp(flag, read_flag) == 0)
            {
                free(read_flag);
                return current_flag;
            }
            all_flags_index+=2;
            read_flag_index = 1;
            read_flag[1] = '\0';
            break;
        default:
            read_flag_index++;
            all_flags_index++;
            break;
        }
    }
    free(read_flag);
    return 0;
}

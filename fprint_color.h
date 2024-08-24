#ifndef FPRINT_COLOR
#define FPRINT_COLOR
#include <stdio.h>
#include <stdlib.h>

#define CONSOLE_COLOR_GREEN "\033[92m"
#define CONSOLE_COLOR_RED "\033[91m"
#define CONSOLE_COLOR_STANDART "\033[39m"

int fprintf_color(FILE* output,const char* color_code, const char* str, ...);
#endif

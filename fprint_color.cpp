#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "fprint_color.h"

int fprintf_color(FILE* output, const char* color_code, const char* str, ...)
{
    int n=0;
    va_list ap;
    va_start(ap, str);
    if (isatty(fileno(output)))
    {
        fprintf(output,"%s", color_code);
        n = vfprintf(output, str, ap);
        fprintf(output, CONSOLE_COLOR_STANDART "\n");
    }
    else
    {
        fprintf(output,"%s", color_code);
        n = vfprintf(output, str, ap);
        fprintf(output, CONSOLE_COLOR_STANDART "\n");
    }
    return n;
}

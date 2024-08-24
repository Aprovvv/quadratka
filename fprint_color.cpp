#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "fprint_color.h"

static const char* color_codes[] =
{
    "\033[39m",
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[90m",
    "\033[91m",
    "\033[92m",
    "\033[93m",
    "\033[94m",
    "\033[95m",
    "\033[96m",
    "\033[97m"
};

int fprintf_color(FILE* output, console_text_colors color, const char* str, ...)
{
    int n = 0;
    va_list ap;
    va_start(ap, str);
    if (isatty(fileno(output)))
    {
        fprintf(output,"%s", color_codes[color]);
        n = vfprintf(output, str, ap);
        fprintf(output, "%s", color_codes[console_text_standart]);
    }
    else
    {
        n = vfprintf(output, str, ap);
    }
    return n;
}

void my_own_assert(int line, const char* file, int condition, const char* format, ...)
{
    if (condition)
        return;
    va_list ap;
    va_start(ap, format);
    fprintf(stderr,"%s", color_codes[console_text_red]);
    fprintf(stderr, "%s:%d ", file, line);
    vfprintf(stderr, format, ap);
    fprintf(stderr,"%s", color_codes[console_text_standart]);
    abort();
}

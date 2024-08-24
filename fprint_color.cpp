/** @file */
#include <stdio.h>
#ifdef __linux__
#include <unistd.h>
#endif
#include <stdarg.h>
#include <assert.h>
#include "fprint_color.h"

static const char* switch_color_code(console_text_colors color);

int vfprintf_color(FILE* output, console_text_colors color, const char* str, va_list ap)
{
    int n = 0;
    #if defined _WIN32
    #warning К сожалению, цветной вывод не поддерживается в вашей ОС.
    n = vfprintf(output, str, ap);
    return n;
    #elif defined __APPLE__
    #warning К сожалению, цветной вывод не поддерживается в вашей ОС.
    n = vfprintf(output, str, ap);
    return n;
    #else
    if (isatty(fileno(output)))
    {
        fprintf(output,"%s", switch_color_code(color));
        n = vfprintf(output, str, ap);
        fprintf(output, "%s", switch_color_code(console_text_standart));
    }
    else
    {
        n = vfprintf(output, str, ap);
    }
    return n;
    #endif
}

int fprintf_color(FILE* output, console_text_colors color, const char* str, ...)
{
    int n = 0;
    va_list ap;
    va_start(ap, str);
    n = vfprintf_color(output, color, str, ap);
    return n;
}

void assert_but_better(int line, const char* file, int condition, const char* format, ...)
{
    if (condition)
        return;
    va_list ap;
    va_start(ap, format);
    fprintf_color(stderr, console_text_red, "%s:%d ", file, line);
    vfprintf_color(stderr, console_text_red, format, ap);
    abort();
}

static const char* switch_color_code(console_text_colors color)
{
    switch(color)
    {
    case console_text_standart:
        return "\033[39m";
    case console_text_black:
        return "\033[30m";
    case console_text_dark_red:
        return "\033[31m";
    case console_text_dark_green:
        return "\033[32m";
    case console_text_dark_yellow:
        return "\033[33m";
    case console_text_dark_blue:
        return "\033[34m";
    case console_text_dark_magenta:
        return "\033[35m";
    case console_text_dark_cyan:
        return "\033[36m";
    case console_text_grey:
        return "\033[37m";
    case console_text_dark_grey:
        return "\033[90m";
    case console_text_red:
        return "\033[91m";
    case console_text_green:
        return "\033[92m";
    case console_text_orange:
        return "\033[93m";
    case console_text_blue:
        return "\033[94m";
    case console_text_magenta:
        return "\033[95m";
    case console_text_cyan:
        return "\033[96m";
    case console_text_white:
        return "\033[97m";
    default:
        assert(0 && "Ошибка: неизвестный код цвета.");
        return "";
    }
}

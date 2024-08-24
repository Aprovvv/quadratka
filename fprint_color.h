#ifndef FPRINT_COLOR
#define FPRINT_COLOR
#include <stdio.h>
#include <stdlib.h>

enum console_text_colors
{
    console_text_standart,
    console_text_black,
    console_text_dark_red,
    console_text_dark_green,
    console_text_dark_yellow,
    console_text_dark_blue,
    console_text_dark_magenta,
    console_text_dark_cyan,
    console_text_grey,
    console_text_dark_grey,
    console_text_red,
    console_text_green,
    console_text_orange,
    console_text_blue,
    console_text_magenta,
    console_text_cyan,
    console_text_white
};

int fprintf_color(FILE* output, console_text_colors color, const char* str, ...);
#endif

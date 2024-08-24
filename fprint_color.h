/** @file */
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
/**
 * Функция цветной печати (если печатаем в файл, то печатает обычным цветом). Способ вывода аналогичен printf
 * \param output {Указатель на файл}
 * \param color {Цвет. Должен быть членом enum console_text_colors}
 * \param str {Строка форматирования}
 * \param ... {Другие аргументы, которые надо вывести}
 */
int fprintf_color(FILE* output, console_text_colors color, const char* str, ...);

/**
 * Как assert, только лучше. Вызывается с помощью макроса ASSERT
 * \param line {строка, в которой произошла ошибка. ВВОДИТЬ НЕ НАДО, ЭТО СДЕЛАЕТ МАКРОС}
 * \param file {имя файла, в котором произошла ошибка. ВВОДИТЬ НЕ НАДО, ЭТО СДЕЛАЕТ МАКРОС}
 * \param condition {Условие, при невыполнении которого выводится ошибка}
 * \param format {Строка форматирования}
 * \param ... {Другие аргументы, которые надо вывести}
 */
void assert_but_better(int line, const char* file, int condition, const char* format, ...);

/**
 * Используется для удобного вызова my_own_assert.
 * \param condition {Условие, при невыполнении которого выводится ошибка}
 * \param format {Строка форматирования}
 * \param ... {Другие аргументы, которые надо вывести}
 */

int vfprintf_color(FILE* output, console_text_colors color, const char* str, va_list ap);
#define ASSERT(...) assert_but_better(__LINE__, __FILE__, __VA_ARGS__)
#endif

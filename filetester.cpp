/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <unistd.h>
#include "quadlin.h"
#include "filetester.h"
#include "language.h"
#include "fprint_color.h"

extern int lang_flag;
extern const struct print_data phrases[2];

const int ROOT_SIGN_COUNT = 3;

static int quad_equal(struct quad a, struct quad b, double eps);//1, если структуры а и b равны, 0 если нет
static void print_test_error(struct quad file_answer, struct quad func_answer, int line);//печатает инфу о неверно пройденном тесте

int filetester(const char* filename)
{
    setlocale(LC_ALL, phrases[lang_flag].locale_name);
    FILE* fp = fopen(filename, "r");
    if (errno != 0)
    {
        if (isatty(2))
            fprintf(stderr, CONSOLE_COLOR_RED "%s %s\n" CONSOLE_COLOR_STANDART, phrases[lang_flag].pr_file_nopen, strerror(errno));
        else
            fprintf(stderr, "%s %s\n", phrases[lang_flag].pr_file_nopen, strerror(errno));
        errno = 0;
        return 1;
    }
    setlocale(LC_ALL, "C");

    int line = 0;
    int all_correct = 1;
    double a_coef=0, b_coef=0, c_coef=0;
    struct quad file_answer = {};
    struct quad func_answer = {};
    int scan_count;
    while ((scan_count = fscanf(fp, "%lf,%lf,%lf,%i,%lf,%lf", &a_coef, &b_coef, &c_coef, &file_answer.count, &file_answer.x1, &file_answer.x2)) != EOF)
    {
        line++;
        if (scan_count != 6)
            fprintf_color(stderr, CONSOLE_COLOR_RED, "%s %d\n", phrases[lang_flag].pr_read_err, line);
        func_answer = quad_solve(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
        if (quad_equal(file_answer, func_answer, pow(10, -ROOT_SIGN_COUNT)) == 0)
        {
            all_correct = 0;
            print_test_error(file_answer, func_answer, line);
        }
    }
    if (all_correct)
        fprintf_color(stdout, CONSOLE_COLOR_GREEN, "%s", phrases[lang_flag].pr_test_pass);
    fclose(fp);
    return 0;//
}

/**
 * Функция для сравнения двух структур типа quad. Просто сравнить их нельзя из-за наличия double.
  * \param a, b - сравниваемые структуры
  * \param eps - точность сравнения double
 * \return 1, если структуры а и b равны, 0 если нет.
*/
static int quad_equal (struct quad a, struct quad b, double eps)
{
    return ((a.count == b.count) && (cmpdoubles(a.x1, b.x1, eps) == 0) && (cmpdoubles(a.x2, b.x2, eps) == 0));
}

/**
 * Функция, которая печатает инфу о проведенном тесте.
 * \param file_answer {Правильные ответы}
 * \param func_answer {Полученные ответы}
 * \param line {Строка, в которой произошла ошибка}
 */
static void print_test_error(struct quad file_answer, struct quad func_answer, int line)
{

    fprintf_color(stdout, CONSOLE_COLOR_RED, "%s %i\n", phrases[lang_flag].pr_test_err, line);
    fprintf_color(stdout, CONSOLE_COLOR_RED, "%s %i %.*f %.*f\n", phrases[lang_flag].pr_exp, file_answer.count, ROOT_SIGN_COUNT, file_answer.x1, ROOT_SIGN_COUNT, file_answer.x2);
    fprintf_color(stdout, CONSOLE_COLOR_RED, "%s %i %.*f %.*f\n\n", phrases[lang_flag].pr_res, func_answer.count, ROOT_SIGN_COUNT, func_answer.x1, ROOT_SIGN_COUNT, func_answer.x2);
}

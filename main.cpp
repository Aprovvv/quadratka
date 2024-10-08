/**@file */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>
#include "quadlin.h"
#include "filetester.h"
#include "flag.h"
#include "language.h"
#include "color_print/color_print.h"

//const char flags[] = "h/help;f/filetest/test/t;e/eng/english";
const int ROOT_SIGN_COUNT = 3;                 //число знаков после запятой при выводе корней
extern const struct print_data phrases[2];
const struct flag_struct flags[3] =
{ {'h', "help"}, {'t', "test"}, {'e', "english"} };

static void print_menu(void);                  //функция которая выдает приглашение на ввод
static void print_roots(const struct quad);    //функция которая печатает корни
static void clean_buf(void);                   //функция для очистки буфера
static void print_help(void);                  //выводит справку флага -h
static int start_filetest(void);               //вызывает тестирование из файла (флаг -f)
static int sget(char* str, int sizasserte);    //функция для чтения строки без \n на конце
static void arg_analyze(int argc, char** argv);//проходится по всем argv и выбирает, чо с ними делать

int lang_flag = 0;//переменная, отвечающая за язык

int main(int argc, char** argv)
{
    arg_analyze(argc, argv);
    double a_coef = 0, b_coef = 0, c_coef = 0;
    int scan_return = 0;
    struct quad root = {};
    print_menu();

    while((scan_return = scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef)) != EOF)
    {
        clean_buf();
        if (scan_return == 3)
        {
            root = quad_solve(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
            print_roots(root);
            print_menu();
        }
        else
        {
            printf("%s", phrases[lang_flag].pr_numb);
            clean_buf();
        }
    }
    return 0;
}

/**
 * Функция которая выдает приглашение на ввод.
 */
static void print_menu(void)
{
    printf("%s", phrases[lang_flag].pr_menu);
}

/**
 * Функция, которая печатает корни.
 * \param r {Структура quad, содеражащая корни.}
 */
static void print_roots(const struct quad r)
{
    switch (r.count)
    {
    case ZERO_ROOTS:
        printf("%s", phrases[lang_flag].pr_no_roots);
        break;
    case ONE_ROOT:
        printf("%s", phrases[lang_flag].pr_one_root);
        printf("x = %.*f\n\n", ROOT_SIGN_COUNT, r.x1);
        break;
    case TWO_ROOTS:
        printf("%s", phrases[lang_flag].pr_two_roots);
        printf("x1 = %.*f\n", ROOT_SIGN_COUNT, r.x1);
        printf("x2 = %.*f\n\n", ROOT_SIGN_COUNT, r.x2);
        break;
    case INF_ROOTS:
        printf("%s", phrases[lang_flag].pr_inf_roots);
        ASSERT_BUT_BETTER(1==2, "Ошибка: неожиданное число корней, равное %d\n", r.count);
        break;
    case OVERFLOW_ERR:
        fprintf_color(stderr, CONSOLE_TEXT_RED, "%s", phrases[lang_flag].inf_or_nan);
        break;
    default:
        ASSERT_BUT_BETTER(0, "Ошибка: неожиданное число корней, равное %d\n", r.count);
    }
}

/**
 * Функция для очистки буфера.
 */
static void clean_buf(void)
{
    int ch = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
        continue;
}

/**
 * Функция для вызова тестирования из файла (флаг -f).
 */
static int start_filetest(void)
{
    char filename[PATH_MAX] = "";
    do
    {
        printf("%s", phrases[lang_flag].pr_filename);
        if(sget(filename, PATH_MAX))
            return 1;
        if(strcmp(filename,"#") == 0)
            return 0;
    } while(filetester(filename) != 0);
    return 0;
}

/**
 * Функция, которая выводит справку (флаг -h)
 */
static void print_help(void)
{
    printf("%s", phrases[lang_flag].pr_help);
}

/**
 * Функция для чтения строки без '\n' на конце.
 * \param str {Адрес строки, в которую записываем считанные данные.}
 * \param size {Длина строки str.}
 */
static int sget (char* str, int size)
{
    int ch = 'a';
    int count = 0;
    while ((ch = getchar()) != '\n' && count != size-2)
    {
        if (ch == EOF)
            return 1;
        str[count++] = (char)ch;
    }
    str[count] = '\0';
    return 0;
}

/**
 * Функция проходится по всем argv и выбирает, вызывает analyse_flag и вызывает
 * соответствующие функции при опознанных флагах
 * \param argc {Копия argc из main}
 * \param argv {Копия argv из main}
 */
static void arg_analyze(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        int flag = analyze_flag(flags, sizeof(flags)/sizeof(struct flag_struct), argv[i]);
        switch (flag)
        {
        case 'h':
            print_help();
            break;
        case 't':
            if(start_filetest())
                exit(EXIT_SUCCESS);
            break;
        case 'e':
            lang_flag = 1;
            break;
        default:
            fprintf_color(stderr, CONSOLE_TEXT_RED, phrases[lang_flag].pr_fl_err);
            print_help();
        }
    }
}

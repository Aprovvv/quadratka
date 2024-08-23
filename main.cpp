/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "quadlin.h"
#include "filetester.h"
#include "flag.h"

const char* flags = "hf";
const int ROOT_SIGN_COUNT = 3;          //число знаков после запятой при выводе корней

void print_menu(void);                  //функция которая выдает приглашение на ввод
void print_roots(const struct quad);    //функция которая печатает корни
void clean_buf(void);                   //функция для очистки буфера
void print_help(void);                  //выводит справку флага -h
void start_filetest(void);              //вызывает тестирование из файла (флаг -f)
int sget (char* str, int sizasserte);   //функция для чтения строки без \n на конце

int main(int argc, char** argv)
{
    //puts(s);
    for (int i = 1; i < argc; i++)
    {
        int n = analyse_flag(argv[i], flags, strlen(flags));
        switch (n)
        {
        case 'h':
            print_help();
            break;
        case 'f':
            start_filetest();
            break;
        default:
            printf(RED"Ошибка: неопознанный флаг \"%c\"\n"STANDART, n);
            print_help();
        }
    }
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
            printf("Введите число\n");
            clean_buf();
        }
    }
    return 0;
}

/**
 * Функция которая выдает приглашение на ввод.
 */
void print_menu(void)
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n"
    "Для завершения введите EOF\n");
}

/**
 * Функция, которая печатает корни.
 * \param r {Структура quad, содеражащая корни.}
 */
void print_roots(const struct quad r)
{
    switch (r.count)
    {
    case ZERO_ROOTS:
        printf("Нет корней\n\n");
        break;
    case ONE_ROOT:
        printf("Уравнение имеет один корень:\n");
        printf("x = %.*f\n\n", ROOT_SIGN_COUNT, r.x1);
        break;
    case TWO_ROOTS:
        printf("Уравнение имеет два корня:\n");
        printf("x1 = %.*f\n", ROOT_SIGN_COUNT, r.x1);
        printf("x2 = %.*f\n\n", ROOT_SIGN_COUNT, r.x2);
        break;
    case INF_ROOTS:
        printf("Любое число является решением\n\n");
        break;
    default:
        assert("Ошибка: неожиданное число корней" && 0);
    }
}

/**
 * Функция для очистки буфера.
 */
void clean_buf(void)
{
    int ch = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
        continue;
}

/**
 * Функция для вызова тестирования из файла (флаг -f).
 */
void start_filetest(void)
{
    char filename[PATH_MAX] = "";
    printf("Введите имя файла с данными для тестирования или # для отмены:\n");
    sget(filename, PATH_MAX);
    //printf("%d %d", filetester(filename) != 0, strcmp(filename,"#") != 0);
    while(filetester(filename) && strcmp(filename,"#") != 0)
    {
        strcpy(filename, "");
        printf("Введите имя файла с данными для тестирования или EOF для отмены тестирования:\n");
        if (sget(filename, PATH_MAX))
            return;
    }
}

/**
 * Функция, которая выводит справку (флаг -h)
 */
void print_help(void)
{
    printf("Добро пожаловать в квадратку!\n"
    "Введите ./a.out для запуска программы.\n"
    "Также доступны следующие флаги:\n"
    "-h: помощь;\n"
    "-f: тестирование по данным из файла (нужен файл с именем testdata.csv для работы).\n\n");
}

/**
 * Функция для чтения строки без '\n' на конце.
 * \param str {Адрес строки, в которую записываем считанные данные.}
 * \param size {Длина строки str.}
 */
int sget (char* str, int size)
{
    int ch = 'a';
    int count = 0;
    while ((ch = getchar()) != '\n' && count!= size-2)
    {
        if (ch == EOF)
            return 1;
        str[count++] = (char)ch;
    }
    str[count] = '\0';
    return 0;
}

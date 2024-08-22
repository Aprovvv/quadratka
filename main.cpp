#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "quadlin.h"
#include "filetester.h"
#include "flag.h"
#include <assert.h>
#include <string.h>

const char* flags = "hf";
const int ROOT_SIGN_COUNT = 3; //число знаков после запятой при выводе корней

void print_menu(void);//функция которая выдает приглашение на ввод
void print_roots(const struct quad);//функция которая печатает корни
void clean_buf(void);//функция для очистки буфера
void print_help(void);//выводит справку флага -h
void start_filetest(void);//вызывает тестирование из файла (флаг -f)
void sget (char* str, int size);//функция для чтения строки без \n на конце

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        int n = analyse_flags(argv[i], flags, (int)strlen(flags));
        switch (n)
        {
        case 'h':
            print_help();
            break;
        case 'f':
            start_filetest();
            break;
        default:
            printf("Ошибка: неопознанный флаг\n");
        }
    }
    double a_coef = 0, b_coef = 0, c_coef = 0;
    int scan_return = 0;
    struct quad root = {};

    setlocale(LC_ALL, "RUS");
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

//функция которая выдает приглашение на ввод
void print_menu(void)//функция которая выдает приглашение на ввод
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n"
    "Для завершения введите EOF\n");
}

//функция которая печатает корни
void print_roots(const struct quad r)//функция которая печатает корни
{
    switch (r.count)
    {
    case 0:
        printf("Нет корней\n\n");
        break;
    case 1:
        printf("Уравнение имеет один корень:\n");
        printf("x = %.*f\n\n", ROOT_SIGN_COUNT, r.x1);
        break;
    case 2:
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

//функция для очистки буфера
void clean_buf(void)
{
    int ch = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
        continue;
}

//вызывает тестирование из файла (флаг -f)
void start_filetest(void)
{
    char filename[100];
    printf("Введите имя файла с данными для тестирования:\n");
    sget(filename, 100);
    filetester(filename);
}

//выводит справку флага -h
void print_help(void)
{
    printf("Добро пожаловать в квадратку!\n"
    "Введите ./a.out для запуска программы.\n"
    "Также доступны следующие флаги:\n"
    "-h: помощь;\n"
    "-f: тестирование по данным из файла (нужен файл с именем testdata.csv для работы).\n\n");
}

//функция для чтения строки без \n на конце
void sget (char* str, int size)
{
    int ch = 'a';
    int count = 0;
    while ((ch = getchar()) != '\n' && count!= size-2)
        str[count++] = (char)ch;
    str[count] = '\0';
}

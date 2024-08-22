#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "quadlin.h"
#include "filetester.h"
#include <errno.h>
#include <locale.h>

#define GREEN "\033[92m"
#define RED "\033[91m"
#define STANDART "\033[39m"
const int ROOT_SIGN_COUNT = 3;

static int quad_equal (struct quad a, struct quad b, double eps);//1, если структуры а и b равны, 0 если нет
static void print_test_error(struct quad file_answer, struct quad func_answer, int line);//печатает инфу о неверно пройденном тесте

void filetester(const char* filename)
{
    //setlocale(LC_ALL, "RUS");
    //setlocale(LC_ALL, "RUS");
    //printf("%s\n", s);
    setlocale(LC_ALL, "ru_RU.utf8");
    FILE* fp = fopen(filename, "r");
    if (errno != 0)
    {
        printf("Не удалось открыть файл: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
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
        {
            printf("Ошибка чтения из файла в строке %d\n", line);
            exit(EXIT_FAILURE);
        }
        func_answer = quad_solve(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
        if (quad_equal(file_answer, func_answer, pow(10, -ROOT_SIGN_COUNT)) == 0)
        {
            all_correct = 0;
            print_test_error(file_answer, func_answer, line);
        }
    }
    if (all_correct)
        printf(GREEN"Все тесты успешно пройдены!\n\n"STANDART);
}

//1, если структуры а и b равны, 0 если нет
static int quad_equal (struct quad a, struct quad b, double eps)
{
    return ((a.count == b.count) && (cmpdoubles(a.x1, b.x1, eps) == 0) && (cmpdoubles(a.x2, b.x2, eps) == 0));
}

//печатает инфу о неверно пройденном тесте
static void print_test_error(struct quad file_answer, struct quad func_answer, int line)
{
    printf(RED"Ошибка в тесте %i\n", line);
    printf("Ожидаемые значения: %i %.*f %.*f\n", file_answer.count, ROOT_SIGN_COUNT, file_answer.x1, ROOT_SIGN_COUNT, file_answer.x2);
    printf("Полученные значения: %i %.*f %.*f\n\n"STANDART, func_answer.count, ROOT_SIGN_COUNT, func_answer.x1, ROOT_SIGN_COUNT, func_answer.x2);
}

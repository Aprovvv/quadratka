#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "quadlin.h"
#include "filetester.h"

const int ROOT_SIGN_COUNT = 3;

static int quad_equal (struct quad a, struct quad b, double eps);//1, если структуры а и b равны, 0 если нет
static void print_test_error(struct quad file_answer, struct quad func_answer, int line);//печатает инфу о неверно пройденном тесте

void filetester(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Не удается открыть файл\n");
        exit(EXIT_FAILURE);
    }

    int line = 0;
    int all_correct = 1;
    double a_coef=0, b_coef=0, c_coef=0;
    struct quad file_answer = {};
    struct quad func_answer = {};

    while (fscanf(fp, "%lf,%lf,%lf,%i,%lf,%lf", &a_coef, &b_coef, &c_coef, &file_answer.count, &file_answer.x1, &file_answer.x2) != EOF)
    {
        line++;
        func_answer = quad_solve(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
        if (quad_equal(file_answer, func_answer, pow(10, -ROOT_SIGN_COUNT)) == 0)
        {
            all_correct = 0;
            print_test_error(file_answer, func_answer, line);
        }
    }
    if (all_correct)
        printf("\033[92mВсе тесты успешно пройдены!\n\n\033[39m");
}

//1, если структуры а и b равны, 0 если нет
static int quad_equal (struct quad a, struct quad b, double eps)
{
    return ((a.count == b.count) && (cmpdoubles(a.x1, b.x1, eps) == 0) && (cmpdoubles(a.x2, b.x2, eps) == 0));
}

//печатает инфу о неверно пройденном тесте
static void print_test_error(struct quad file_answer, struct quad func_answer, int line)
{
    printf("\033[91mОшибка в тесте %i\n\033[39m", line);
    printf("\033[91mОжидаемые значения: %i %.*f %.*f\n\033[39m", file_answer.count, ROOT_SIGN_COUNT, file_answer.x1, ROOT_SIGN_COUNT, file_answer.x2);
    printf("\033[91mПолученные значения: %i %.*f %.*f\n\n\033[39m", func_answer.count, ROOT_SIGN_COUNT, func_answer.x1, ROOT_SIGN_COUNT, func_answer.x2);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "quadlin.h"

const int ROOT_SIGN_COUNT = 3;

int quad_equal (struct quad a, struct quad b, double eps);

int main()
{
    FILE* fp = fopen("testdata.txt", "r"); 
    if (fp == NULL)
    {
        printf("Не удается открыть файл\n");
        exit(EXIT_FAILURE);
    }
    //rewind(fp);
    int line = 0;
    double a_coef=0, b_coef=0, c_coef=0;
    struct quad file_answer = {};
    struct quad func_answer = {};
    
    while (fscanf(fp, "%lf %lf %lf %i %lf %lf", &a_coef, &b_coef, &c_coef, &file_answer.count, &file_answer.x1, &file_answer.x2) != EOF)
    {
        line++;
        func_answer = quad_solve(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
        if (quad_equal(file_answer, func_answer, pow(10, -ROOT_SIGN_COUNT)) == 0)
        {
            printf("Ошибка в тесте %i\n", line); 
            printf("Ожидаемые значения: %i %.*f %.*f\n", file_answer.count, ROOT_SIGN_COUNT, file_answer.x1, ROOT_SIGN_COUNT, file_answer.x2);
            printf("Полученные значения: %i %.*f %.*f\n\n", func_answer.count, ROOT_SIGN_COUNT, func_answer.x1, ROOT_SIGN_COUNT, func_answer.x2);
        }
    }
    printf("Все тесты пройдены.\n");
}

int quad_equal (struct quad a, struct quad b, double eps)
{
    return ((a.count == b.count) && (cmpdoubles(a.x1, b.x1, eps) == 0) && (cmpdoubles(a.x2, b.x2, eps) == 0));
}

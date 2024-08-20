#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "quad.h"
#include <assert.h>
#include <string.h>

const int ROOT_SIGN_COUNT = 3; //число знаков после запятой при выводе корней
const char* EXIT_CODE = "exit";

void print_menu(void);//функция которая выдает приглашение на ввод
void print_roots(int count, double x1, double x2);//функция которая печатает корни

int main()
{
    double a_coef = 0, b_coef = 0, c_coef = 0;
    double x1 = 0, x2 = 0;
    int count = 0;
    struct roots root = {0, 0};
    
    setlocale(LC_ALL, "RUS");
    print_menu();

    /*while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        count = solve_equation(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT, &x1, &x2);
        print_roots(count, x1, x2);
        print_menu();
    }*/
    
    
    while(1)
    {
        if (scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
        {
            count = solve_equation(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT, &x1, &x2);
            print_roots(count, x1, x2);
            print_menu();
        } else {
            char s[5];
            fgets(s, 5, stdin);
            if (strcmp(s, EXIT_CODE) == 0)
                exit(EXIT_SUCCESS);
            printf("Ошибка: неправильный формат. Введите 3 числа или exit, чтобы завершить выполнение\n");
            while (getchar() != '\n')
                continue;
        }
    }
    

    return 0;
}

void print_menu(void)//функция которая выдает приглашение на ввод
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n");
    printf("Для завершения введите любой нечисловой символ\n");
}

void print_roots(int count, double x1, double x2)//функция которая печатает корни
{
    switch (count)
    {
    case 0:
        printf("Нет корней\n\n");
        break;
    case 1:
        printf("Уравнение имеет один корень:\n");
        printf("x = %.*f\n\n", ROOT_SIGN_COUNT, x1);
        break;
    case 2:
        printf("Уравнение имеет два корня:\n");
        printf("x1 = %.*f\n", ROOT_SIGN_COUNT, x1);
        printf("x2 = %.*f\n\n", ROOT_SIGN_COUNT, x2);
        break;
    case INF_ROOTS:
        printf("Любое число является решением\n\n");
        break;
    default:
        assert("Ошибка: неожиданное число корней" && 0);
    }
}

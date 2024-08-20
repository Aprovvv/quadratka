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
void print_roots(int count, const struct roots);//функция которая печатает корни

int main()
{
    double a_coef = 0, b_coef = 0, c_coef = 0;
    int count = 0, scan_return = 0;
    struct roots root = {};
    
    setlocale(LC_ALL, "RUS");
    print_menu();
   
    while((scan_return = scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef)) != EOF)
    {
        if (scan_return == 3)
        {
            count = solve_equation(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT, &root);
            print_roots(count, root);
            print_menu();
        } 
        else 
        {
            printf("Введите число\n");
            while (getchar() != '\n')
                continue;
        }
    }
    

    return 0;
}

void print_menu(void)//функция которая выдает приглашение на ввод
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n");
    printf("Для завершения введите EOF\n");
}

void print_roots(int count, const struct roots r)//функция которая печатает корни
{
    switch (count)
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

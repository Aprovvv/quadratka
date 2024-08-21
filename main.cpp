#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "quadlin.h"
#include <assert.h>
#include <string.h>

const int ROOT_SIGN_COUNT = 3; //число знаков после запятой при выводе корней

void print_menu(void);//функция которая выдает приглашение на ввод
void print_roots(const struct quad);//функция которая печатает корни
void clean_buf(void);

int main()
{
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
            root = quad_solver(a_coef, b_coef, c_coef, ROOT_SIGN_COUNT);
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

void print_menu(void)//функция которая выдает приглашение на ввод
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n");
    printf("Для завершения введите EOF\n");
}

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

void clean_buf(void)
{
    while (getchar() != '\n')
        continue;
}

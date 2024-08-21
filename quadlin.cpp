#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadlin.h"

static int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью. Объявил как статик, т.к. она нужна только в quad.cpp

/**
Функция для решения квадратного уравнения

\param[double] a, b, c {коэффициенты квадратного уравнения}
\return структуру quad, содержащую количество корней и их значения. Если корень 1, то его значение содержится в x1. Если корней <2, то остальные корни нули.
*/
struct quad quad_solver(double a, double b, double c, int root_sign_count)
{
    double D = b*b - 4*a*c;
    struct quad answer = {};

     //случай нет корней
    if (D < 0)
    {
        answer.count = 0;
        return answer;
    }
    double sqrtD = sqrt(D);
    //случай нулевых коэффициентов
    if (0 == cmpdoubles(a, 0, EPS_COEF))
    {
        struct lin lin_ans = lin_solver(b, c);
        if (lin_ans.count == 1)
        {
            answer.count = 1;
            answer.x1 = lin_ans.x;
            return answer;
        }
        else
        {
            answer.count = lin_ans.count;
            return answer;
        }
    }
    //случай 1 корень
    if (0 == cmpdoubles(sqrtD/a, 0, pow(10, -root_sign_count)))//пренебрегаем разницей между корнями порядка 10^-root_sign_count, т.к. выводим с такой точностью
    {
        answer.x1 = -b/(2*a);
        answer.count = 1;
        return answer;
    }
    //случай 2 корня
    answer.x1 = (-b - sqrtD)/2/a;
    answer.x2 = (-b + sqrtD)/2/a;
    answer.count = 2;
    return answer;
}

/**
Функция для решения линейного уравнения.
\param[double] k, b
\return структуру lin, содержащую количество корней и значения. Если корней бесконечно или 0, корень нулевой.
*/
struct lin lin_solver(double k, double b)
{
    struct lin answer = {};
    if (0 == cmpdoubles(k, 0, EPS_COEF))
    {
        if (0 == cmpdoubles(b, 0, EPS_COEF))
        {
            answer.count = INF_ROOTS;
            return answer;
        }
        else
        {
            answer.count = 0;
            return answer;
        }
    }
    else
    {
        answer.x = -b/k;
        answer.count = 1;
        return answer;
    }
}

/**функция для сравнения даблов с заданной точностью
\param[double] a, b {сравниваемые чиса}
\param[double] eps {точность сравнения}
\return -1 если a<b; 0 если a=b; +1 если a>b
*/
static int cmpdoubles(double a, double b, double eps)
{
    if (fabs(a-b) < eps)
        return 0;
    if (a < b)
        return -1;
    else
        return 1;
}

/**@file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadlin.h"
#include <assert.h>

// iee754 floating point
struct quad quad_solve(double a, double b, double c, int root_sign_count)
{
    double D = b*b - 4*a*c;
    struct quad answer = {};

    if (!isfinite(a) && !isfinite(b) && !isfinite(c))
    {
        answer.count = OVERFLOW_ERR;
        return answer;
    }
     //случай нет корней
    if (D < 0)
    {
        answer.count = 0;
        return answer;
    }
    double sqrtD = sqrt(D);
    //случай нулевых коэффициентов
    if (cmpdoubles(a, 0, EPS_COEF) == 0)
    {
        struct lin lin_ans = lin_solve(b, c);
        if (lin_ans.count == 1)
        {
            answer.count = 1;
            answer.x1 = lin_ans.x;
            if (!isfinite(answer.x1))
            {
                answer.count = OVERFLOW_ERR;
                return answer;
            }
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
    if (a > 0)
    {
        answer.x1 = (-b - sqrtD)/2/a;
        answer.x2 = (-b + sqrtD)/2/a;
    }
    else
    {
        answer.x1 = (-b + sqrtD)/2/a;
        answer.x2 = (-b - sqrtD)/2/a;
    }
    if (!isfinite(answer.x1) || !isfinite(answer.x2))
    {
        answer.count = OVERFLOW_ERR;
        return answer;
    }
    answer.count = 2;
    return answer;
}

/**
Функция для решения линейного уравнения.
\param k, b {коэффициенты линейного уравнения}
\return структуру lin, содержащую количество корней и значения. Если корней бесконечно или 0, корень нулевой.
*/
struct lin lin_solve(double k, double b)
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

int cmpdoubles(double a, double b, double eps)
{
    if (fabs(a-b) < eps)
        return 0;
    if (a < b)
        return -1;
    else
        return 1;
}

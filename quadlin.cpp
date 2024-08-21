#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadlin.h"

static int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью. Объявил как статик, т.к. она нужна только в quad.cpp

//функция, которая решает уравнение и возвращает количество корней
//Переменные записываются по адресам х1 и х2
//Если корень 1, то он записывается в х1
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

//функция для сравнения даблов с заданной точностью
//-1 = a<b; 0 = a=b; +1 = a>b
static int cmpdoubles(double a, double b, double eps)
{
    if (fabs(a-b) < eps)
        return 0;
    if (a < b)
        return -1;
    else
        return 1;
}

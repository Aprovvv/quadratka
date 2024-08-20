#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quad.h"

static int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью. Объявил как статик, т.к. она нужна только в quad.cpp

//функция, которая решает уравнение и возвращает количество корней
//Переменные записываются по адресам х1 и х2
//Если корень 1, то он записывается в х1
int solve_equation(double a, double b, double c, int root_sign_count, struct roots *r_adr)
{
    double D = b*b - 4*a*c;

     //случай нет корней
    if (D < 0)
        return 0;
    double sqrtD = sqrt(D);
    //случай нулевых коэффициентов
    if (0 == cmpdoubles(a, 0, EPS_COEF))
    {
        if (0 == cmpdoubles(b, 0, EPS_COEF))
        {
            if (0 == cmpdoubles(c, 0, EPS_COEF))
                return INF_ROOTS;
            else
                return 0;
        }
    else
    {
        r_adr->x1 = -c/b;
        return 1;
    }
    }
    //случай 1 корень
    if (0 == cmpdoubles(sqrtD/a, 0, pow(10, -root_sign_count)))//пренебрегаем разницей между корнями порядка 10^-root_sign_count, т.к. выводим с такой точностью
    {
        r_adr->x1 = -b/(2*a);
        return 1;
    }
    //случай 2 корня
    r_adr->x1 = (-b - sqrtD)/2/a;
    r_adr->x2 = (-b + sqrtD)/2/a;
    return 2;
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

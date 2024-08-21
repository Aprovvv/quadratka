#ifndef QUAD_H
#define QUAD_H

//константы заменил на макросы, чтобы если что их можно было определить самому в файле кода
#ifndef INF_ROOTS
#define INF_ROOTS (-1) //возвращаемое значение solve_equation, если корней бесконечно много
#endif
#ifndef EPS_COEF
#define EPS_COEF (1e-7) //точность определения нулевых коэффициентов
#endif

struct quad
{
    int count;
    double x1;
    double x2;
};
struct lin
{
    int count;
    double x;
};

/**
 *Функция для решения квадратного уравнения
 *
 * \param a, b, c {коэффициенты квадратного уравнения}
 * \return структуру quad, содержащую количество корней и их значения. Если корень 1, то его значение содержится в x1. Если корней <2, то остальные корни нули.
*/
struct quad quad_solve(double a, double b, double c, int root_sign_count);//функция, которая решает уравнение и возвращает количество корней
struct lin lin_solve(double k, double b);
int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью
#endif

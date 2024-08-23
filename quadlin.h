/**@file */
#ifndef QUAD_H
#define QUAD_H

const double EPS_COEF = 1e-7;

enum root_count {INF_ROOTS = -1, ZERO_ROOTS, ONE_ROOT, TWO_ROOTS};

/**
 * Структура для хранения решений квадратного уравнения
 * Состоит из:
 * int count - количество корней
 * double x1 - первый корень (0 если корней 0)
 * double x2 - второй корень (0 если корней 0 или 1)
 */
struct quad
{
    int count;
    double x1;
    double x2;
};
/**
 * Структура для хранения решений квадратного уравнения
 * Состоит из:
 * int count - количество корней
 * double x - корень (0 если корней 0)
 */
struct lin
{
    int count;
    double x;
};

struct quad quad_solve(double a, double b, double c, int root_sign_count);//функция, которая решает уравнение и возвращает количество корней
struct lin lin_solve(double k, double b);
int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью
#endif

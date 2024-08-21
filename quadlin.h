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

struct quad quad_solver(double a, double b, double c, int root_sign_count);//функция, которая решает уравнение и возвращает количество корней
struct lin lin_solver(double k, double b);
#endif

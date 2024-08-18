#ifndef QUAD_H
    #define QUAD_H
    
    //константы заменил на макросы, чтобы если что их можно было определить самому в файле кода
    #ifndef INF_ROOTS
        #define INF_ROOTS (-1) //возвращаемое значение solve_equation, если корней бесконечно много
    #endif
    #ifndef EPS_COEF
        #define EPS_COEF (1e-7) //точность определения нулевых коэффициентов
    #endif

    int solve_equation(double a, double b, double c, int root_sign_count, double *x1, double *x2);//функция, которая решает уравнение и возвращает количество корней
    int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью
#endif

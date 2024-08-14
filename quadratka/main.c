#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>

//прототипы функций
void solve_equation(double a, double b, double c);//функция, которая решает уравнение
void print_menu(void);

int main()
{
    //объявление переменных
    double a_coef=0, b_coef=0, c_coef=0;

    print_menu();

    //ввод значений
    while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        solve_equation(a_coef, b_coef, c_coef);
        print_menu();
    }

    return 0;
}

void solve_equation(double a, double b, double c)//функция, которая решает уравнение
{
    // объявление переменных
     double D = b*b - 4*a*c;

     //случай нет корней
     if (D<0)
     {
        printf("Дискриминант меньше нуля. Нет корней\n\n");
        return;
     }
     //случай нулевых коэффициентов
     if (fabs(a)<1e-7)
     {
        if (fabs(b)<1e-7)
        {
            if (fabs(c)<1e-7)
                printf("Любое число является решением\n\n");
            else
                printf("Нет корней\n\n");
        }
        else
        {
            double x = -c/b;
            printf("Уравнение имеет один корень\n");
            printf("x = %.3f\n\n", x);
        }
        return;
     }
     //случай 1 корень
     if (sqrt(D)/a<0.001)//пренебрегаем разницей между корнями порядка 10^-3, т.к. выводим с такой точностью
     {
        double x = -b/(2*a);
        printf("Дискриминант равен нулю. Уравнение имеет один корень\n");
        printf("x = %.3f\n\n", x);
        return;
     }
     //случай 2 корня
     double x1, x2;
     x1 = (-b - sqrt(D))/2/a;
     x2 = (-b + sqrt(D))/2/a;
     printf("Уравнение имеет два корня:\n");
     printf("x1 = %.3f\n", x1);
     printf("x2 = %.3f\n\n", x2);
}

void print_menu(void)
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n");
    printf("Для завершения введите любой нечисловой символ\n");
}

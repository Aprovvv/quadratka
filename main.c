#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

#define INF_ROOTS -1 //возвращаемое значение solve_equation, если корней бесконечно много
#define ROOT_SING_COUNT 3 //число знаков после запятой при выводе корней
#define EPS_COEF 1e-7 //точность определения нулевых коэффициентов

int solve_equation(double a, double b, double c, double *x1, double *x2);//функция, которая решает уравнение и возвращает количество корней
void print_menu(void);//функция которая выдает приглашение на ввод
void print_roots(int count, double x1, double x2);//функция которая печатает корни
bool eqdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью

int main()
{
    double a_coef=0, b_coef=0, c_coef=0;
    double x1 = 0, x2 = 0;
    int count = 0;

    setlocale(LC_ALL, "RUS");

    print_menu();

    while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        count = solve_equation(a_coef, b_coef, c_coef, &x1, &x2);
        print_roots(count, x1, x2);
        print_menu();
    }

    return 0;
}

//функция, которая решает уравнение и возвращает количество корней
//Переменные записываются по адресам х1 и х2
//Если корень 1, то он записывается в х1
int solve_equation(double a, double b, double c, double *x1_adress, double *x2_adress)
{
     double D = b*b - 4*a*c;
     double sqrtD = sqrt(D);

     //случай нет корней
     if (D<0)
        return 0;
     //случай нулевых коэффициентов
     if (eqdoubles(a, 0, EPS_COEF))
     {
        if (eqdoubles(b, 0, EPS_COEF))
        {
            if (eqdoubles(c, 0, EPS_COEF))
                return INF_ROOTS;
            else
                return 0;
        }
        else
        {
            *x1_adress = -c/b;
            return 1;
        }
     }
     //случай 1 корень
     if (eqdoubles(sqrtD/a, 0, pow(10, -ROOT_SING_COUNT)))//пренебрегаем разницей между корнями порядка 10^-ROOT_SING_COUNT, т.к. выводим с такой точностью
     {
        *x1_adress = -b/(2*a);
        return 1;
     }
     //случай 2 корня
     *x1_adress = (-b - sqrtD)/2/a;
     *x2_adress = (-b + sqrtD)/2/a;
     return 2;
}

void print_menu(void)//функция которая выдает приглашение на ввод
{
    printf("Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n");
    printf("Для завершения введите любой нечисловой символ\n");
}

void print_roots(int count, double x1, double x2)//функция которая печатает корни
{
    switch (count)
    {
    case 0:
        printf("Нет корней\n\n");
        break;
    case 1:
        printf("Уравнение имеет один корень:\n");
        printf("x = %.*f\n\n", ROOT_SING_COUNT, x1);
        break;
    case 2:
        printf("Уравнение имеет два корня:\n");
        printf("x1 = %.*f\n", ROOT_SING_COUNT, x1);
        printf("x2 = %.*f\n\n", ROOT_SING_COUNT, x2);
        break;
    case INF_ROOTS:
        printf("Любое число является решением\n\n");
        break;
    default:
        printf("Я не знаю как, но вы сломали программу");
        break;
    }
}

bool eqdoubles(double a, double b, double eps)//функция для сравнения даблов с заданной точностью
{
    return (fabs(a-b)<eps);
}

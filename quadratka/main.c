#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>

//��������� �������
void solve_equation(double a, double b, double c);

int main()
{
    double a_coef, b_coef, c_coef;

    printf("��� ������� ��������� ���� ax^2+bx+c=0 ������� ������������ a, b � c:\n");
    scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef);

    solve_equation(a_coef, b_coef, c_coef);

    return 0;
}

void solve_equation(double a, double b, double c)
{
     double D;

     D = b*b - 4*a*c;
     if (D<0)
     {
        printf("������������ ������ ����. ��� ������");
        return;
     }
     if (fabs(D)<0.0001)
     {
        double x = -b/(2*a);
        printf("������������ ����� ����. ��������� ����� ���� ������\n");
        printf("x = %.4f", x);
        return;
     }
     double x1, x2;
     x1 = (-b - sqrt(D))/2/a;
     x2 = (-b + sqrt(D))/2/a;
     printf("��������� ����� ��� �����:\n");
     printf("x1 = %.4f\n", x1);
     printf("x2 = %.4f\n", x2);
}

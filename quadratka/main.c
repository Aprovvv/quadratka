#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>

//��������� �������
void solve_equation(double a, double b, double c);//�������, ������� ������ ���������

int main()
{
    //���������� ����������
    double a_coef, b_coef, c_coef;

    printf("��� ������� ��������� ���� ax^2+bx+c=0 ������� ������������ a, b � c:\n");
    printf("��� ���������� ������� ����� ���������� ������\n");

    //���� ��������
    while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        solve_equation(a_coef, b_coef, c_coef);
        printf("��� ������� ��������� ���� ax^2+bx+c=0 ������� ������������ a, b � c:\n");
        printf("��� ���������� ������� ����� ���������� ������\n");
    }

    return 0;
}

void solve_equation(double a, double b, double c)//�������, ������� ������ ���������
{
    // ���������� ����������
     double D;

     D = b*b - 4*a*c;
     //������ ��� ������
     if (D<0)
     {
        printf("������������ ������ ����. ��� ������\n\n");
        return;
     }
     //������ ������� �������������
     if (fabs(a)<1e-7)
     {
        if (fabs(b)<1e-7)
        {
            if (fabs(c)<1e-7)
                printf("����� ����� �������� ��������\n\n");
            else
                printf("��� ������\n\n");
        }
        else
        {
            double x = -c/b;
            printf("��������� ����� ���� ������\n");
            printf("x = %.3g\n\n", x);
        }
        return;
     }
     //������ 1 ������
     if (sqrt(D)/a<0.001)//������������ �������� ����� ������� ������� 10^-3
     {
        double x = -b/(2*a);
        printf("������������ ����� ����. ��������� ����� ���� ������\n");
        printf("x = %.4g\n\n", x);
        return;
     }
     //������ 2 �����
     double x1, x2;
     x1 = (-b - sqrt(D))/2/a;
     x2 = (-b + sqrt(D))/2/a;
     printf("��������� ����� ��� �����:\n");
     printf("x1 = %.3g\n", x1);
     printf("x2 = %.3g\n\n", x2);
}

#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>

//��������� �������
void solve_equation(double a, double b, double c);//�������, ������� ������ ���������
void print_menu(void);

int main()
{
    //���������� ����������
    double a_coef=0, b_coef=0, c_coef=0;

    print_menu();

    //���� ��������
    while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        solve_equation(a_coef, b_coef, c_coef);
        print_menu();
    }

    return 0;
}

void solve_equation(double a, double b, double c)//�������, ������� ������ ���������
{
    // ���������� ����������
     double D = b*b - 4*a*c;

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
            printf("x = %.3f\n\n", x);
        }
        return;
     }
     //������ 1 ������
     if (sqrt(D)/a<0.001)//������������ �������� ����� ������� ������� 10^-3, �.�. ������� � ����� ���������
     {
        double x = -b/(2*a);
        printf("������������ ����� ����. ��������� ����� ���� ������\n");
        printf("x = %.3f\n\n", x);
        return;
     }
     //������ 2 �����
     double x1, x2;
     x1 = (-b - sqrt(D))/2/a;
     x2 = (-b + sqrt(D))/2/a;
     printf("��������� ����� ��� �����:\n");
     printf("x1 = %.3f\n", x1);
     printf("x2 = %.3f\n\n", x2);
}

void print_menu(void)
{
    printf("��� ������� ��������� ���� ax^2+bx+c=0 ������� ������������ a, b � c:\n");
    printf("��� ���������� ������� ����� ���������� ������\n");
}

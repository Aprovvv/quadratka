#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>

int solve_equation(double a, double b, double c, double *x1, double *x2);//�������, ������� ������ ��������� � ���������� ���������� ������ (3 = ����������)
void print_menu(void);//������� ������� ������ ����������� �� ����
void print_roots(int count, double x1_adress, double x2_adress);//������� ������� �������� �����

int main()//������� ������ ��� �������
{
    double a_coef=0, b_coef=0, c_coef=0;
    double x1 = 0, x2 = 0;
    int count = 0;

    print_menu();

    while(scanf("%lf %lf %lf", &a_coef, &b_coef, &c_coef) == 3)
    {
        count = solve_equation(a_coef, b_coef, c_coef, &x1, &x2);
        print_roots(count, x1, x2);
        print_menu();
    }

    return 0;
}

//�������, ������� ������ ��������� � ���������� ���������� ������ (3 = �������������).
//���������� ������������ �� ������� �1 � �2
//���� ������ 1, �� �� ������������ � �1
int solve_equation(double a, double b, double c, double *x1_adress, double *x2_adress)
{
     double D = b*b - 4*a*c;

     //������ ��� ������
     if (D<0)
        return 0;
     //������ ������� �������������
     if (fabs(a)<1e-7)
     {
        if (fabs(b)<1e-7)
        {
            if (fabs(c)<1e-7)
                return 3;
            else
                return 0;
        }
        else
        {
            *x1_adress = -c/b;
            return 1;
        }
     }
     //������ 1 ������
     if (sqrt(D)/a<0.001)//������������ �������� ����� ������� ������� 10^-3, �.�. ������� � ����� ���������
     {
        *x1_adress = -b/(2*a);
        return 1;
     }
     //������ 2 �����
     *x1_adress = (-b - sqrt(D))/2/a;
     *x2_adress = (-b + sqrt(D))/2/a;
     return 2;
}

void print_menu(void)//������� ������� ������ ����������� �� ����
{
    printf("��� ������� ��������� ���� ax^2+bx+c=0 ������� ������������ a, b � c:\n");
    printf("��� ���������� ������� ����� ���������� ������\n");
}

void print_roots(int count, double x1, double x2)//������� ������� �������� �����
{
    switch (count)
    {
    case 0:
        printf("��� ������\n\n");
        break;
    case 1:
        printf("��������� ����� ���� ������:\n");
        printf("x = %.3f\n\n", x1);
        break;
    case 2:
        printf("��������� ����� ��� �����:\n");
        printf("x1 = %.3f\n", x1);
        printf("x2 = %.3f\n\n", x2);
        break;
    case 3:
        printf("����� ����� �������� ��������\n\n");
        break;
    default:
        printf("� �� ���� ���, �� �� ������� ���������");
        break;
    }
}

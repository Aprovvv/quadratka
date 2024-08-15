#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

#define INF_ROOTS -1 //������������ �������� solve_equation, ���� ������ ���������� �����
#define ROOT_SING_COUNT 3 //����� ������ ����� ������� ��� ������ ������
#define EPS_COEF 1e-7 //�������� ����������� ������� �������������

int solve_equation(double a, double b, double c, double *x1, double *x2);//�������, ������� ������ ��������� � ���������� ���������� ������
void print_menu(void);//������� ������� ������ ����������� �� ����
void print_roots(int count, double x1, double x2);//������� ������� �������� �����
bool eqdoubles(double a, double b, double eps);//������� ��� ��������� ������ � �������� ���������

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

//�������, ������� ������ ��������� � ���������� ���������� ������
//���������� ������������ �� ������� �1 � �2
//���� ������ 1, �� �� ������������ � �1
int solve_equation(double a, double b, double c, double *x1_adress, double *x2_adress)
{
     double D = b*b - 4*a*c;
     double sqrtD = sqrt(D);

     //������ ��� ������
     if (D<0)
        return 0;
     //������ ������� �������������
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
     //������ 1 ������
     if (eqdoubles(sqrtD/a, 0, pow(10, -ROOT_SING_COUNT)))//������������ �������� ����� ������� ������� 10^-ROOT_SING_COUNT, �.�. ������� � ����� ���������
     {
        *x1_adress = -b/(2*a);
        return 1;
     }
     //������ 2 �����
     *x1_adress = (-b - sqrtD)/2/a;
     *x2_adress = (-b + sqrtD)/2/a;
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
        printf("x = %.*f\n\n", ROOT_SING_COUNT, x1);
        break;
    case 2:
        printf("��������� ����� ��� �����:\n");
        printf("x1 = %.*f\n", ROOT_SING_COUNT, x1);
        printf("x2 = %.*f\n\n", ROOT_SING_COUNT, x2);
        break;
    case INF_ROOTS:
        printf("����� ����� �������� ��������\n\n");
        break;
    default:
        printf("� �� ���� ���, �� �� ������� ���������");
        break;
    }
}

bool eqdoubles(double a, double b, double eps)//������� ��� ��������� ������ � �������� ���������
{
    return (fabs(a-b)<eps);
}

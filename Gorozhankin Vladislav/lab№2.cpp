/*var.12(Треугольник. Разработать программу, меню которой позволяет
выполнить следующие функции:
1. Ввод координат вершин треугольника.
2. Определить вид треугольника (правильный, прямоугольный,
равнобедренный, произвольного вида).
3. Вывод периметра треугольника.
4. Вывод площади треугольника.
5. Вычислить и вывести радиусы вписанной и описанной вокруг
треугольника окружностей.
6. Информация о версии и авторе программы.
7. Выход из программы.)*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string.h>

using namespace std;

void ENTER(double& a, double& b, double& c)
{
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    double x3 = 0;
    double y3 = 0;
    printf("Enter x1: \n" ) ;
    scanf("%lf", &x1);
    printf( "Enter y1: \n") ;
    scanf("%lf", &y1);
    printf( "Enter x2: \n") ;
    scanf("%lf", &x2);
    printf("Enter y2: \n");
    scanf("%lf", &y2);
    printf("Enter x3: \n");
    scanf("%lf", &x3);
    printf("Enter y3: \n");
    scanf("%lf", &y3);
    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    printf("%lf\n", a);
    printf("%lf\n", b);
    printf("%lf\n", c);
    printf("\n");
}

void  DEFINE(double& a, double& b, double& c)
{
    if (abs(a - b) < 0.000001 && abs(b - c) < 0.000001 && abs(a - c) < 0.000001) 
    { 
        printf( "The triangle is equilateral\n"); 
    }
    else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2))
    {
        if (a == b || b == c || a == c) 
        { 
            printf( "The triangle is isosceles and rectangular\n"); 
        }
        else 
        {
            printf( "The triangle is rectangular\n") ;
        }
    }
    else if (a == b || b == c || a == c) 
    { 
        printf("The triangle is isosceles\n" ); 
    }
    else 
    { 
        printf( "The triangle is of undefined kind\n"); 
    }
    printf("\n");
}

void PERIMETER(double& a, double& b, double& c, double& P)
{
    P = a + b + c;
    printf("The perimeter of the triangle is: %lf\n", P);
    printf("\n");
}

void SQUARE(double& a, double& b, double& c, double& S)
{
    double cos_alpha = 0;
    cos_alpha = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * b * c);
    S = 0.5 * b * c * sqrt(1 - pow(cos_alpha, 2));
    printf("The square of the triangle is: %lf\n", S);
    printf("\n");
}

void  RADIUS(double& a, double& b, double& c, double& S, double& P)
{
    double r_in = 0;
    double R_out = 0;
    r_in = 2 * S / P;
    R_out = a * b * c / (4 * S);
    printf("The radius of inside circle is: %lf\n", r_in);
    printf("The radius of outside circle is: %lf\n", R_out);
    printf("\n");
}

void info()
{
    printf("The author of the program is Vladislav Gorozhankin\n");
    printf("Microsoft Visual Studio 2021\n");
    printf("\n");
}

void print_menu()
{
    printf("1-enter coordinates\n");
    printf("2-define the kind of triangle\n");
    printf("3-count perimeter\n");
    printf("4-count square\n");
    printf("5-count the radius of inside and outside circle\n");
    printf("6-information about the version and author of the program\n");
    printf("7-exit\n");
}

int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}


int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double P = 0;
    double S = 0;
    int variant;

    do {
        print_menu();

        variant = get_variant(7); 

        switch (variant) {
        case 1:
            ENTER(a, b, c);
            break;

        case 2:
            DEFINE(a, b, c);
            break;

        case 3:
            PERIMETER(a, b, c, P);
            break;

        case 4:
            SQUARE(a, b, c, S);
            break;

        case 5:
            RADIUS(a, b, c, S, P);
            break;
        case 6:
            info();
            break;
        }
        if (variant != 7)
        system("pause"); 
    } while (variant != 7);
}
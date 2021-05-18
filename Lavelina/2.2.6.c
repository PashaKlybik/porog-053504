/*Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х. */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

long int factorial(long int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int Teylor(float x, double e)
{
    double rez = x;
    int n = 2.;
    while(fabs(sin(x) - rez) >= e)
    {
        rez += pow(-1, n - 1) * pow(x, 2 * n - 1) / factorial(2 * n - 1);
        n++;
    }
    printf("\nIteration: %lf, sin(x) = %lf", rez, sin(x));
    return n - 1;
}

int Recursion(float x, int n, double e, double rez)
{
    double rezend = rez;
        
        if (fabs(sin(x) - rezend) < e) 
        {
            printf("\nRecursion: %lf, sin(x) = %lf", rezend, sin(x));
            return n;
        }
        n++;
        rezend += (pow(-1, n - 1) * pow(x, 2 * n - 1)) / factorial(2 * n - 1);

    return Recursion(x, n, e, rezend);
}

int main()
{
    
    double x, e;
    printf("Enter x:\nx = ");
    scanf_s("%lf.20", &x);
    printf("Enter e:\ne = ");
    scanf_s("%lf", &e);
    printf("n = %d", Recursion(x, 1, e, x));
    printf("n = %d", Teylor(x, e));

    return 0;
}
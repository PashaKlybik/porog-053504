/*Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х. */

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.1415926535

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int IterationTeylor(float x, double e)
{
    double rez = 0;
    int n = 1;
    do
    {
        rez += pow(-1, n - 1) * pow(x, 2 * n - 1) / factorial(2 * n - 1);
        n++;
    } while (fabs(rez-sin(x))>e);
        
    printf("\nIteration: %lf, sin(x) = %lf", rez, sin(x));
    return --n;
}

int RecursionTeylor(float x, int n, double e, double rez)
{
    double rezend = rez;
        
        if (fabs(sin(x) - rezend) < e) 
        {
            printf("\nRecursion: %lf, sin(x) = %lf", rezend, sin(x));
            return n;
        }
        n++;
        rezend += (pow(-1, n - 1) * pow(x, 2 * n - 1)) / factorial(2 * n - 1);

    return RecursionTeylor(x, n, e, rezend);
}

float Calc(long float x)
{
    long float degree;
    degree = (x * 180) / PI;
    if (x > 0)
    {
        while (degree > 0)
        {
            degree -= 360;
        }
        degree += 360;
    }
    else
    {
        while (degree < 0)
        {
            degree += 360;
        }
        degree -= 360;
    }
    double result;
    result = (PI * degree) / 180;
    return result;
}

int main()
{
    
    double x, e, rightX;
   
    printf("Enter x:\nx = ");
    scanf_s("%lf.20", &x);
    printf("Enter e:\ne = ");
    scanf_s("%lf", &e);

    rightX = Calc(x);
    printf(" n = %d", RecursionTeylor(rightX, 1, e, rightX));
    printf(" n = %d", IterationTeylor(rightX, e));

    return 0;
}
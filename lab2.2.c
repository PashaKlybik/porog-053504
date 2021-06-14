// 2.2(6).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<math.h>

int Find_n(double x, double e);
long double fact(int n);

int main()
{
    float x, e;

    printf("Enter x: ");
    scanf_s("%f", &x);
    printf("Enter e: ");
    scanf_s("%f", &e);

    printf("%d", Find_n(x, e));

}

long double fact(int n) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int Find_n(double x, double e) {

    long double ans = 0;
    
    int a, b, n = 0;

    for (int i = 1; fabs(sin(x) - ans) > e; i++) {
        a = i - 1;
        b = 2 * i - 1;
        ans += pow(-1, a) * pow(x, b) / fact(2 * i - 1);
        n = i;
    }
    return n;
}
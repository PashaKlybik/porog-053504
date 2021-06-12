#include <stdio.h>
#include <math.h>

int main()
{
    double x = 0, element, sum = 0, d = 0;
    int i = 1;
    printf("Enter x and d: \n");
    scanf_s("%lf", &x);
    scanf_s("%lf", &d);
    double si = sin(x), rs = 1 + d;
    element = x;
    for (i = 1; rs > d; i++)
    {
        sum += element;
        element *= (-1) * x * x / (2 * i) / (2 * i + 1);
        rs = fabs(si - sum);
    }
    printf("x = %lf\n", x);
    printf("sin(%lf) = ", x);
    printf("%lf\n", sum);
    int n = i;
    printf("%d", n);
    return 0;
}
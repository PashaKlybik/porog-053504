#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


unsigned long long fact(unsigned long long n)
{
    unsigned long long res = 1;
    while (n > 1)
    {
        res *= n--;
    }
    return res;
}

long double recursivesin(long double x, long double currentPrecision, long double precision, unsigned long long *n)
{
    long double res = (powl(-1, (*n) - 1) * powl(x, 2 * (*n) - 1) / fact(2 * (*n) - 1));
    currentPrecision -= res;
    if (fabs(currentPrecision) <= precision)
        return res;
    (*n)++;
    return (res + recursivesin(x, currentPrecision, precision, n));
}

long double itersin(long double x, long double precision, unsigned long long *n)
{
    long double res = 0, tmp, original = sinl(x);

    while (1) {
        tmp = powl(-1, (*n) - 1) * powl(x, 2 * (*n) - 1) / fact(2 * (*n) - 1);
        res += tmp;
        if (fabs(res - original) <= precision)
            break;
        (*n)++;
    }
    return res;
}

int main()
{
    char choice = 'y';
    long double x, precision, rec_res, iter_res;
    unsigned long long counter;

    while (choice == 'y')
    {
        printf("Enter X(radians): ");
        scanf(" %lf", &x);

        printf("Enter precision: ");
        scanf(" %lf", &precision);

        counter = 1;

        iter_res = itersin(x, precision, &counter);

        printf("Iterational result: %.10lf\n", iter_res);
        printf("Count of iterations: %d\n\n", counter);

        counter = 1;
        if (precision < 0.00000001)
        {
            printf("Too small precision. Too many recursive calls\n\n");
        }
        else
        {
            rec_res = recursivesin(x, sinf(x), precision, &counter);

            printf("Recursive result: %.10lf\n ", rec_res);
            printf("Count of function calls: %llu\n\n", counter);
        }

        printf("Do you want to continue?(Y/n)\n");
        scanf("\n%c", &choice);
    }
    return 0;
}

#include <stdio.h>
# include <math.h>


int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int rec(float x, float precis)
{
    int counter =0;
    float recs=0, orig=sinf(x);
    do
    {
        counter++;
        recs+=pow(-1,counter-1)*pow(x, 2*counter-1)/fact(2*counter-1);
    }
    while (orig-precis>recs || orig+precis<recs);
    printf_s("Original sin(x): %lf\nTaylor's formula: %lf\n ", orig, recs);

    return counter;
}

int main()
{
    _Bool run = 1;
    float precision = 0;
    int x=20, finish=0, coef=1, numb=0;
    float radx = 0;

    while(run)
    {
        printf_s("Set X:");
        scanf_s("%d", &x);

        if( x > 180 )
        {
            coef=(int)(x/180);
            x-=(180*coef);
        }

        printf_s("Set precision: ");
        scanf_s("%f",&precision);

        radx=(float)x/180*3.14;
        numb = rec(radx, precision);

        printf_s("Number of calculations: %d\n\n", numb);

        printf_s("Continue ?\n Y(1)/N(0)->");
        scanf_s("%d\n\n", &finish);

        if(finish==0)
        {
            run = 0;
        }
    }
    printf("Thank you!");
    return 0;
}

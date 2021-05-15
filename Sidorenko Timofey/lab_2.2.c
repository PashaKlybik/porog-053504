#include <stdio.h>
#include <math.h>


int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

float rec(float x, float precis, float orig, int* n)
{
    float recs = (float)(pow(-1,*n-1)*pow(x, 2*(*n)-1)/fact(2*(*n)-1));
    if( fabs(recs) <= precis )
    {
        (*n)--;
        return 0;
    }
    (*n)++;
    return (recs + rec(x, precis, orig, n));
}

int iter(float x, float precis)
{
    int counter =0;
    float recs=0, orig=sinf(x);

    do
    {
        counter++;
        recs+=pow(-1,counter-1)*pow(x, 2*counter-1)/fact(2*counter-1);
    }
    while (orig-precis>recs || orig+precis<recs);

    printf_s("Original sin(x): %lf\n\nIteration way: %lf\n ", orig, recs);
    return counter;
}

int main()
{
    _Bool run = 1;
    float precision = 0;
    int x=20, finish=0, coef=1, numb=0, counter=1;
    float radx = 0, original=0, newsin=0;

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
        scanf_s(" %f",&precision);

        radx=(float)x/180*3.14;
        original = sinf(radx );
        numb = iter(radx, precision);

        printf_s("Number of calculations 1: %d\n\n", numb);

        newsin = rec(radx, precision, original, &counter);
        printf_s("Recursion way: %lf\n ", newsin);

        printf_s("Number of calculations 2: %d\n\n", counter);
        printf_s("Continue ?\n Y(1)/N(0)-> ");
        scanf_s(" %d", &finish);

        if(finish == 0)
        {
            run = 0;
        }
    }
    return 0;
}
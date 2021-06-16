
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define Pi 3.14159265

unsigned long long fact(int n)
{
    if(n < 2)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    float x, e, exp = 0;
    int n = 1, i = 0;
    bool checked = false, converge = true;
    while (!checked)
    {
        printf("\n\n\nDo you want to enter the angle x in degrees?\n 1 - Yes.\n 2 - No.\n");
        switch (getch())
        {
        case '1':
        {
            printf("\nEnter x: ");
            scanf("%f", &x);
            x = x * (2 * Pi) / 360 ;
            checked = true;
            break;
        }
        case '2':
        {
            printf("\n\nEnter x: ");
            scanf("%f", &x);
            checked = true;
            break;
        }
        default:
        {
            break;
        }
        }
    }
    printf("Enter epsilon(e): ");
    scanf("%f", &e);
    while(x > 2 * Pi)
    {
        x -= 2 * Pi;
    }
    printf("\nx = %f", x);
    double curdiff = fabs(exp - sin(x)), diff = 1000;
    while(true)
    {
        exp += pow(-1, (n - 1)) * pow(x, 2 * n - 1) / fact(2 * n - 1);
        printf("\n%d)\nsin(x) = %f\nexpression = %f\n|exp - sin(x)| = %f\n", n, sin(x), exp, fabs(exp - sin(x)));
        if(fabs(exp - sin(x)) < e)
        {
            break;
        }
        if(fabs(exp - sin(x)) == e)
        {
            break;
        }
        n++;
    }
    printf ("\n\n%d - is the needed n\n", n);
    printf("The Razlozhenie is shodyasheese");
    return 0;
}
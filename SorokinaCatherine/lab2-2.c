#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653

int fact(int num){
    if (num<0)
        return 0;
    if (num==0)
        return 1;
    else
        return num * fact(num-1);
}

int taylor_iter(float x, double e, int minus){
    double result = x;
    int n = 2;
    while (fabs(sinf(x) - result) >= e){
        result+= pow(-1,n-1)*pow(x,2*n-1)/fact(2*n-1);
        n++;
    }
    if (minus==1)
        printf("\nЧерез ряд Тейлора итерационно: %lf", -result);
    else
        printf("\nЧерез ряд Тейлора итерационно: %lf", result);
    return n-1;
}

int taylor_rec(float x, int n, double e, double res, int minus){
    double result = res;

    if (fabs(sinf(x) - result) < e){
        if (minus==1)
            printf("\nЧерез ряд Тейлора рекурсивно: %lf", -result);
        else
            printf("\nЧерез ряд Тейлора рекурсивно: %lf", result);
        return n;
    }
    n++;

    result += (pow(-1,n-1)*pow(x,2*n-1))/fact(2*n-1);
    return taylor_rec(x, n, e, result, minus);

}

int main() {
    setlocale(LC_ALL,"Rus");

    int n, z;
    float x, var=0;
    double e;


    while(var!=1){
        printf("Введите х: ");
        var=scanf("%f",&x);
        if(var!=1)
            fflush(stdin);
    }
    var = 0;
    while(var!=1){
        printf("Введите погрешность: ");
        var=scanf("%lf", &e);
        if(var!=1)
            fflush(stdin);
    }

    z=x/(2*PI);
    if(abs(z)>=1){
        x = x - ((z)*2*PI);
    }
    if (x<=PI) {
        z=0;
    }
    else if(x>PI &&x<2*PI){
        x-=PI;
        z=1;
    }

    printf("sin(x) = %lf", sinf(x));
    n = taylor_iter(x, e, z);
    printf("\nn при итерационном методе: %d", n);
    n = taylor_rec(x, 1, e, x, z);
    printf("\nn при рекурсивном методе: %d", n);
    return 0;
}

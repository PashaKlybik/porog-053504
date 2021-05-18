#include <stdio.h>
#include <locale.h>
#include <math.h>

int fact(int num){
    if (num<0)
        return 0;
    if (num==0)
        return 1;
    else
        return num * fact(num-1);
}

int taylor_iter(float x, double e){
    double result = x;
    int n = 2;
    while (fabs(sinf(x) - result) >= e){
        result+= pow(-1,n-1)*pow(x,2*n-1)/fact(2*n-1);
        n++;
    }
    printf("\nЧерез ряд Тейлора итерационно: %lf", result);
    return n-1;
}

int taylor_rec(float x, int n, double e, double res){
    double result = res;

    if (fabs(sinf(x) - result) < e){
        printf("\nЧерез ряд Тейлора рекурсивно: %lf", result);
        return n;
    }
    n++;

    result += (pow(-1,n-1)*pow(x,2*n-1))/fact(2*n-1);
    return taylor_rec(x, n, e, result);

}

int main() {
    setlocale(LC_ALL,"Rus");

    int n;
    float x;
    double e;

    printf("Введите х: ");
    scanf("%f",&x);
    if (x<=1 && x>=-1) {
        printf("Введите погрешность: ");
        scanf("%lf", &e);

        printf("sin(x) = %lf", sinf(x));
        n = taylor_iter(x, e);
        printf("\nn при итерационном методе: %d", n);
        n = taylor_rec(x, 1, e, x);
        printf("\nn при рекурсивном методе: %d", n);
    } else
        printf("Вы ввели неверный х");
    return 0;
}

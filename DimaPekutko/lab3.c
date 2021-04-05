#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calculateGauss(int m, int n, double *a) {
    int i, j, k, maxElStringIndex;
    double maxElement;

    i = 0; j = 0;
    while (i < m && j < n) {
        maxElement = 0.0;
        for (k = i; k < m; k++) {
            if (fabs(a[k*n + j]) > maxElement) {
                maxElStringIndex = k;
                maxElement = fabs(a[k*n + j]);
            }
        }
        if (maxElement <= 0.001) {
            for (k = i; k < m; k++) {
                a[k*n + j] = 0.0;
            }
            j++;
            continue;
        }

        if (maxElStringIndex != i) {
            // Меняем местами i-ю и l-ю строки
            for (k = j; k < n; k++) {
                maxElement = a[i*n + k];
                a[i*n + k] = a[maxElStringIndex*n + k];
                a[maxElStringIndex*n + k] = (-maxElement); // Меняем знак строки
            }
        }

        // Утверждение: fabs(a[i*n + k]) > eps

        // Обнуляем j-й столбец, начиная со строки i+1,
        // применяя элем. преобразования второго рода
        for (k = i+1; k < m; k++) {
            maxElement = (-a[k*n + j] / a[i*n + j]);

            // К k-й строке прибавляем i-ю, умноженную на r
            a[k*n + j] = 0.0;
            for (maxElStringIndex = j+1; maxElStringIndex < n; maxElStringIndex++) {
                a[k*n+maxElStringIndex] += maxElement*a[i*n+maxElStringIndex];
            }
        }

        i++; j++;   // Переходим к следующему минору
    }

    return i;
}

int main() {
    int m, n, i, j, rang;
    double *a;

    printf("Type matrix string and raws count: ");
    scanf("%d%d", &m, &n);

    a = (double*)malloc(m*n*sizeof(double));

    printf("Type matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &(a[i*n + j]));
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%5.5lf ", a[i*n + j]);
        }
        printf("\n");
    }

    rang = calculateGauss(m, n, a);

    printf("Result matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%5.5lf ", a[i*n + j]);
        }
        printf("\n");
    }

    printf("Rang(a)=%d\n", rang);

    free(a);
    return 0;
}


// гр.053504 Щегловская Мария Ранг матрицы. Найти ранг прямоугольной матрицы a(m, n) методом Гаусса.  
#include <stdio.h>  
#include <math.h>   
#include <stdlib.h> 
int gaussMethod(int m,int n,double* a, double eps)
{
    int i, j, k, l;
    double r;

    i = 0; j = 0;
    while (i < m && j < n) {
    
        r = 0.0;
        for (k = i; k < m; ++k) {
            if (fabs(a[k * n + j]) > r) {
                l = k;   
                r = fabs(a[k * n + j]); 
            }
        }
        if (r <= eps) {
            
            for (k = i; k < m; ++k) {
                a[k * n + j] = 0.0;
            }
            ++j;      
            continue; 
        }

        if (l != i) {
           
            for (k = j; k < n; ++k) {
                r = a[i * n + k];
                a[i * n + k] = a[l * n + k];
                a[l * n + k] = (-r);
            }
        }


       
        for (k = i + 1; k < m; ++k) {
            r = (-a[k * n + j] / a[i * n + j]);

            a[k * n + j] = 0.0;
            for (l = j + 1; l < n; ++l) {
                a[k * n + l] += r * a[i * n + l];
            }
        }

        ++i; ++j;   
    }

    return i; 
}

int main() {
    int m, n, i, j, rank;
    double* a;
    double eps, det;

    printf("Vvedite element mtr");
    scanf_s("%d%d", &m, &n);


    a = (double*)malloc(m * n * sizeof(double));

    printf("Elem:\n");
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
          
            scanf_s("%lf", &(a[i * n + j]));
        }
    }

    printf("Tochnost: ");
    scanf_s("%lf", &eps);


    rank = gaussMethod(m, n, a, eps);


    printf("Stupenchatyi vid :\n");
    for (i = 0; i < m; ++i) {
       
        for (j = 0; j < n; ++j) {
            printf(         
                "%10.3lf ", 
                a[i * n + j]  
            );
        }
        printf("\n");  
    }

    printf("Rang = %d\n", rank);

    if (m == n) {
      
        det = 1.0;
        for (i = 0; i < m; ++i) {
            det *= a[i * n + i];
        }
        printf("Opredelitel = %.3lf\n", det);
    }

    free(a); 
    return 0;   
}


	







#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <mm_malloc.h>

void fill_SLAY(double *brray, double **array, int size);
void output_SLAY(double *brray, double **array, int size);
void gauss(double *xrray, double *brray, double **array, int size);


int main() {
    setlocale(LC_ALL,"Rus");

    int size;
    double **arr;
    double *brr;
    double *xrr;
    printf("Введите размер n квадратной матрицы значений a: ");
    scanf ("%d", &size);
    arr = (double **) malloc(size * sizeof(double));
    brr = (double *) malloc(size* sizeof(double));
    xrr = (double *) malloc(size* sizeof(double));
    fill_SLAY(brr, arr, size);
    output_SLAY(brr, arr, size);
    gauss(xrr, brr, arr, size);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
    free(brr);
    free(xrr);
    return 0;
}


void fill_SLAY(double *brray, double **array, int size) {
    printf("Заполните квадратную матрицу значений a: \n");
    for (int i = 0; i < size; i++) {
        array[i] = (double *) malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            printf("a[%d][%d] = ", (i+1), (j+1));
            scanf("%lf", &array[i][j]);
        }
    }
    printf("Заполните матрицу свободных членов b: \n");
    for (int i = 0; i < size; i++) {
        printf("b[%d] = ", i+1);
        scanf("%lf", &brray[i]);
    }
}

void output_SLAY(double *brray, double **array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%5.3lf", array[i][j]);
            printf("\t");
        }
        printf("\t| %5.3lf", brray[i]);
        printf("\n");
    }
}
//сделать так, чтобы уравнение 1 не рассматривалось после первого этапа и тд
void gauss(double *xrray, double *brray, double **array, int size) {
    double a_max, temp;
    const double e = 0.00001;
    int number;
    for (int j = 0; j < size; j++) {
        a_max = fabs(array[j][j]);
        number = j;
        //ищем максимальный элемент в первом столбце
        for (int i = j; i < size; i++) {
            if (fabs(array[i][j]) > a_max){
                number = i;
                a_max = fabs(array[i][j]);
            }
        }
        if (a_max < e){
            printf("Невозможно решить данную матрицу");
            return;
        }
        //меняем строки
        if (number!=0){
            for (int l = 0; l < size; l++) {
                temp=array[j][l];
                array[j][l]=array[number][l];
                array[number][l]=temp;
            }
        }
        temp = brray[j];
        brray[j]=brray[number];
        brray[number]=temp;

        for (int i = j; i < size; i++) {
            temp = array[i][j];

            if (fabs(temp) < e) continue; //с нулевым коэффициентом не делаем ничего

            for (int k = 0; k < size; k++) {
                array[i][k]=array[i][k]/temp;
            }
            brray[i]=brray[i]/temp;

            if (i == j) continue;

            for (int k = 0; k < size; ++k) {
                array[i][k]=array[i][k]-array[j][k];
            }
            brray[i]=brray[i]-brray[j];
        }
    }

    for (int k = size - 1; k >= 0; k--) {
        xrray[k] = brray[k];
        for (int i = 0; i <k; i++) {
            brray[i] = brray[i] - (array[i][k] * xrray[k]);
        }
    }

    printf("\n X = ");
    for (int i = 0; i < size; i++) {
        printf("%5.3lf ", xrray[i]);
    }
}




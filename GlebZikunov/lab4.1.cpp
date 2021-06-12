#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

// ввод массива матриц
void enterMatrices(char*** matrices, int n, int rows, int columns) {
    char letters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < columns; k++)
            {
                int f = rand() % 25;
                matrices[i][j][k] = letters[f];
            }
            matrices[i][j][columns] = '\0';
        }
    }
}

// подсчет суммы аски кодов строки
int countASCII(char* string) 
{
    int ascii_sum = 0;
    for (int i = 0; string[i] != '\0'; i++) 
    {
        ascii_sum += string[i];
    }
    return ascii_sum;
}

// вывод матрицы
void showMatrix(char** matrix, int rows)
{
    for (int i = 0; i < rows; i++, putchar('\n'))
    {
        printf("%20s (%d)", matrix[i], countASCII(matrix[i]));
    }
}

// вывод всех матриц
void showMatrices(char*** matrices, int n, int rows)
{
    for (int i = 0; i < n; i++) 
    {
        printf("Matrix %d:\n", i + 1);
        showMatrix(matrices[i], rows);
        putchar('\n');
    }
}

// реверс строки (зеркальное отражение)
void reverse(char* string) 
{
    int lenght = strlen(string);
    for (int i = 0; i < lenght / 2; i++) 
    {
        char tmp = string[i];
        string[i] = string[lenght - i - 1];
        string[lenght - i - 1] = tmp;
    }
}

// функция реверса нужных строк в матрице
void reverseStrings(char** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int ascii_sum = countASCII(matrix[i]);
        if (ascii_sum % 2 == 0)
        { // если сумма кодов четная
            reverse(matrix[i]); // то происходит реверс
        }
    }
}

//проход по всем матрицами с функцией реверса
void reverseAllMatrices(char*** matrices, int n, int rows)
{
    for (int i = 0; i < n; i++) 
    {
        reverseStrings(matrices[i], rows);
    }
}

void freeMatrix(char** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void printLine() {
    for (int i = 0; i < 120; i++)
        printf("_");
    putchar('\n');
}

int main() {

   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

    char*** matrices;
    int n, rows, columns;

    printf("Enter number of matrices: ");
    scanf_s("%d", &n);
    printf("Enter number of rows in each matrix: ");
    scanf_s("%d", &rows);
    printf("Enter number of columns in each matrix: ");
    scanf_s("%d", &columns);

    matrices = (char***)malloc(n * rows * columns * sizeof(char));
    for (int i = 0; i < n; i++) {
        matrices[i] = (char**)malloc(rows * columns * sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rows; j++) {
            matrices[i][j] = (char*)malloc(columns * sizeof(char));
        }
    }

    enterMatrices(matrices, n, rows, columns);
    system("cls");
    printLine();
    printf("Before reverse:\n");
    printLine();
    showMatrices(matrices, n, rows);
    reverseAllMatrices(matrices, n, rows);
    printLine();
    printf("After reverse:\n");
    printLine();
    showMatrices(matrices, n, rows);
    printLine();
}
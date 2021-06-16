#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include <time.h>

#pragma warning(disable: 4996)

int compare_greater(int a, int b) 
{
    return a > b;
}

int compare_less(int a, int b)
{
    return a < b;
}

// функция которая заполняет строку рандомными буквами
char* randStringWithLetters() 
{
    int i = 0;
    char* str = (char*)malloc(32);
    srand(time(NULL));
    char letters[] = { " ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    for (i = 0; i < 32; i++) 
    {
        int j = rand() % 26;
        str[i] = letters[j];
    }
    str[i] = '\0';
    return str;
}

// функция которая заполняет строку рандомными символами-числами
char* randStringWithDigits()
{
    int i = 0;
    char* str = (char*)malloc(8);
    srand(time(NULL));
    char digits[] = { "123456789" };
    for (i = 0; i < 9; i++) 
    {
        int j = rand() % 10;
        str[i] = digits[j];
    }
    str[i] = '\0';
    return str;
}

// ввод файла
void enterFile(const char* filename, int numberOfLines)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        exit(-101);
    }
    // задается определенное кол-во строк (numberOfLines)
    for (int i = 0; i < numberOfLines; i++) 
    {   // через цикл записываем в файл
        fprintf(file, "%s", randStringWithLetters());   // 32 байта букв
        fprintf(file, "%d\n", randStringWithDigits());  // остальные 8 - на рандомное число
    }
    fclose(file);
}

// функция для просмотра файла
void showFile(const char* filename)
{
    char buffer[41];
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(-101);
    }
    while (fgets(buffer, 41, file) != NULL) 
    {
        printf("%s", buffer);
    }
    fclose(file);
}

// перевод части строки в int (для сортировки)
int convertToInt(char* string)
{
    int n = 0;
    for (int i = 0; string[i] != 0; i++) 
    {
        if (isdigit(string[i])) 
        {
            for (n = 0; isdigit(string[i]); i++)
                n = 10 * n + (string[i] - '0');
            return n;
        }
    }
}

// функция свапа строк в массиве
void swapStrings(char** str1, char** str2)
{
    char* tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

// считывание файла в массив
void readFileIntoArray(const char* filename, char** array, int lines)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        exit(-101);
    }
    rewind(file);
    for (int i = 0; i < lines; i++)
    {
        fread(array[i], sizeof(char), 41, file);
        array[i][40] = '\0';
    }
    fclose(file);
}

// запись массива в файл
void writeArrayIntoFile(const char* filename, char** array, int lines) 
{
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < lines; i++)
        fprintf(file, "%s\n", array[i]);
    fclose(file);
}

// сортировка 
void readAndSort(const char* filename, int lines, int (*compare)(int, int))
{

    char** fileContent = (char**)malloc(lines * 41 * sizeof(char));

    for (int i = 0; i < lines; i++)
        fileContent[i] = (char*)malloc(41 * sizeof(char));

    readFileIntoArray(filename, fileContent, lines);    // считываем файл в массив

    // сортируем массив
    for (int i = 0; i < lines - 1; i++) 
    {

        for (int j = 0; j < lines - i - 1; j++) 
        {

            int firstValue = convertToInt(fileContent[j]);
            int secondValue = convertToInt(fileContent[j + 1]);

            if (compare(firstValue, secondValue)) 
            {
                swapStrings(&fileContent[j], &fileContent[j + 1]);
            }
        }
    }
    // записываем его обратно в файл
    writeArrayIntoFile(filename, fileContent, lines);
}

void printLine() 
{
    for (int i = 0; i < 40; i++)
        printf("_");
    putchar('\n');
}

int main() 
{
    srand(time(NULL));
    int lines = 0;
    char filename[30];
    printf("Enter number of lines, which will be written into file: ");
    scanf_s("%d", &lines);
    printf("Enter name of file: ");
    rewind(stdin);
    gets_s(filename);;
    enterFile(filename, lines);
    printLine();
    printf("File content before sort: \n");
    printLine();
    showFile(filename);
    printLine();
    readAndSort(filename, lines, compare_less);
    printf("File content after sort: \n");
    printLine();
    showFile(filename);
    printLine();
}
//вариант 13
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <locale.h>

int main(void)                 
{                               
    char* locale = setlocale(LC_ALL, "");
   
    int numb;
    printf("Введите натуральное целое число, не  превосходящее 100 \n");
    scanf_s("%d", &numb);
    
    int ost = numb % 10;
    int dec = numb / 10;
    printf("Введенное число: %d, его запись прописью -  ", numb);

    if (numb > 9 && numb < 20)
    {
        switch (numb)
        {
            case 10: printf("Десять\n"); break;
            case 11: printf("Одиннадцать\n"); break;
            case 12: printf("Двенадцать\n"); break;
            case 13: printf("Тринадцать\n"); break;
            case 14: printf("Четырнадцать\n"); break;
            case 15: printf("Пятнадцать\n"); break;
            case 16: printf("Шестнадцать\n"); break;
            case 17: printf("Семнадцать\n"); break;
            case 18: printf("Восемнадцать\n"); break;
            case 19: printf("Девятнадцать\n"); break;
             default:;
        }
    }
    switch (dec)
    {
        
        case 2: printf("Двадцать "); break;
        case 3: printf("Тридцать "); break;
        case 4: printf("Сорок "); break;
        case 5: printf("Пятьдесят "); break;
        case 6: printf("Шестьдесят "); break;
        case 7: printf("Семьдесят "); break;
        case 8: printf("Восемьдесят "); break;
        case 9: printf("Девяносто "); break;
        case 10: printf("Сто\n"); break;
         default:;
    }
    switch (ost)
    {

        case 1: printf("Один\n"); break;
        case 2: printf("Два\n"); break;
        case 3: printf("Три\n"); break;
        case 4: printf("Четыре\n"); break;
        case 5: printf("Пять\n"); break;
        case 6: printf("Шесть\n"); break;
        case 7: printf("Семь\n"); break;
        case 8: printf("Восемь\n"); break;
        case 9: printf("Девять\n"); break;
         default:;
    }
    return 0;                   
}
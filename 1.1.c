// 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#pragma warning(disable : 4996)

void int_to_Arr(int number, int n, int*& arr);
void Check(int*& arr, int n, int count);
char* FindFac(int* arr);
int FindYear(int* arr, int year);

int main(void)
{
    int number, n=6;//n - к-во цифр в номере
    int year, ansYear;
    char *ansFac = (char*)malloc(7 * sizeof(char*));

    printf("Enter number: ");
    scanf_s("%d", &number);
    printf("Enter year: ");
    scanf_s("%d", &year);
    int* arr = (int*)malloc(n * sizeof(int*));
    
    int_to_Arr(number, n, arr);
    ansFac = FindFac(arr);
    ansYear = FindYear(arr, year);

    if (strcmp(ansFac, "1") == 0 || ansYear == 1) {
        printf("\nERROR.");
        exit(1);
    }

    printf("\nFaculty - %s;\nYear - %d", ansFac, ansYear);
}

void int_to_Arr(int number, int n, int*& arr){
    int count = 0;

    while (number != 0) {
        arr[n-1-count] = number % 10;
        number /= 10;
        count++;
    }

    Check(arr, n, count);
    
}

void Check(int*& arr, int n, int count) {
    if (count > n) {
        printf("\nERROR.");
        exit(1);
    }
    else if(count < n)
        while (count < n) {
            arr[n - 1 - count] = 0;
            count++;
        }
}

char* FindFac(int* arr) {
    char* fac = (char*)malloc(7 * sizeof(char*));
    switch (arr[1]){
    case 1:strcpy(fac,"FKP."); break;
    case 2:strcpy(fac, "FITU."); break;
    case 4:strcpy(fac, "FRE."); break;
    case 5:strcpy(fac, "FKSIS."); break;
    case 6:strcpy(fac, "FTK."); break;
    case 7:strcpy(fac, "EF."); break;
    default:strcpy(fac, "1"); break;
    }
    return fac;
}
int FindYear(int* arr, int year) {
   for(int i=1; i<=5; i++)
       if ((year - i) % 10 == arr[0]) {
           return year - i;
       }
   return 1;
}
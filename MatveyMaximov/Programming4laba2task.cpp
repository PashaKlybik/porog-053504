// Programming 4 laba 2nd task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <clocale>
#include <ctime>
#pragma warning(disable: 4996)
#define N 100
#define M 100

int main()
{
    char arr[M][N];
    char buffer[N];
    int i = 0, j = 0, k = 0,count = 0;
    FILE* fp;
    fp = fopen("C:\\Users\\user\\source\\repos\\Programming4laba2ndtask\\Programming 4 laba 2nd task\\Debug\\FIO.txt", "r+");
    if(fp == NULL){
        printf("Cannot open file. \n\n");
        exit(1);
    }
    else {
        printf("File open. \n\n");
    }
    while (fgets(buffer, N, fp) != NULL) {
        while(buffer[i] != '\0'){
            if (i == 0) {
                if ((int)buffer[i] >= 97 && (int)buffer[i] <= 122) {
                        buffer[i] -= 32;
                        printf("%c", buffer[i]);
                }
                else {
                    printf("%c", buffer[i]);
                }
            }
            else if (buffer[--i] == ' ') {
                i++;
                if ((int)buffer[i] >= 97 && (int)buffer[i] <= 122) {
                    buffer[i] -= 32;
                    printf("%c", buffer[i]);
                }
                else {
                    printf("%c", buffer[i]);
                }
            }
            else {
                i++;
                printf("%c", buffer[i]);
            }
            if (((int)buffer[i] >= 65 && (int)buffer[i] <= 90) || ((int)buffer[i] >= 97 && (int)buffer[i] <= 122) || (int)buffer[i] == 32 || buffer[i] == '\n') {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                    arr[j][k] = buffer[i];
                    k = 0;
                }
                else {
                    arr[j][k] = buffer[i];
                    k++;
                }
            }
            i++;
        }
        i = 0;
        j++;
    }
    for (int a = 0; a < j; a++) {
        for (int b = 0; b < M; b++) {
            if (((int)arr[a][b] >= 65 && (int)arr[a][b] <= 90) || ((int)arr[a][b] >= 97 && (int)arr[a][b] <= 122) || (int)arr[a][b] == 32 || arr[a][b] == '\n') {
                if (count <= b) {
                    count = b;
                }
            }
            else {
                break;
            }
        }
    }
    printf("\n\n\n\n\n");
    printf("After sorting : \n");
    for (int a = 0; a < j; a++) {
        int buff = (int)arr[a][0];
        for(int b = a + 1; b < j; b++){
            if ((int)arr[b][0] < buff) {
                buff = (int)arr[b][0];
                int r = 0;
                while (r < count + 3) {
                    char buff = arr[a][r];
                    arr[a][r] = arr[b][r];
                    arr[b][r] = buff;
                    r++;
                }
            }
        }
    }
    for (int a = 0; a < j; a++) {
        for (int b = 0; b < count + 3; b++) {
            if (arr[a][b] == '\0') {
                printf("\n");
                b = 0;
                break;
            }
            else {
                printf("%c", arr[a][b]);
            }
        }
    }
    fclose(fp);
}

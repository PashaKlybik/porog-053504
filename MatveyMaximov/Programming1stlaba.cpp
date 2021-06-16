// Programming 1st laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100];
    int result;
    printf("Enter decimal number : ");
    gets_s(text);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ',') {
            if (text[i + 1] && text[i + 2] && text[i + 3]) {
                result = (text[i + 1] - '0') + (text[i + 2] - '0') + (text[i + 3] - '0');
                printf("%d", result);
            }
            else {
                printf("Error.Missing digits after ','");
            }
        }
    }
    return 0;
}

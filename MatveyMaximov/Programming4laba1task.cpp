// Programming 4 laba 1st task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void Part(int a) {
    int i = 0;
    while (i != a) {
        printf("#");
        i++;
    }
    printf("\n");
}

void Diagram(int a, int b, int c, int d, int e, int f, int s) {
    float n1 = 100,n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;
    printf("Diagram,which shows vowel dependence in text : \n\n\n");
    printf("All word count in text is %d,",a);
    printf("which is %f percents of the text. \n",n1);
    Part(a);
    n2 = (b * n1) / a;
    printf("A/a word count in text is %d,", b);
    printf("which is %f percents of the text. \n", n2);
    Part(b);
    n3 = (c * n1) / a;
    printf("E/e word count in text is %d,", c);
    printf("which is %f percents of the text. \n", n3);
    Part(c);
    n4 = (d * n1) / a;
    printf("I/i word count in text is %d,", d);
    printf("which is %f percents of the text. \n", n4);
    Part(d);
    n5 = (e * n1) / a;
    printf("O/o word count in text is %d,", e);
    printf("which is %f percents of the text. \n", n5);
    Part(e);
    n6 = (f * n1) / a;
    printf("U/u word count in text is %d,", f);
    printf("which is %f percents of the text. \n", n6);
    Part(f);
    n7 = (s * n1) / a;
    printf("Y/u word count in text is %d,", s);
    printf("which is %f percents of the text. \n", n7);
    Part(s);
}

int main()
{
    int count_ALL = 0, count_A = 0, count_E = 0, count_I = 0, count_O = 0, count_U = 0, count_Y = 0;
    char str[1000],ch;
    int i = 0;
    puts("Print your text : \n");
    while ((ch = getchar()) != '!') {
        count_ALL++;
        if (ch == 'A' || ch == 'a') {
            count_A++;
        }
        else if (ch == 'E' || ch == 'e') {
            count_E++;
        }
        else if (ch == 'I' || ch == 'i') {
            count_I++;
        }
        else if (ch == 'O' || ch == 'o') {
            count_O++;
        }
        else if (ch == 'U' || ch == 'u') {
            count_U++;
        }
        else if (ch == 'Y' || ch == 'y') {
            count_Y++;
        }
        str[i++] = ch;
    }
    str[i] = '\0';

    printf("\n\n");
    Diagram(count_ALL, count_A, count_E, count_I, count_O, count_U, count_Y);
    return 0;
}


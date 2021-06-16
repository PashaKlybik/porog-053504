// Programming 5 laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

// Структура,описывающая элемент двусвязного списка
typedef struct item {
    int digit;
    struct item* next;
    struct item* prev;
}Item;

//Структура,описывающая многоразрядное число
typedef struct mnumber {
    Item* head;
    Item* tail;
    int n;
}MNumber;

void AddDigit(MNumber* number, int digit) {
    Item* p = (Item*)malloc(sizeof(Item));
    p->digit = digit;
    p->next = p->prev = NULL;
    if (number->head == NULL) {
        number->head = number->tail = p;
    }
    else {
        number->tail->next = p;
        p->prev = number->tail;
        number->tail = p;
    }
    number->n++;
}

void PrintNumber(MNumber number) {
    Item* p = number.tail;
    printf("\n");
    printf("Number : ");
    while (p) {
        printf("%d", p->digit);
        p = p->prev;
    }
}

MNumber CreateNumber(const char* str) {
    MNumber number = { NULL, NULL, 0 };
    int n;
    for (n = strlen(str) - 1; n >= 0; n--) {
        AddDigit(&number, str[n] - '0');
    }
    return number;
}

long long NOD(long long sn , long long sm) {
    long long div;
    if (sn == sm) {
        return sn;
    }
    long long delta = sn - sm;
    if (delta < 0) {
        delta = -delta;
        div = NOD(sn, delta);
    }
    else {
        div = NOD(sm, delta);
    }
    return div;
}

long long NOK(long long sn, long long sm) {
    return sn * sm / NOD(sn, sm);
}

void ChangeNumberToInt(MNumber a, MNumber b) {
    MNumber nok = CreateNumber("");
    Item* p1 = a.head;
    Item* p2 = b.head;
    int n = 0, m = 0;
    long long s1 = 0, s2 = 0;
    while (p1 || p2) {
        if (p1) {
            s1 += (long long)(p1->digit) * pow(10, n);
            p1 = p1->next;
            n++;
        }
        if (p2) {
            s2 += (long long)(p2->digit) * pow(10, m);
            p2 = p2->next;
            m++;
        }
    }

    long long result = NOK(s1, s2);

    printf("\n");
    printf("NOK is : %lld", result);
    printf("\n");
    free(p1);
    free(p2);
}

int main()
{
    MNumber a = CreateNumber("112");
    MNumber b = CreateNumber("82");
    PrintNumber(a);
    PrintNumber(b);
    ChangeNumberToInt(a, b);
}



#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node* next;
    struct node* prev;
    int digit;
}Node;

typedef struct list {
    Node* head;
    Node* tail;
    int size;
}List;


List calculation(List number);
List difference(List one, List two);
List divByTwo(List number);
int counter(List number, int x);
List inBinary(List number);
List createNum(int pow);
void freeList(List *number);

int main()
{
    List num_1 = createNum(39873);
    List num_2 = createNum(19936);
    List num_3 = difference(num_1, num_2);
    num_3 = inBinary(num_3);
    int count_of_zero = counter(num_3, 0);
    int count_of_one = counter(num_3, 1);
    if (count_of_one - count_of_zero == 1) {
        printf("Number is perfect ");
    }
    else {
        printf("Number is not perfect");
    }
    freeList(&num_1);
    freeList(&num_2);
    freeList(&num_3);
    return 0;
}
List calculation(List number) {


    Node* tmp = number.tail;
    while (number.tail) {
        number.tail->digit *= 2;
        number.tail = number.tail->prev;
    }
    number.tail = tmp;
    while (number.tail->prev) {
        if (number.tail->digit / 10 > 0) {
            int tmp = number.tail->digit / 10;
            number.tail->prev->digit += tmp;
            number.tail->digit %= 10;

        }
        number.tail = number.tail->prev;
    }

    if (number.tail->digit / 10 > 0) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->digit = number.tail->digit / 10;
        p->prev = NULL;
        number.tail->digit %= 10;
        p->next = number.tail;
        number.tail->prev = p;
        number.head = p;
        number.size++;
    }

    number.tail = tmp;

    return number;
}

List difference(List one, List two) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp = one.tail;
    while (two.size) {
        if (one.tail->digit < two.tail->digit) {
            one.tail->prev->digit -= 1;
            one.tail->digit += 10;
            one.tail->digit -= two.tail->digit;
        }
        else {
            one.tail->digit -= two.tail->digit;
        }
        one.tail = one.tail->prev;
        two.tail = two.tail->prev;
        two.size--;
    }
    one.tail = tmp;
    return one;

}

List divByTwo(List number) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp = number.head;
    while (number.head) {

        if (number.head->digit == 0) {
            number.head = number.head->next;
            number.head->prev = NULL;

        }
        if (number.head->digit % 2 == 1 && number.head->next) {
            number.head->next->digit += 10;
        }
        number.head->digit /= 2;
        number.head = number.head->next;
    }

    number.head = tmp;

    return number;
}

int counter(List number, int x) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp = number.head;
    int count = 0;
    while (number.head) {
        if (number.head->digit == x) {
            count++;
        }
        number.head = number.head->next;
    }
    return count;
}

List inBinary(List number) {
    List bin_number = { NULL,NULL,0 };
    while (number.tail->digit != 0) {

        Node* p = (Node*)malloc(sizeof(Node));
        p->digit = 0;
        if (number.tail->digit % 2 == 1) {
            p->digit = 1;

        }


        if (!bin_number.head) {

            p->next = p->prev = NULL;
            bin_number.head = bin_number.tail = p;
            bin_number.size++;
        }
        else {
            p->prev = NULL;
            p->next = bin_number.head;
            bin_number.head->prev = p;
            bin_number.head = p;
            bin_number.size++;
        }

        number = divByTwo(number);


    }
    return bin_number;
}

List createNum(int pow) {
    List number = { NULL,NULL,0 };
    for (int i = 0; i < pow; i++)
    {


        if (!number.head) {
            Node* n = (Node*)malloc(sizeof(Node));
            n->digit = 2;
            n->next = n->prev = NULL;
            number.head = number.tail = n;
            number.size++;
        }
        else {
            number = calculation(number);


        }
    }
    return number;
}

void freeList(List *number) {
    Node *tmp;
    while (number->head) {
        tmp = number->head;
        number->head = number->head->next;
        free(tmp);
        number->size--;
    }
}
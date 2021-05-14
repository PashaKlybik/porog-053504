#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

int main() {

}
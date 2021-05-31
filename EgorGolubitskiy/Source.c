#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void printList(struct Node* node);

void from_list_to_tree(struct node* tree, struct list* lst);

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data);


void main(void)
{
    int n;
    printf("Enter n: ");
    scanf_s("%d", &n);

    struct list* lst = NULL;
    struct node* root;
    root = rand() % 100;

    for (int i = 0; i < n * 5; i++)
    {
        int number = rand() % 100;

        push(&lst, number);
    }
    printList(lst);
    

    return 0;
}



void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}
void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
 
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref;
    new_node->data = new_data;

    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return;
}
void printList(struct Node* node)
{
    struct Node* last;
    while (node != NULL) {
        printf("%d\n", node->data);
        last = node;
        node = node->next;
    }
}


struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

void from_list_to_tree(struct node* tree, struct Node* node)
{
    struct Node* last;
    while (node != NULL) {
        if (tree->data < node->data) {
            tree->left;
        }
        else
            newNode(tree->right, node);
        last = node;
        node = node->next;
    }
}
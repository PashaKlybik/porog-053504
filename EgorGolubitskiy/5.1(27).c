#include <stdio.h>
#include <malloc.h>

struct QNode {
    char key;
    struct QNode* next;
};
struct Queue {
    struct QNode* front, * rear;
};
struct QNode* newNode(char k);
struct Queue* createQueue();
void enQueue(struct Queue* q, char k);
void deQueue(struct Queue* q);
void print(struct Queue* q);

struct Node {
    int data;
    char s;
    char c;
    struct Node* next;
    struct Node* prev;
};
void push(struct Node** head_ref, int new_data, char s, char c);
void insertAfter(struct Node* prev_node, int new_data, char s, char c);
void append(struct Node** head_ref, int new_data, char s, char c);
void printList(struct Node* node);

void work_with_queue(struct Node* node, struct Queue** q, int n);

void main(void)
{
    int n;
    printf("Enter n: ");
    scanf_s("%d", &n);
    struct Queue** q = (struct Queue*)malloc(sizeof(struct Queue*) * n);
    for (int i = 0; i < n; i++)
        q[i] = createQueue();
   
    struct list* lst = NULL;

    for (int i = 0; i < n * 5; i++)
    {
        int number = rand() % n;
        char s, c;
        if (rand() % 2 == 0)
            s = 'A';
        else
            s = 'D';
        c = (char)(97 + rand() % 26);

        push(&lst, number, s, c);
    }
    printList(lst);
    work_with_queue(lst, q, n);
   
    return 0;
}

struct QNode* newNode(char k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return(q);
}
void enQueue(struct Queue* q, char k)
{
    struct QNode* temp = newNode(k);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}
void print(struct Queue* q)
{
    struct Queue* temp = q;
    while (temp->front != NULL)
    {
        printf(" %c ", temp->front->key);
        temp->front = temp->front->next;
    }
}

void push(struct Node** head_ref, int new_data, char s, char c)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->c = c;
    new_node->s = s;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}
void insertAfter(struct Node* prev_node, int new_data, char s, char c)
{
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->c = c;
    new_node->s = s;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void append(struct Node** head_ref, int new_data, char s, char c)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->c = c;
    new_node->s = s;

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
        printf("%d, %c, %c\n", node->data, node->s, node->c);
        last = node;
        node = node->next;
    }
}

void work_with_queue(struct Node* node, struct Queue** q, int n)
{
    struct Node* last;
    while (node != NULL) 
    {
        if (node->s == 'A')
        {
            enQueue(q[node->data], node->c);
        }
        else if (node->s == 'D')
        {
            deQueue(q[node->data]);
        }
        last = node;
        node = node->next;
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {   
        printf("%d: ", i);
        print(q[i]);
        printf("\n");
    }
}
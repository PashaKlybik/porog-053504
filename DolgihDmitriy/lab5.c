#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct list {

    int size;

    Node* head;
    Node* tail;
} list;

list* create_list()
{
    list* lt = malloc(sizeof(list));

    lt->size = 0;
    lt->head = NULL;
    lt->tail = NULL;

    return lt;
}

void InsertStart(list* lt, int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = lt->head;

    lt->head = node;
    lt->size += 1;
}

void push(list* lt, int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (lt->head == NULL)
    {
        lt->head = node;
        lt->tail = node;
        node = NULL;
    }
    else
    {
        lt->tail->next = node;
        lt->tail = node;
    }

    lt->size += 1;
}

void InsertPos(list* lt, int pos, int data)
{
    if (pos == 1)
    {
        InsertStart(lt, data);

    }
    else if (pos > lt->size)
    {
        printf("There are %d elements in List,inserted to the back of List\n", lt->size);
        push(lt, data);

    }
    else {
        Node* tmp = malloc(sizeof(Node));
        Node* cur;
        tmp->data = data;
        cur = lt->head;
        for (int i = 1; i < pos - 1; i++)
        {
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
        lt->size++;
    }
}

void printList(list* lt)
{
    Node* node = malloc(sizeof(Node));
    node = lt->head;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteList(list* lt) {


    Node* prev = NULL;
    while (lt->head->next)
    {
        prev = lt->head;
        lt->head = lt->head->next;
        free(prev);
        lt->size -= 1;
    }
    free(lt->head);
    lt->size--;
    lt->head = NULL;
}

void deleteFirst(list* lt)
{
    Node* node = malloc(sizeof(Node));
    node = lt->head;
    lt->head = lt->head->next;
    lt->size--;
    free(node);

}

void deleteLast(list* lt)
{

    Node* current = malloc(sizeof(Node));
    Node* previous = malloc(sizeof(Node));
    current = lt->head;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    lt->tail = previous;
    previous->next = NULL;
    lt->size--;
    free(current);

}


void deletePos(list* lt, int pos)
{
    if (pos == 1)
    {
        deleteFirst(lt);

    }
    else if (pos > lt->size)
    {
        printf("There are %d elements in List,deleted last\n", lt->size);
        deleteLast(lt);


    }
    else {
        Node* current = malloc(sizeof(Node));
        Node* previous = malloc(sizeof(Node));
        current = lt->head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        lt->size--;
        free(current);

    }

}

void removeDuplicates(list* lt)
{
    {
        Node* t, * p, * i, * prev;
        for (p = lt->head; p != NULL; p = p->next)
        {
            prev = p;
            for (i = p->next; i != NULL; )
            {
                if (i->data == p->data)
                {
                    t = prev->next = i->next;
                    free(i);
                    lt->size--;
                    i = t;
                    continue;
                }
                prev = i;
                i = i->next;
            }
        }

    }
}

void sort(list*lt){
    Node* ptr = lt->head; Node* tmp = NULL; Node* prev = NULL;
int  flag = 0;
if (lt->head)
{
    do
    {
        flag = 0;
        ptr = lt->head;
        while (ptr->next)
        {
            if (ptr->data > ptr->next->data)
            {
                if (ptr == lt->head)
                {
                    tmp = ptr;
                    ptr = tmp->next;
                    tmp->next = ptr->next;
                    ptr->next = tmp;
                    lt->head = ptr;
                    flag = 1;
                }
                else
                {
                    tmp = ptr;
                    ptr = tmp->next;
                    tmp->next = ptr->next;
                    ptr->next = tmp;
                    prev->next = ptr;
                    flag = 1;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }
    } while (flag);
   
}
    Node* a;
    a = lt->head;
    while(a)
    {
        lt->tail = a;
        a = a->next;
    }

}


list* merge(list* lt1,list *lt2)
{
    list* lt3 = create_list();
    Node* a;
    Node* b;
     a = lt1->head;
     b = lt2->head;
    while (a) {
        push(lt3, a->data);
        if (a == lt1->tail)
            break;
        a = a->next;
    }
    while(b)
    {
        push(lt3, b->data);
        if (b == lt2->tail)
            break;
        b = b->next;
    }
   
    return lt3;
}
void mergeSort(list *lt1,list *lt2,list *lt3)
{
    if (lt1->head) {
        printf("1st List:");
        printList(lt1);
    }
    else printf("1st List:clear\n");
    
    if (lt2->head) {
        printf("2st List:");
        printList(lt2);
    }
    else  printf("2st List:clear\n");
    sort(lt1);
    sort(lt2);
    removeDuplicates(lt1);
    removeDuplicates(lt2);
    if (lt1->head) {
        printf("1st sorted List without duplicates:");
        printList(lt1);
    }
    
    if (lt2->head) {
        printf("2st sorted List without duplicates:");
        printList(lt2);
    }
   
    lt3 = merge(lt1, lt2);
    sort(lt3);
   if (lt3->head)
        printf("3st sorted,merged List:");
    printList(lt3);
    removeDuplicates(lt3);
    if (lt3->head)
        printf("3st sorted,merged List without duplicates:");
    printList(lt3);
    printf("\n");
}

int main()
{
    list* FirstList = create_list();
    list* SecondList = create_list();
    list* ThirdList = create_list();
    printf("Enter capacity of first List:");
    int first;
    scanf_s("%d", &first);
    printf("Enter %d numbers:\n",first);
    for(int i=0;i<first;i++)
    {
        int a;
        scanf_s("%d", &a);
        push(FirstList, a);

    }
    printf("Enter capacity of second List:");
    int second;
    scanf_s("%d", &second);
    printf("Enter %d numbers:\n",second);
    for (int i = 0; i < second; i++)
    {
        int a;
        scanf_s("%d", &a);
        push(SecondList, a);
    }
 
    mergeSort(FirstList, SecondList,ThirdList);
    deleteList(FirstList);
    deleteList(SecondList);
    deleteList(ThirdList);



    return 0;
}


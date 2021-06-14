#include <stdio.h>


typedef struct Node {
    int data;
 
    struct Node* next;
    struct Node* prev;
};
void append(struct Node** head_ref, struct Node** tail_ref, int new_data);
void printList(struct Node* node);
void push(struct Node** head_ref, int new_data);
int empty(struct Node* head_ref);
void fact(struct Node* node);
void find_fact(struct Node* node);


void main(void)
{
    char ch;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    printf("Enter n: ");
    while ((ch = getchar()) != '\n')
    {
        if ((int)ch < 48 || (int)ch > 57)
        {
            printf("Error!\nWrong number.");
            free(head);
            break;
        }
        else
            push(&head, (int)ch - 48);
    }
    find_fact(head);
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
void append(struct Node** head_ref, struct Node** tail_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref;
    new_node->data = new_data;
   

    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = *tail_ref = new_node;
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
    //struct Node* last = node;
    while (node != NULL) {
        printf("%d", node->data);
      //  last = node;
        node = node->next;
    }
}
int empty(struct Node* head_ref)
{
    if (head_ref == NULL)
        return 1;
    else
        return 0;
}

void find_fact(struct Node* node)
{
    struct Node* num = node, *ans_head, *num2 = node;
    num2->data--;
    ans_head = NULL;
    int buf1 = 0, buf2;
    while (num2 != NULL)
    {
        if ((num2->data * num->data) > 9)
        {
            buf2 = (num2->data * num->data + buf1) % 10;
            buf1 = (num2->data * num->data + buf1) / 10;
            
            push(&ans_head, buf2);
        }
        else if ((num2->data * num->data) <= 9 && (num2->data * num->data) >= 0)
        {
            buf2 = (num2->data * num->data + buf1) % 10;
            buf1 = 0;

            push(&ans_head, buf2);
        }
        if(num->prev != NULL)
            num = num->prev;
        else
        {
            printList(ans_head);
            break;
        }
    }

}
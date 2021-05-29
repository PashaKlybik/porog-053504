#include <stdio.h> 
#include <stdlib.h>

typedef struct item{
	int numb;
	struct item* l;
	struct item* r;
}Item;

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}Node;

void AddNode(int data, Item** node);
void Stack(Item* node, Node** stack1, Node** stack2);
void PreOrder(Item* node);
void InsertLast(int x, Node** head, Node** tail);
void push(Node** stack, int x);
void Print(Node* s);
void InOrder(Item* node);
void PostOrder(Item* node);
Node* Init(int x);
int Size(Node *s);
int Top(Node *s);
void Pop(Node **tail, Node* head);

void main(void)
{
	int r, sizof;
	Item* root = NULL;
	Node* head = NULL;
	Node* tail = NULL;
	Node* stack1 = NULL;
	Node* stack2 = NULL;

	for (int i = 0; i < 10; i++) {
		 r= rand()%100+1;
		 InsertLast(r, &head, &tail);
	}
	printf("Your list:\n");
	Print(head);
	sizof = Size(head);
	for (int i = 0; i < sizof; i++) {
		AddNode(Top(tail), &root);
		Pop(&tail, head);
	}
	printf("PreOrder:\n");
	PreOrder(root);
	printf("\nInOrder:\n");
	InOrder(root);
	printf("\nPostOrder:\n");
	PostOrder(root);
	Stack(root, &stack1, &stack2);
	printf("\nEven nodes:\n");
	Print(stack1);
	printf("Odd nodes:\n");
	Print(stack2);
}

void AddNode(int data, Item** node)
{
	if (*node == NULL) {
		*node = (Item*)calloc(1, sizeof(Item));
		(*node)->numb = data;
		(*node)->l = (*node)->r = NULL;
	}
	else {
		if (data <= (*node)->numb)
			AddNode(data, &(*node)->l); 
		else if (data > (*node)->numb)
			AddNode(data, &(*node)->r);
	}
}

void Stack(Item* node, Node** stack1, Node** stack2)
{
	if ((node->numb) % 2 == 0)
		push(&(*stack1), node->numb);
	else 
		push(&(*stack2), node->numb);

		if (node->l)
			Stack(node->l, &(*stack1), &(*stack2));
		if (node->r)
			Stack(node->r, &(*stack1), &(*stack2));
	
}
void PreOrder(Item* node)
{
	printf("%d ", node->numb);
	if (node->l)
		PreOrder(node->l);
	if (node->r)
		PreOrder(node->r);
}

void InOrder(Item* node)
{
	if (node->l)
		PreOrder(node->l);
	printf("%d ", node->numb);
	if (node->r)
		PreOrder(node->r);
}

void PostOrder(Item* node)
{
	if (node->l)
		PreOrder(node->l);
	if (node->r)
		PreOrder(node->r);
	printf("%d ", node->numb);
}

Node* Init(int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertLast(int x, Node** head, Node** tail) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = x;
	if (*head == NULL) {
		(*head) = (*tail) = Init(x);
	}
	else {
		newNode->prev = (*tail);
		(*tail)->next = newNode;
		(*tail) = newNode;
	}
}

void push(Node** stack, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = x;
	if ((*stack) == NULL) {
		(*stack) = Init(x);
	}
	else {
		Node* last = (*stack);
		while (last->next != NULL)
			last = last->next;
		newNode->prev = last;
		last->next = newNode;
		
	}
}

void Print(Node* s) {
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

int Top(Node *s)
{
	return s->data;
}

void Pop(Node** tail, Node* head) {
	Node* current = NULL, * previous = NULL;
	if (Size(head) == 1)
	{
		(*tail) = (*tail)->prev;
		free(tail);
	}
	else
	{
		(*tail) = (*tail)->prev;
	}
}

int Size(Node *s) {
	Node* temp = s;
	int k = 0;
	while (temp != NULL) {
		temp = temp->next;
		k++;
	}
	return k;
}
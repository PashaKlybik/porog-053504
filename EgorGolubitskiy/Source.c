#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
void append(struct Node** head_ref, int new_data);
void push(struct Node** head_ref, int new_data);
void printList(struct Node* node);

struct nodeTree {
	int key;
	struct nodeTree* left, * right;
};
struct nodeTree* newNode(int item);
void inorder(struct nodeTree* root);
void preorder(struct nodeTree* root);
void postorder(struct nodeTree* root);
struct nodeTree* insert(struct nodeTree* node, int key);

struct nodeTree* from_list_to_tree(struct nodeTree* tree, struct Node* lst);
void show(struct nodeTree* tree);

void main(void)
{
	int n, d = 0;

	printf("Enter n: ");
	scanf_s("%d", &n);

	struct Node* lst = NULL;
	struct nodeTree* root = NULL;

	for (int i = 0; i < n; i++)
	{
		int number = rand() % 100;
		push(&lst, number);
	}
	printf("List: ");
	printList(lst);
	printf("\n\n");

	root = from_list_to_tree(root, lst);
	printf("Preorder: ");
	preorder(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\n\n");
	show(root);

	free(lst);
	free(root);
	return;
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
void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref;
	new_node->data = new_data;


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
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
}

struct nodeTree* newNode(int item)
{
	struct nodeTree* temp
		= (struct nodeTree*)malloc(sizeof(struct nodeTree));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct nodeTree* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf(" %d ", root->key);
		inorder(root->right);
	}
}
void preorder(struct nodeTree* root)
{
	if (root != NULL) {
		printf(" %d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct nodeTree* root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d ", root->key);
	}
}
struct nodeTree* insert(struct nodeTree* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct nodeTree* from_list_to_tree(struct nodeTree* tree, struct Node* lst)
{
	struct Node* last;
	while (lst != NULL) {
		tree = insert(tree, lst->data);
		last = lst;
		lst = lst->next;
	}
	return(tree);
}

int find_count(struct nodeTree* tree)
{
	int count = 0;

	if (tree != NULL)
	{
		count++;
		count += find_count(tree->left);
		count += find_count(tree->right);
	}
	else
		return count;
}
void show(struct nodeTree* tree)
{
	int count_left = find_count(tree->left), count_right = find_count(tree->right);

	printf("Bigest branch: ");
	if (count_left > count_right)
		preorder(tree->left);
	else if (count_left < count_right)
		preorder(tree->right);
	else
		printf("The branches are equal.");
}
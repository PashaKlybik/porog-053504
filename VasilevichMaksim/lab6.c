#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define TEXT_SIZE 256

/*
5.2 (15)
¬ текстовом файле записаны целые числа. ѕостроить
сбалансированное бинарное дерево, в котором количество левых и
правых потомков у каждой вершины отличаетс€ не более чем на
единицу.
*/

typedef struct Node {
	long long int key;
	unsigned char height;
	struct Node* left_child;
	struct Node* right_child;
} Node;

void PrintTree(Node* root, int tabs);
Node* CreateTree(int k, long long int* num);
Node* AddNode(long long int key, Node* root);
Node* RotateRight(Node* root);
Node* RotateLeft(Node* root);
Node* Balance(Node* root);
int height(Node* p);
int GetBF(Node* p);
void UpdateHeight(Node* p);
void PrintInOrder(Node* root);
void ClearTree(Node* root);


// adding one node to the tree
Node* AddNode(long long int key, Node* root) {
	if (!root) {
		root = (Node*)malloc(sizeof(Node));
		root->key = key;
		root->height = 0;
		root->left_child = NULL;
		root->right_child = NULL;
		return root;
	}
	else if (key < root->key) {
		root->left_child = AddNode(key, root->left_child);
	}
	else {
		root->right_child = AddNode(key, root->right_child);
	}
	return Balance(root);
}

// creating whole tree from int massive
Node* CreateTree(int k, long long int* num) {
	Node* root = AddNode(num[0], NULL);
	for (int i = 1; i < k; i++)
		root = AddNode(num[i], root);
	return root;
}

// printing tree on screen
void PrintTree(Node* root, int tabs) {
	if (root == NULL) return;
	tabs += 5;

	PrintTree(root->left_child, tabs);
	for (int i = 0; i < tabs; i++) printf(" ");
	printf("%lld\n", root->key);
	PrintTree(root->right_child, tabs);
	tabs -= 5;

	return;
}

void PrintInOrder(Node* root) {
	if (root->left_child)
		PrintInOrder(root->left_child);

	printf("%lld, ", root->key);

	if (root->right_child)
		PrintInOrder(root->right_child);
}
void ClearTree(Node* root) {
	if (root->left_child) ClearTree(root->left_child);
	if (root->right_child) ClearTree(root->right_child);
	free(root);
}

// -------------------------------------------------------------------------------------------------------------
// Balance Functions
Node* RotateRight(Node* root) {
	Node* p = root;
	Node* q = p->left_child;
	p->left_child = q->right_child;
	q->right_child = p;
	UpdateHeight(p);
	UpdateHeight(q);
	return q;
}
Node* RotateLeft(Node* root) {
	Node* q = root;
	Node* p = q->right_child;
	q->right_child = p->left_child;
	p->left_child = q;
	UpdateHeight(q);
	UpdateHeight(p);
	return p;
}

Node* Balance(Node* root) {
	UpdateHeight(root);
	if (GetBF(root) == 2) {
		if (GetBF(root->right_child) < 0)
			root->right_child = RotateRight(root->right_child);
		return RotateLeft(root);
	}
	else if (GetBF(root) == -2) {
		if (GetBF(root->right_child) > 0)
			root->left_child = RotateLeft(root->left_child);
		return RotateRight(root);
	}
	return root;
}

int height(Node* p) {
	return p ? p->height : -1;
}
int GetBF(Node* p) {
	return height(p->right_child) - height(p->left_child);
}
void UpdateHeight(Node* p) {
	int heightl = height(p->left_child);
	int heightr = height(p->right_child);
	p->height = (heightl > heightr ? heightl : heightr) + 1;
}

// -------------------------------------------------------------------------------------------------------------
bool compareSeparator(char a) {
	if (a == ' ' || a == ',' || a == '.' || a == '?' || a == '!' || a == ';' || a == ':') return true;
	return false;
}

long long int ToInt(char* w, int l) {
	long long int n = 0; int i = l - 1, minus = 1, k = 0;
	if (w[0] == '-') minus = -1;
	while(i >= 0 && w[i] != '-')
		n += (int)(w[i--] - '0') * (int)pow(10, k++) * minus;
	return n;
}

// -------------------------------------------------------------------------------------------------------------
int main(void) {
	FILE* file = fopen("text.txt", "r");
	char separator[] = " .,?!;:";

	char text[TEXT_SIZE][TEXT_SIZE];
	char words[TEXT_SIZE][TEXT_SIZE];
	long long int num[TEXT_SIZE];
	int amount = 0;
	int k = 0;
	if (!file) return 1;
	while (fgets(text[amount], TEXT_SIZE, file) != NULL) {
		if (text[amount][strlen(text[amount]) - 1] == '\n') text[amount][strlen(text[amount]) - 1] = '\0';
		int i = 0;
		while (i < strlen(text[amount])) {
			int j = 0;
			while (!compareSeparator(text[amount][i]) && i < strlen(text[amount])) {
				words[k][j++] = text[amount][i++];
			}
			if (j) {
				words[k][j] = '\0';
				num[k] = ToInt(words[k], strlen(words[k]));
			}
			if (i && !compareSeparator(text[amount][i - 1])) k++;
			i++;
		}
		amount++;
	}

	Node* root = CreateTree(k ,num);
	PrintTree(root, 0);
	printf("Traverse Inorder: ");
	PrintInOrder(root);
	ClearTree(root);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct binarytree
{
	char* text;
	struct binarytree* left_child, * right_child;
} BinaryTree;

void AddBranch(BinaryTree* head, char* text, size_t m);
void _changeBranch(BinaryTree** head, char s, size_t m);
char* createText(BinaryTree* head, char s, size_t m);
void deleteTree(BinaryTree* head);
void displayPreOrder(BinaryTree* head);
void displayInOrder(BinaryTree* head);
void displayPostOrder(BinaryTree* head);

int main()
{
	FILE* fp = fopen("C:\\Users\\Asus\\Desktop\\input.txt", "r");
	size_t n, m;
	BinaryTree* head = malloc(sizeof(BinaryTree));
	head->left_child = NULL;
	head->right_child = NULL;
	fscanf(fp, "%d %d", &n, &m);
	head->text = NULL;
	char* buffer = malloc((m + 2) * sizeof(char));
	fgets(buffer, m, fp);
	for (size_t i = 0; i < n; i++)
	{
		fgets(buffer, m + 2, fp);
		AddBranch(head, buffer, m);
	}
	char choise = 'y';
	while (choise == 'y')
	{
		printf("1. Pre Order\n 2.In Order\n 3. Post Order: ");
		scanf(" %c", &choise);
		if (choise == '1')
			displayPreOrder(head);
		else if (choise == '2')
			displayInOrder(head);
		else if (choise == '3')
			displayPostOrder(head);
		else
			printf("Incorrect answer\n");
		printf("Do you want to continue?(y/n) ");
		scanf(" %c", &choise);
	}
	fclose(fp);
	deleteTree(head);
	return 0;
}

char* createText(BinaryTree* head, char s, size_t m)
{
	size_t text_size = 2;
	if (head->text != NULL)
		text_size += strlen(head->text);
	char* res = malloc(text_size * sizeof(char));
	res[text_size - 1] = '\0';
	res[text_size - 2] = s;
	int pos = text_size - 3;
	while (pos >= 0)
	{
		if (head->text != NULL)
		{
			for (int i = strlen(head->text) - 1; i >= 0 && pos >= 0; i--)
			{
				res[pos--] = head->text[i];
			}
		}
		if (pos < 0)
			break;
		res[pos--] = '0';
	}
	return res;
}

void _changeBranch(BinaryTree** head, char s, size_t m)
{
	if (s == '\n')
		return;
	if (s == '0')
	{
		if ((*head)->left_child == NULL) {
			(*head)->left_child = malloc(sizeof(BinaryTree));
			(*head)->left_child->text = createText(*head, s, m);
			(*head)->left_child->left_child = NULL;
			(*head)->left_child->right_child = NULL;
		}
		*head = (*head)->left_child;
	}
	else
	{
		if ((*head)->right_child == NULL) {
			(*head)->right_child = malloc(sizeof(BinaryTree));
			(*head)->right_child->text = createText(*head, s, m);
			(*head)->right_child->left_child = NULL;
			(*head)->right_child->right_child = NULL;
		}
		*head = (*head)->right_child;
	}
}
void AddBranch(BinaryTree* head, char* text, size_t m)
{
	BinaryTree* currentNode = head;
	for (int i = 0; i < strlen(text); i++)
	{
		_changeBranch(&currentNode, text[i], m);
	}
}
void displayPreOrder(BinaryTree* head)
{
	if (head == NULL)
		return;
	if (head->text == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->text);
	displayPreOrder(head->left_child);
	displayPreOrder(head->right_child);
}
void displayInOrder(BinaryTree* head)
{
	if (head == NULL)
		return;
	displayInOrder(head->left_child);
	if (head->text == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->text);
	displayInOrder(head->right_child);
}
void displayPostOrder(BinaryTree* head)
{
	if (head == NULL)
		return;
	displayPostOrder(head->left_child);
	displayPostOrder(head->right_child);
	if (head->text == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->text);
}
void deleteTree(BinaryTree* head)
{
	if (head == NULL)
		return;
	if (head->left_child != NULL)
		deleteTree(head->left_child);
	if (head->right_child != NULL)
		deleteTree(head->right_child);
	free(head->text);
	free(head);
}
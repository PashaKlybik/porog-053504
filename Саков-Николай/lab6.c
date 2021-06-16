#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

struct Tree* AddNode(char data, struct Tree* tree);
void DeleteTree(struct Tree* tree);
int NodesNumber(struct Tree* tree, char ch, short isFound, int count);
struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
};

void PrintTree(struct Tree* tree, int n)
{
	if (tree->left) PrintTree(tree->left, n + 1);
	for (int i = 0; i < n; i++) printf(" ");
	printf("%c\n", tree->data);
	if (tree->right) PrintTree(tree->right, n + 1);
}

int main()
{
	setlocale(0, "rus");
	char str[128];
	int countOfNodes;
	struct Tree *tree = NULL;
	printf("Введите строку: ");
	gets(str);
	int wi = 0;
	while (str[wi] != '\0')
	{
		tree = AddNode(str[wi], tree);
		wi++;
	}
	printf("Введите символ: ");
	char ch;
	scanf("%c", &ch);
	PrintTree(tree, 0);
	countOfNodes = NodesNumber(tree, ch, 0, 0);
	printf("Количество узлов в правом и левом поддеревьях для символа %c = %d", ch, countOfNodes);
	DeleteTree(tree);
}

struct Tree* AddNode(char data, struct Tree* tree)
{
	if (tree == NULL)
	{
		tree = malloc(sizeof(struct Tree));
		tree->data = data;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (toupper(data) < toupper(tree->data))
	{
		tree->left = AddNode(data, tree->left);
	}
	else
	{
		tree->right = AddNode(data, tree->right);
	}
	return tree;
}

void DeleteTree(struct Tree* tree)
{
	if (tree != NULL)
	{
		DeleteTree(tree->left);
		DeleteTree(tree->right);
		free(tree);
	}
}

int NodesNumber(struct Tree* tree, char ch, short isFound, int count)
{
	if (tree != NULL)
	{
		if (isFound == 0)
		{
			if (tree->data == ch)
			{
				count = NodesNumber(tree->left, ch, 1, count);
				count = NodesNumber(tree->right, ch, 1, count);
			}
			else
			{
				count = NodesNumber(tree->left, ch, 0, count);
				count = NodesNumber(tree->right, ch, 0, count);
			}
		}
		else
		{
			count++;
			count = NodesNumber(tree->left, ch, 1, count);
			count = NodesNumber(tree->right, ch, 1, count);
		}
	}
	return count;
}
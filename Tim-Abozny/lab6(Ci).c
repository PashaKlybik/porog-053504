#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


struct tr
{
	char value;
	struct tr* left;
	struct tr* right;
};

struct tr* toNode(char value, struct tr* tr)
{
	if (tr == NULL)
	{
		tr = malloc(sizeof(struct tr));
		tr->value = value;
		tr->left = NULL;
		tr->right = NULL;
	}
	else if (toupper(value) < toupper(tr->value))
	{
		tr->left = toNode(value, tr->left);
	}
	else
	{
		tr->right = toNode(value, tr->right);
	}
	return tr;
}

void clTree(struct tr* tr)
{
	if (tr != NULL)
	{
		clTree(tr->left);
		clTree(tr->right);
		free(tr);
	}
}

int ndCouter(struct tr* tr, char ch, short YesOrNot, int Counter)
{
	if (tr != NULL)
	{
		if (YesOrNot == 0)
		{
			if (tr->value == ch)
			{
				Counter = ndCouter(tr->left, ch, 1, Counter);
				Counter = ndCouter(tr->right, ch, 1, Counter);
			}
			else
			{
				Counter = ndCouter(tr->left, ch, 0, Counter);
				Counter = ndCouter(tr->right, ch, 0, Counter);
			}
		}
		else
		{
			Counter++;
			Counter = ndCouter(tr->left, ch, 1, Counter);
			Counter = ndCouter(tr->right, ch, 1, Counter);
		}
	}
	return Counter;
}

void Show(struct tr* tr, int n)
{
	if (tr->left)
	{
		Show(tr->left, n + 1);
	}
	for (int i = 0; i < n; i++)
	{
		printf(" ");
	}
	printf("%c\n", tr->value);
	if (tr->right)
	{
		Show(tr->right, n + 1);
	}
}

int main()
{
	setlocale(0, "rus");
	char str[128];
	int howNodes;
	struct tr* tr = NULL;

	printf("enter string: ");
	gets(str);

	int k = 0;
	while (str[k] != '\0')
	{
		tr = toNode(str[k], tr);
		k++;
	}
	printf("enter char: ");
	char ch;
	scanf("%c", &ch);

	Show(tr, 0);
	howNodes = ndCouter(tr, ch, 0, 0);
	printf("How nodes: %c = %d", ch, howNodes);
	clTree(tr);
	
	return 0;
}
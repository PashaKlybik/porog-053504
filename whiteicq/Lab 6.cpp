/*Построить бинарное дерево поиска из букв строки, вводимой пользователем. Разработать функцию подсчета числа листьев дерева.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
struct TNode
{
	char symbol;
	struct TNode* LeftNode;
	struct TNode* RightNode;
};

void TraversePreOrder(struct TNode* root)
{
	if (root)
	{
		printf("%c", root->symbol);
		TraversePreOrder(root->LeftNode);
		TraversePreOrder(root->RightNode);
	}
}

void TraverseInOrder(struct TNode* root)
{
	if (root)
	{
		TraverseInOrder(root->LeftNode);
		printf("%c", root->symbol);
		TraverseInOrder(root->RightNode);
	}
}

void TraversePostOrder(struct TNode* root)
{
	if (root)
	{
		TraversePostOrder(root->LeftNode);
		TraversePostOrder(root->RightNode);
		printf("%c", root->symbol);
	}
}

struct TNode* AddNBinaryNode(char ch, struct TNode* root)
{
	if (root == NULL)
	{
		root = (TNode*)malloc(sizeof(TNode));
		root->symbol = ch;
		root->LeftNode = NULL;
		root->RightNode = NULL;
	}

	else if (ch < root->symbol)
	{
		root->LeftNode = AddNBinaryNode(ch, root->LeftNode);
	}

	else
	{
		root->RightNode = AddNBinaryNode(ch, root->RightNode);
	}
	return root;
}

int CounterLeaf(struct TNode* root)
{
	if (!root)
	{
		return 0;
	}
	return root->LeftNode == NULL && root->RightNode == NULL ? 1 : CounterLeaf(root->LeftNode) + CounterLeaf(root->RightNode);
}

int main()
{
	int i = 0;
	char str[SIZE];
	printf("Enter your string:\n");
	gets_s(str);
	struct TNode* root = (TNode*)malloc(sizeof(TNode));
	root->LeftNode = NULL;
	root->RightNode = NULL;
	root->symbol = str[0];
	for (int i = 1; i < strlen(str); i++)
	{
		AddNBinaryNode(str[i], root);
	}
	printf("Binary tree with inorder: ");
	TraverseInOrder(root);
	printf("\n");
	printf("Binary tree with preorder: ");
	TraversePreOrder(root);
	printf("\n");
	printf("Binary tree with postorder: ");
	TraversePostOrder(root);
	printf("\n");
	printf("Number of leaf: %d", CounterLeaf(root));
	return 0;
}	
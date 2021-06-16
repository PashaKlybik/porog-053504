/*var.4(В текстовом файле записаны целые числа. Построить бинарное
дерево поиска, в узлах которого хранятся числа из файла.
Разработать функцию, определяющую число узлов дерева на
каждом уровне.)*/
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include<locale.h>
int tabs = 0;


typedef struct item {

	int data;
	struct item* right;
	struct item* left;
}Item;


void AddNode(int data, Item** node)
{
	if (*node == NULL)
	{
		*node = (Item*)calloc(1, sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else
	{
		if (data > (*node)->data)
			AddNode(data, &(*node)->left);
		else if (data < (*node)->data)
			AddNode(data, &(*node)->right);
		else printf("Уже существует %d на дереве\n", (*node)->data);

	}

}

void print(Item* node)
{
	if (node == NULL) return;
	tabs += 5;

	print(node->left);
	for (int i = 0; i < tabs; i++) printf(" ");
	printf("%d\n", node->data);
	print(node->right);
	tabs -= 5;

	return;

}

void freemem(Item* node)
{
	if (node != NULL)
	{
		freemem(node->left);
		freemem(node->right);
		free(node);
	}
}

int HeightOfTree(Item* node)
{
	if (node == 0)
		return 0;
	int left, right;
	if (node->left != NULL) {
		left = HeightOfTree(node->left);
	}
	else
		left = -1;
	if (node->right != NULL) {
		right = HeightOfTree(node->right);
	}
	else
		right = -1;
	int max = left > right ? left : right;
	return max + 1;

}

int numNodesHeightK(Item* root, int k) {
	if (root == NULL) return 0; //if the tree is empty return 0
	if (k == 0) return 1; //if k = 0, then the root is the only node to return 

	return numNodesHeightK(root->left, k - 1) + numNodesHeightK(root->right, k - 1);
}

void numNodes(Item* root)
{

	int k = HeightOfTree(root);
	for (int i = 0; i < k + 1; i++)
	{
		printf("%d элементы на %d уровне\n", numNodesHeightK(root, i), i);
	}
}

void sortmas(int* mas, int k)
{
	int tmp;
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (mas[j] < mas[i])
			{
				tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;

			}
		}
	}
}

void balanceTree(int* mas, int start, int end, Item** root)
{
	int mid = (start + end) / 2;
	AddNode(mas[mid], &(*root));
	if (mid > start)
		balanceTree(mas, start, mid - 1, &(*root)->right);
	if (mid < end)
		balanceTree(mas, mid + 1, end, &(*root)->left);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int mas[100];
	char buffer[128];
	Item* root = NULL;

	FILE* fp = fopen("data.txt", "r");
	int k = 0;
	if (!fp) exit(1);
	while (!feof(fp)) {
		if (fgets(buffer, 128, fp))
			if (atoi(buffer) != 0) {
				mas[k] = atoi(buffer);
				k++;
			}
	}
	sortmas(mas, k);
	balanceTree(mas, 0, k - 1, &root);
	printf("Бинарное дерево:\n");
	print(root);
	numNodes(root);
	fclose(fp);
	freemem(root);
	return 0;
}
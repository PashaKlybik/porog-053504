#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"

int tabs = 0;

typedef struct item {

	int data;
	struct item *right;
	struct item *left;
}Item;


void AddNode(int data, Item **node)
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
		else printf("There is already %d in the tree\n", (*node)->data);

	}

}

void print(Item *node)
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

void freemem(Item *node)
{
	if (node != NULL)
	{
		freemem(node->left);
		freemem(node->right);
		free(node->data);
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
		printf("%d elements on %d level\n", numNodesHeightK(root, i), i);
	}
}

int main()
{
	char buffer[128];
	Item *root = NULL;
	FILE *fp = fopen("BinTree.txt", "r"); 
	 
	if (!fp) exit(1);
	while (!feof(fp)) {
		if (fgets(buffer, 128, fp))
			if(atoi(buffer)!=0)
		AddNode(atoi(buffer), &root);
	 }

	printf("Binary Tree:\n");
	print(root);
	numNodes(root);
	fclose(fp);
	freemem(root);
	return 0;
}


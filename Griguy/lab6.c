// variant 16
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode         //Node structure
{
	struct TreeNode *left;
	struct TreeNode *right;
	char symb;
} TreeNode;

TreeNode* CreateNode(char c) {              //creator of a node
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	if (!node)
		exit(1);
	node->symb = c;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TreeNode* add(TreeNode* root, char c) {  //tree->add (uses CreateNode)
	if (!root) {
		return CreateNode(c);
	}
	TreeNode *temp = root;
	while (1) {
		if (c == temp->symb) {
			return root;           //if symbol exist in tree, does nothing
		}
		if (c < temp->symb) {
			if (temp->left) {
				temp = temp->left;
			}
			else {
				temp->left = CreateNode(c);
				return root;
			}
		}
		else {
			if (temp->right) {
				temp = temp->right;
			}
			else {
				temp->right = CreateNode(c);
				return root;
			}
        }
	}
}


TreeNode* find(TreeNode *root, char c) {    //returns address of found element
	if (!root) {
		return root;
	}
	while (1) {
		if (c == root->symb) {
			return root;
		}
		if (c < root->symb) {
			if (root->left) {
				root = root->left;
			}
			else {
				return NULL;         //if element is not found, returns NULL
			}
		}
		else {
			if (root->right) {
				root = root->right;
			}
			else {
				return NULL;
			}
		}
	}
}

void traverse_inorder(TreeNode *root) {  //in-order traverse of a tree
	if (!root)                           //prints all contained symbols
		return;
	if (root->left) {
		traverse_inorder(root->left);
	}
	putchar(root->symb);
	putchar(' ');
	if (root->right) {
		traverse_inorder(root->right);
	}
}

int find_height(TreeNode *root) {      //recursive finder of tree height
	int hleft, hright;
	hleft = root->left ? find_height(root->left) : 0;
	hright = root->right ? find_height(root->right) : 0;
	return (hleft > hright ? hleft : hright) + 1;
}

void clear(TreeNode *root) {     //clears a tree
    if (!root)
		return;

	clear(root->left);
	clear(root->right);

	free(root);
}


int main()
{
	TreeNode *root = NULL;
	char str[256];
	int i = 0;

	puts("Enter string:");
	gets(str);                //get users string

	while (str[i] != '\0') {
		char c = str[i];
		if (c>='a' && c<='z' || c>='A' && c<='Z') {
			root = add(root, c);            //adding LETTERS to the tree
		}
		i++;
	}

	traverse_inorder(root);            //traverse print of the tree
	printf("\n%d", find_height(root));   //prints height of the tree

    clear(root);
	getchar();
	return 0;
}

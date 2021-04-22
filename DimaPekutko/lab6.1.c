#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 256

typedef struct node {
    struct node *left;
    struct node *right;
    char data;
} Node;

typedef struct tree {
	Node *root;
	int length;
} Tree;

Node * addElement(char data, Node *node, Tree *tree) {
	if(node == NULL) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		if(!tree->length) {
			tree->root = node;
		}
		tree->length++;
	}
	else {
		if(data > node->data) {
			node->right = addElement(data, node->right, tree);
		}
		else {
			node->left = addElement(data, node->left, tree);
		}
	}
	return node;
}

void printNLR(Node *node) {
	if(node != NULL) {
		printf("%c\n", node->data);
		printNLR(node->left);
		printNLR(node->right);
	}
}

int countLeafs(Node *node) {
	if(node != NULL) {
		if((node->left == NULL) && (node->right == NULL)) {
			return 1;
		}	
		else {
			return 
				countLeafs(node->left) + 
				countLeafs(node->right);
		}
	}
}

Node *clearTree(Node *node, Tree *tree) {
	if(node != NULL) {
		clearTree(node->left, tree);
		clearTree(node->right, tree);
		printf("deleted=%c\n", node->data);
		free(node);
		tree->length--;
	}
}

int main() {
    char text[MAX_TEXT_SIZE];

	printf("Type your string:\n");
	fgets(text, MAX_TEXT_SIZE, stdin);   
	Tree tree;
	tree.length = 0;
	tree.root = NULL;
	for(int i = 0; i < strlen(text)-1; i++) {
		if(text[i] != ' ') {
			addElement(text[i], tree.root, &tree);
		}
	}
	printf("Tree direct trace:\n");
	printNLR(tree.root);
	printf("Leafs count=%d\n", countLeafs(tree.root));
	clearTree(tree.root, &tree);

	return 0;
}
// Programming6LabNew.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

struct bn_tree {
	int digit;
	struct bn_tree* left;
	struct bn_tree* right;
	struct bn_tree* parent;
};

struct bn_tree* root = NULL;

struct bn_tree* AddNode(int x, struct bn_tree* node, struct bn_tree* parent) {
	if (node == NULL) {
		node = (struct bn_tree*)malloc(sizeof(struct bn_tree));
		node->digit = x;
		node->left = NULL;
		node->right = NULL;
		node->parent = parent;
	}
	else {
		if (node->digit > x) {
			node->left = AddNode(x, node->left, node);
		}
		else {
			node->right = AddNode(x, node->right, node);
		}
	}
	return node;
}

void DeleteTree(struct bn_tree* node) {
	if (node != NULL) {
		DeleteTree(node->left);
		DeleteTree(node->right);
		free(node);
	}
}

struct bn_tree* FindMaxNode(struct bn_tree* node) {
	while (node->right) {
		node = node->right;
	}
	return node;
}

void Dedublicate(struct bn_tree* order_node, struct bn_tree* node_for_check) {
	if (order_node == NULL && node_for_check == NULL) {
		return;
	}
	if (node_for_check->left != 0) {
		Dedublicate(order_node, node_for_check->left);
	}
	if(node_for_check->right != 0) {
		Dedublicate(order_node, node_for_check->right);
	}
	if (order_node->digit == node_for_check->digit && order_node != node_for_check) {

		printf("Найден дубликат %d\n", node_for_check->digit);

		if (node_for_check->left && node_for_check->right) {
			bn_tree* Max = FindMaxNode(node_for_check->left);
			node_for_check->digit = Max->digit;
			Dedublicate(order_node, Max);
			return;
		}
		else if (node_for_check->left) {
			if (node_for_check == node_for_check->parent->left) {
				node_for_check->parent->left = node_for_check->left;
			}
			else {
				node_for_check->parent->right = node_for_check->left;
			}
		}
		else if (node_for_check->right) {
			if (node_for_check == node_for_check->parent->right) {
				node_for_check->parent->right = node_for_check->right;
			}
			else {
				node_for_check->parent->left = node_for_check->right;
			}
		}
		else {
			if (node_for_check == node_for_check->parent->left) {
				node_for_check->parent->left = NULL;
			}
			else {
				node_for_check->parent->right = NULL;
			}
		}
		free(node_for_check);
	}
}

void CheckTree(struct bn_tree* node) {
	if (node == NULL) {
		return;
	}
	if (node->left != 0) {
		CheckTree(node->left);
	}
	if (node->right != 0) {
		CheckTree(node->right);
	}
	Dedublicate(node, root);
}

void PrintTree(struct bn_tree* print, int level) {
	if (print) {
		if (print->right){
			PrintTree(print->right, level + 1);
		}
		for (int i = 0; i < level; i++) {
			printf_s("   ");
		}
		printf_s("%d\n", print->digit);
		if (print->left) {
			PrintTree(print->left, level + 1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int number = 0, count = 0;

	printf_s("Заполните дерево числами. Введя число, нажмите enter. Для завершения ввода введите 0.\n");
	for (;;)
	{
		scanf_s("%d", &number);
		if (number == 0)
		{
			break;
		}
		else{
			root = AddNode(number, root, root);
			count++;
		}
	}
	PrintTree(root, count);
	CheckTree(root);
	PrintTree(root, count);
	DeleteTree(root);
	return 0;
}

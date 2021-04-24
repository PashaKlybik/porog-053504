#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define MAXWORD 100

struct tnode
{   
    int number;
    struct tnode* left;
    struct tnode* right;
    struct tnode* parent;
};

struct tnode* root = NULL;

struct tnode* addnode(int x, struct tnode* node, struct tnode* parent)
{
    if (node == NULL)
    {
        node = new tnode;
        node->number = x;
        node->left = NULL;
        node->right = NULL;
        node->parent = parent;
    }
    else
    {
        if (x < node->number)
            node->left = addnode(x, node->left, node);
        else
            node->right = addnode(x, node->right, node);
    }

    return(node);
}

void freemem(tnode* tree) 
{
    if (tree != NULL) 
    {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}


struct tnode* findMaxNode(tnode* node) 
{
    while (node->right) {
        node = node->right;
    }
    return (node);
}

void deduplicate(tnode* origin_node, tnode* node_to_check)
{
    if (node_to_check == NULL && origin_node == NULL)
        return;

    if (node_to_check->left != 0)
        deduplicate(origin_node, node_to_check->left);
    if (node_to_check->right != 0)
        deduplicate(origin_node, node_to_check->right);

    if(node_to_check->number == origin_node->number && node_to_check != origin_node)
    {
        printf("Найден дубликат %d\n", node_to_check->number);

        if (node_to_check->left && node_to_check->right) {
            tnode* localMax = findMaxNode(node_to_check->left);
            node_to_check->number = localMax->number;
            deduplicate(origin_node, localMax);
            return;
        }
        else if (node_to_check->left) {
            if (node_to_check == node_to_check->parent->left) {
                node_to_check->parent->left = node_to_check->left;
            }
            else {
                node_to_check->parent->right = node_to_check->left;
            }
        }
        else if (node_to_check->right) {

            if (node_to_check == node_to_check->parent->right) {
                node_to_check->parent->right = node_to_check->right;
            }
            else {
                node_to_check->parent->left = node_to_check->right;
            }
        }
        else {

            if (node_to_check == node_to_check->parent->left) {
                node_to_check->parent->left = NULL;
            }
            else {
                node_to_check->parent->right = NULL;
            }
        }
        free(node_to_check);
    }
}

void treecheck(tnode* node)
{
    if (node == NULL)
        return;

    if (node->left != 0)
        treecheck(node->left);
    if(node->right != 0)
        treecheck(node->right);

    deduplicate(node, root);
}

void treeprint(struct tnode* p, int level) 
{
    if (p)
    {
        if(p->right)
        treeprint(p->right, level + 1);
        for (int i = 0; i < level; i++) printf_s("   ");
        printf_s("%d\n", p->number);
        if(p->left)
        treeprint(p->left, level + 1);
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");

    int number = 0;
    int count = 0;

    printf_s("Заполните дерево числами. Введя число, нажмите enter. Для завершения ввода введите 0.\n");
    for(;;)
    {
        scanf_s("%d", &number);
        if(number == 0)
        {
            break;
        }
        root = addnode(number, root, root);
        count++;

    }
    
    treeprint(root, count);
    treecheck(root);
    treeprint(root, count);
    freemem(root);
    
    return 0;
}
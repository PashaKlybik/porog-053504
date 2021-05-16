//Дан связный список, элементы которого содержат целые числа.
//Сформировать на основе списка бинарное дерево поиска.
//Разработать функцию удаления из дерева всех узлов, содержащих
//отрицательные значения.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_TEXT_SIZE 256

typedef struct ListNode {
    int value;
    struct Node *next;
} ListNode;

typedef struct TreeNode         //Node structure
{
    struct TreeNode *left;
    struct TreeNode *right;
    int value;
} TreeNode;

void push(ListNode **head, int data) {
    ListNode *tmp = (ListNode*) malloc(sizeof(ListNode));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}
int pop(ListNode **head) {
    ListNode* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void fromArray(ListNode **head, int *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}


void printLinkedList(const ListNode *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
void deleteList(ListNode **head) {
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

struct TreeNode* CreateNode(int number) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node)
        exit(1);
    node->value = number;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* Addtree(struct TreeNode* root, int number){
    if (!root) {
        return CreateNode(number);
    }
    TreeNode *temp = root;
    while (1) {
        if (number == temp->value) {
            return root;           //if number exist in tree, does nothing
        }
        if (number < temp->value) {
            if (temp->left) {
                temp = temp->left;
            }
            else {
                temp->left = CreateNode(number);
                return root;
            }
        }
        else {
            if (temp->right) {
                temp = temp->right;
            }
            else {
                temp->right = CreateNode(number);
                return root;
            }
        }
    }
}
void traverse_direct(TreeNode *root) {  //in-order traverse of a tree
    if (!root)                           //prints all contained symbols
        return;
    int num = root->value;
    if(num!=0) {
        printf("%d",num);
        putchar(' ');
    }
    if (root->left) {
        traverse_direct(root->left);
    }
    if (root->right) {
        traverse_direct(root->right);
    }
}
void clear(TreeNode *root) {     //clears a tree
    if (!root)
        return;
    clear(root->left);
    clear(root->right);
    free(root);

}
void DeleteNegNumbers(TreeNode *root){
    int num = 0;
    if (!root)                           //prints all contained symbols
        return;
    while(root->value < 0)
    {
        clear(root->left);
        root->left = NULL;
        root->value = NULL;
        if(root->right)
            root = root->right;
    }
    if (root->left) {
        if(root->left->value < 0)
        {
            clear((root->left)->left);
            (root->left)->left = NULL;
            if((root->left)->right)
                root->left = (root->left)->right;
            else
            {
                clear(root->left);
                root->left = NULL;
            }
        }
        DeleteNegNumbers(root->left);
        DeleteNegNumbers(root->right);
    }
    if (root->right) {
        if(root->right->value < 0)
        {
            clear((root->left)->left);
            (root->left)->left = NULL;
            root->right = (root->right)->right;
        }
        DeleteNegNumbers(root->left);
        DeleteNegNumbers(root->right);
    }
}

int main() {
    TreeNode *root = NULL;
    ListNode* head = NULL;
    int arr[] = {20,4,-1,-3,3,-10,6,-5,-9};
    fromArray(&head, arr, 9);
    printf("Tree in direct traverse:\n");
    printLinkedList(head);
    while(head){
        root=Addtree(root,head->value);
        head = head->next;
    }
    DeleteNegNumbers(root);
    printf("Tree without negative numbers:\n");
    traverse_direct(root);
    deleteList(&head);
    getchar();
}



#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* left, *right;
}Node;

Node* putNode(char* data);
char* inputWord();
void insert(Node** node, char* data);
void enterTree(Node** tree);
int palindrome(char* str);
void showPalindromes(Node* root);
void deleteTree(Node** root);
void menu(Node* root);


int main() {
    Node* root = NULL;
    menu(root);
}

void menu(Node* root) {
    int choice;
    putchar('\n');
    while(1) {
        printf("\n1: Enter tree.\n");
        printf("2: Show palindromes.\n");
        printf("3: Exit.\n\n");
        printf("Choice:");
        scanf("%d", &choice);
        if (choice) {
            switch (choice) {
                case 1:
                    enterTree(&root);
                    break;
                case 2:
                    if (root) {
                        printf("\nPalindromes:");
                        showPalindromes(root);
                        printf("\n");
                    }
                    else {
                        printf("Tree is empty!\n");
                    }
                    break;
                case 3:
                    deleteTree(&root);

                    return;
                default:
                    printf("There is no such option!\n");
                    break;
            }
        }
        else {
            rewind(stdin);
            printf("Incorrect input!\n");
        }
    }
}
Node* putNode(char* data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = (char*)malloc(strlen(data));
    strcpy(tmp->data, data);
    return tmp;
}

char* inputWord() {
    char* str = (char*)malloc(sizeof(char));
    int i = 0;
    while ((str[i] = getchar()) != '\n') {
        if (str[i] == ' ')
            break;
        str = (char*)realloc(str, (++i + 1) * sizeof(char));
    }
    str[i] = '\0';
    return str;
}

void insert(Node** node, char* data) {
    Node* tmp;
    if (*node == NULL) {
        *node = putNode(data);
        return;
    }
    tmp = *node;
    while (tmp) {
        if (strcmp(data, tmp->data) > 0) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            }
            else {
                tmp->right = putNode(data);
                return;
            }
        }
        else if (strcmp(data, tmp->data) < 0) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            }
            else {
                tmp->left = putNode(data);
                return;
            }
        }
        else {
            printf("Word '%s' can't be inserted in tree!\n", data);
            return;
        }
    }
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void enterTree(Node** tree) {
    char* word;
    while (1) {
        printf("\n");
        printf("Enter word:");
        rewind(stdin);
        word = inputWord();
        if (!strcmp(word, "end")) {
            return;
        }
        insert(tree, word);
        free(word);
    }
}

int palindrome(char* str) {
    char* reversed = (char*)malloc(strlen(str) * sizeof(char));
    strcpy(reversed, str);
    strrev(reversed);
    int a = !strcmp(str, reversed);
    free(reversed);
    return a;
}

void showPalindromes(Node* root) {
    if (root) {
        showPalindromes(root->left);
        if (palindrome(root->data)) {
            printf("\n%s", root->data);
        }
        showPalindromes(root->right);
    }
}

void deleteTree(Node** root) {
    if (*root == NULL) return;

    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);
    (*root)->left = (*root)->right = NULL;
    *root = NULL;
    free(*root);
}
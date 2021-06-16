#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct node {
    char* text;
    struct node* left_child, * right_child;
} Node;

void addBranch(Node* node, char* text, int m);
void changeBranch(Node** node, char s, int m);
char* createText(Node* node, char s, int m);
void deleteTree(Node* node);
void displayPreOrder(Node* node);

int main()
{
    FILE* fp = fopen("text.txt", "r");
    int n, m;
    Node* root = malloc(sizeof(Node));
    root->left_child = NULL;
    root->right_child = NULL;
    fscanf(fp, "%d %d", &n, &m);
    root->text = NULL;
    char* buffer = malloc((m + 2) * sizeof(char));
    fgets(buffer, m, fp);
    for (int i = 0; i < n; i++)
    {
        fgets(buffer, m + 2, fp);
        addBranch(root, buffer, m);
    }
    displayPreOrder(root);
    fclose(fp);
    deleteTree(root);
    return 0;
}

char* createText(Node* node, char s, int m)
{
    int text_size = 2;
    if (node->text != NULL)
        text_size += strlen(node->text);
    char* res = malloc(text_size * sizeof(char));
    res[text_size - 1] = '\0';
    res[text_size - 2] = s;
    int pos = text_size - 3;
    while (pos >= 0)
    {
        if (node->text != NULL)
        {
            for (int i = strlen(node->text) - 1; i >= 0 && pos >= 0; i--)
            {
                res[pos--] = node->text[i];
            }
        }
        if (pos < 0)
            break;
        res[pos--] = '0';
    }
    return res;
}

void changeBranch(Node** node, char s, int m)
{
    if (s == '\n')
        return;
    if (s == '0')
    {
        if ((*node)->left_child == NULL) {
            (*node)->left_child = malloc(sizeof(Node));
            (*node)->left_child->text = createText(*node, s, m);
            (*node)->left_child->left_child = NULL;
            (*node)->left_child->right_child = NULL;
        }
        *node = (*node)->left_child;
    }
    else
    {
        if ((*node)->right_child == NULL) {
            (*node)->right_child = malloc(sizeof(Node));
            (*node)->right_child->text = createText(*node, s, m);
            (*node)->right_child->left_child = NULL;
            (*node)->right_child->right_child = NULL;
        }
        *node = (*node)->right_child;
    }
}
void addBranch(Node* node, char* text, int m)
{
    Node* currentNode = node;
    for (int i = 0; i < strlen(text); i++)
    {
        changeBranch(&currentNode, text[i], m);
    }
}
void displayPreOrder(Node* node)
{
    if (node == NULL) return;
    if (node->text == NULL)
        printf("root node.\n");
    else
        printf("%s\n", node->text);

    displayPreOrder(node->left_child);
    displayPreOrder(node->right_child);

}

void deleteTree(Node* node)
{
    if (node == NULL)
        return;
    if (node->left_child != NULL)
        deleteTree(node->left_child);
    if (node->right_child != NULL)
        deleteTree(node->right_child);
    free(node->text);
    free(node);
}
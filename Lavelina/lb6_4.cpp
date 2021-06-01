//variant 4
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <fstream>

typedef struct tree
{
    int key;
    struct tree* left;
    struct tree* right;
} node;

node* Create(node* root, int key)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}
void Add(node** Node, int x)
{
    if (*Node == NULL)  
    {
        (*Node) =(node*)calloc(1, sizeof(node)); 
        (*Node)->left = (*Node)->right = NULL; 
        (*Node)->key = x; 
    }
    else 
    {           
        if (x < (*Node)->key) Add(&(*Node)->left, x);
        else Add(&(*Node)->right, x); 
    }
}
node* search(node* root, int key)
{
    
    if ((root == NULL) || (root->key = key))
        return root;
    
    if (key < root->key)
        return search(root->left, key);
    else return search(root->right, key);
}
void SortBubble(int mass[], int k)
{
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (mass[i] > mass[i + 1])
            {
                flag = 1;
                int tmp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = tmp;
            }
        }
    }
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (root->key)
        printf("%d ", root->key);
    inorder(root->right);
}

int get(node* node, int n, int c)
{
    if (n == c)  return 1;
    return ((node->left) ? get(node->left, n, c + 1) : 0) + ((node->right) ? get(node->right, n, c + 1) : 0);
}
void lvl(node* node) {
    int t = 0, l = 0;
    while ((l = get(node, t++, 0)) != 0) {
        printf("lvl <%d>  =  %d\n", t, l);
    }
}
int main()
{
    int s = 0, k = 0;
    FILE* f;
    f = fopen("D:\\Sem_2\\Prog-e Ñ labs\\LB6\\text_for_lab_6.txt", "r");
    while ((fscanf(f, "%d", &s) != EOF))
    {
        if (!f) break;
        k += 1;
    }
    int* c = (int*)malloc(k * sizeof(int));
    rewind(f);   
    for (int i = 0; i < k; i++)
    {
        fscanf_s(f, "%d", &c[i]);
    }
    fclose(f);
    int flag = 1;
    
    SortBubble(c, k);
    node* tree = (node*)malloc(sizeof(node));
    //root of the tree is the central member of the array
    tree = Create(tree, c[(k / 2)]);
    for (int i = 0; i < k / 2; i++)
    {
        Add(&tree, c[i]);
    }
    for (int i = k / 2 + 1; i < k; i++)
    {
        Add(&tree, c[i]);
    }
    printf("Traverse print of the tree:\n\n");
    inorder(tree);
    printf("\n\nNodes on each level:\n\n");
    lvl(tree);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

int k = 0;
int i = 0;
int a[100];
struct tnode {                
    char* word;                 
    struct tnode* left;          
    struct tnode* right;         
};

struct tnode* addtree(struct tnode* p, char* w) {
    int cond;
    
    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = _strdup(w);
        p->left = p->right = NULL;
    }
    cond = strcmp(w, p->word);
    if (cond < 0)
        p->left = addtree(p->left, w);
    else if(cond > 0)
        p->right = addtree(p->right, w);
    return p;
}

void freememory(struct tnode* tree) {
    if (tree != NULL) {
        freememory(tree->left);
        freememory(tree->right);
        free(tree->word);
        free(tree);
    }
}

void treeprint(struct tnode* p,int level) {
    
    if (p != NULL) {
        treeprint(p->right, level + 1);
        for (int i = 0; i <= level; i++) printf("  ");
        printf("%s\n", p->word);
        treeprint(p->left, level + 1);
        
     }
}

void preorder(struct tnode* p)
{
    if(p != NULL)
    {
        printf("%s\n", p->word);
        preorder(p->left);
        preorder(p->right);
    }
}

int palindrom(char *s)
{
    int l, i;
    l = strlen(s);
    for (i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - 1 - i])
            return(0);
    }
    return(1);
}

void treePalindromeprint(struct tnode* p) {

    if (p != NULL) {
        treePalindromeprint(p->left);
        if(palindrom(p->word))
        printf("%s\n", p->word);
        treePalindromeprint(p->right);
        
    }
}

int main() {
    struct tnode* root;
    char word[MAXWORD];
    root = NULL;
    printf("Enter words and type 'end',when you want to stop.\n");
    do {
        scanf_s("%s", word, MAXWORD);
        if (isalpha(word[0]) && strcmp(word, "end") != 0)
            root = addtree(root, word);
    } while (strcmp(word,"end")!=0);    // условие выхода Ц ввод строик 'end'
    
    printf("\n");
    printf("Binary Tree:\n");
    treeprint(root,0);
    printf("\n");
    printf("Preorder:\n");
    preorder(root);
    printf("All palindromes in alphabetical order:\n");
    treePalindromeprint(root);
    printf("\n");
    freememory(root);
    return 0;
}

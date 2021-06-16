#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree{
    int key1;
    int key2;
    char *word;
    struct tree *left;
    struct tree *right;
} node;


void addNode(node **root, char *word);
void findPalindrom(node *root);
void deleteTree(node **root);
bool isPalindrom(char *word);

int main() {
    char *word, symbol;
    int size = 1;

    node *root = NULL;

    printf("Enter ur words:\n");
    while(strcmp(word,"end")!=0) {
        symbol=' ';
        size=1;
        word=(char*) malloc(size* sizeof(char));
        while (symbol!='\n') {
            symbol = getc(stdin);
            word = (char *) realloc(word, size * sizeof(char));
            if(symbol!='\n')
                word[size-1]=symbol;
            size++;
        }
       addNode(&root, word);
    }

    printf("Your palindromes:\n");
    findPalindrom(root);

    deleteTree(&root);
    return 0;
}

void addNode(node **root, char *word){
    int k1 = word[0], k2 = word[1];
    if ((*root)==NULL) {
        *root =(node*) calloc(1,sizeof(node));
        (*root)->word = word;
        (*root)->left = (*root)->right = NULL;
        (*root)->key1=k1;
        if (word[1]!='\0')
            (*root)->key2 = k2;
        else (*root)->key2 = 0;
    } else{
        if ((*root)->key1 > k1)
            addNode(&((*root)->left), word);
        else if((*root)->key1 < k1)
            addNode(&((*root)->right), word);
        else{
            if ((*root)->key2 > k2)
                addNode(&((*root)->left), word);
            else
                addNode(&((*root)->right), word);
        }
    }
}

bool isPalindrom(char *word){
    if(strlen(word)==3 && word[0]==word[2])
        return true;
    else for (int i = 0, j = strlen(word)-1; i < j; i++, j--) {
        if (word[i]!=word[j])
            return false;
    }
    return true;
}

void findPalindrom(node *root){
    if (root->left)
        findPalindrom(root->left);

    if (isPalindrom(root->word))
        printf("%s\n", root->word);

    if (root->right)
        findPalindrom(root->right);
}

void deleteTree(node **root){
    if((*root)!=NULL){
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free((*root)->word);
        free(*root);
    }
}
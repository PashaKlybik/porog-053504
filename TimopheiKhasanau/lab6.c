#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node{
    char word[30];
    int amount;
    struct Node *pLeft;
    struct Node *pRight;
};

struct Node * addnode(struct Node *new , struct Node *tree);
void freemem(struct Node *tree);
void treeprint(struct Node *tree);
struct Node* formTree(struct Node *tree, char **mass, int *numb, int size);
void fromFileToTree();

int main() {
    fromFileToTree();
}

struct Node * addnode(struct Node *new , struct Node *tree) {
    if (tree == NULL){
        tree = (struct Node *)malloc(1*sizeof(struct Node));
        tree->amount = new->amount;
        tree->pLeft = new->pLeft;
        tree->pRight = new->pRight;
        strcpy(tree->word, new->word);
    }
    else  if (new->amount >= tree->amount){
        tree->pRight = addnode(new, tree->pRight);
    }
    else if(new->amount < tree->amount){
        tree->pLeft = addnode(new, tree->pLeft);
    }
    return(tree);
}

void freemem(struct Node *tree) {
    if(tree!=NULL) {
        freemem(tree->pLeft);
        freemem(tree->pRight);
        free(tree);
    }
}

void treeprint(struct Node *tree) {
    if (tree!=NULL) {
        treeprint(tree->pRight);
        printf_s("[ %s: %d times]\n",tree->word, tree->amount);
        treeprint(tree->pLeft);
    }
}

struct Node* formTree(struct Node *tree, char **mass, int *numb, int size)
{
    int i = 0;
    struct Node *node = (struct Node *)malloc(size*sizeof(struct Node));
    while(i < size)
    {
        node->amount = numb[i];
        node->pRight = NULL;
        node->pLeft = NULL;
        strcpy(node->word, mass[i]);
        tree = addnode(node, tree);
        i++;
    }
    free(node);
    return tree;
}

void fromFileToTree()
{
    char str[30];
    int i = 0;
    int size = 0, amount = 0;
    int *wordAmounts;
    char **words;
    _Bool crit =1;

    FILE *test = fopen("C:\\Git_rep\\prog-053504\\TimopheiKhasanau\\testForLab6.txt","r");
    if(!test)
    {
        printf("Error open\n");
        return;
    }

    while ((str[i] = fgetc(test)) != EOF)
    {
        if(str[i] == ' ' || str[i] == ',' || str[i] == '.'
           || str[i] == ';' || str[i] == '!' || str[i] == ','
           || str[i] == '\n')
        {
            str[i] = '\0';
            for(int j = 0; j < size; j++)
            {
                if(size != 0 && strcmp(words[j], str) == 0)
                {
                    wordAmounts[j] = wordAmounts[j]++;
                    crit = 0;
                    j = size;
                }
                if(strcmp(str, " ") == 0 || strcmp(str, "") == 0)
                {
                    crit = 0;
                    j = size;
                }
            }

            if(crit == 1)
            {
                if(size == amount)
                {
                    size+=5;
                    if(amount == 0)
                    {
                        words = (char **)malloc(size*sizeof(char *));
                        for(int i = 0; i < size; i++) {
                            words[i] = (char *)malloc(30*sizeof(char));
                        }
                        wordAmounts = (int *)malloc(size*sizeof(int ));
                        for(int i = 0; i < size; i++) {
                            wordAmounts[i] = 1;
                        }
                    }
                    else
                    {
                        words = (char **)realloc(words, size*sizeof(char *));
                        for(int i = amount; i < size; i++) {
                            words[i] = (char *)malloc(30*sizeof(char));
                        }
                        wordAmounts = (int *)realloc(wordAmounts, size*sizeof(int ));
                        for(int i = amount; i < size; i++) {
                            wordAmounts[i] = 1;
                        }
                    }
                }
                strcpy(words[amount], str);
                amount++;
            }
            strcpy(str, "");
            i = 0;
            crit = 1;
        }
        else
        {
            i++;
        }
    }

    struct Node *tree = NULL;
    tree = formTree(tree, words, wordAmounts, amount);
    treeprint(tree);

    for(int i = 0; i < size; i++)
    {
        free(words[i]);
    }
    free(words);
    free(wordAmounts);
    freemem(tree);
}
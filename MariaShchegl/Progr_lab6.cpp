//без комментариев
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


/*Пользователь вводит слова с клавиатуры (ввод прекращается, когда
будет введено слово “end”). Построить бинарное дерево поиска, 
каждый узел которого содержит слово, и вывести по алфавиту те
слова, которые являются палиндромами (т.е. читаются справа
налево и слева направо одинаково). */

struct tnode {
    char* word;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* Addtree(struct tnode* p, char* w) {
    int cond;

    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = _strdup(w);
        p->left = p->right = NULL;
    }
    cond = strcmp(w, p->word);
    if (cond < 0)
        p->left = Addtree(p->left, w);
    else if (cond > 0)
        p->right = Addtree(p->right, w);
    return p;
}



void Treeprint(struct tnode* p, int level) {

    if (p != NULL) {
        Treeprint(p->right, level + 1);
        for (int i = 0; i <= level; i++) printf("  ");
        printf("%s\n", p->word);
        Treeprint(p->left, level + 1);

    }
}

void FreeMemory(struct tnode* tree) {
    if (tree != NULL) {
        FreeMemory(tree->left);
        FreeMemory(tree->right);
        free(tree->word);
        free(tree);
    }
}
void Preorder(struct tnode* p)
{
    if (p != NULL)
    {
        printf("%s\n", p->word);
        Preorder(p->left);
        Preorder(p->right);
    }
}

int Palindrom(char* s)
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

void TreePalindrome(struct tnode* p) {

    if (p != NULL) {
        TreePalindrome(p->left);
        if (Palindrom(p->word))
            printf("%s\n", p->word);
        TreePalindrome(p->right);

    }
}

int main() {
    struct tnode* root;
    char word[100];
    root = NULL;
    printf("Enter words and type 'end',when you want to stop.\n");
    do {
        scanf_s("%s", word, 100);
        if (isalpha(word[0]) && strcmp(word, "end") != 0)
            root = Addtree(root, word);
    } while (strcmp(word, "end") != 0);    

    printf("\n");
    printf("Binary Tree:\n");
    Treeprint(root, 0);
    printf("\n");
    printf("Preorder:\n");
    Preorder(root);
    printf("All palindromes in alphabetical order:\n");
    TreePalindrome(root);
    printf("\n");
    FreeMemory(root);
    return 0;
}
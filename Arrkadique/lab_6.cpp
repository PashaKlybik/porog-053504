#include <stdio.h>
#include <stdlib.h>

struct tnode {             
    char word;                  
    struct tnode* left;        
    struct tnode* right;         
};
struct tnode* addtree(struct tnode* p, char w) {
    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = w;
        p->left = p->right = NULL;
    }
    else if (w < p->word)
        p->left = addtree(p->left, w);
    else if (w > p->word)
        p->right = addtree(p->right, w);
    return p;
}
void freemem(tnode* tree) {
    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}

int mystrlen(char* arr) {
    int j = 0;
    int check = 0;
    for (int i = 0; arr[i] != 0; i++) {
        j++;
    }
    return j;
}

void treeletters(struct tnode* p, char* letter, int& count) {

    if (p != NULL) {
        treeletters(p->left, letter, count);
        if (p->word == 'a' || p->word == 'e' || p->word == 'y' || p->word == 'u' || p->word == 'o' || p->word == 'i') count++;
        treeletters(p->right, letter, count);
    }
}

void GetMassive(struct tnode* p, char* M, int& n) {
    if (p != nullptr) {
        GetMassive(p->left, M, n);
        M[n++] = p->word;
        GetMassive(p->right, M, n);
    }
}

void print(struct tnode* p, int n)
{
    if (p)
    {
        print(p->right, n + 4);
        for (int i = 0; i < n; i++)
            printf(" ");
        printf("%c\n", p->word);
        print(p->left, n + 4);
    }
}

int main() {
    struct tnode* root;
    char letter[30], buflet[30];
    int i = 0, count = 0, n = 0;
    root = NULL;
    printf("Enter your letters:\n");
    fgets(letter, 29, stdin);
    letter[mystrlen(letter)] = '\0';
    do {
        if ((letter[i] > 64 && letter[i] < 91) || (letter[i] > 96 && letter[i] < 123)) {
            if (letter[i] > 64 && letter[i] < 91) {
                letter[i] += 32;
            }
            root = addtree(root, letter[i]);
        }
        i++;
    } while (letter[i] != '\0');
    print(root, 0);
    
    GetMassive(root, buflet, n);
    buflet[n] = '\0';

    treeletters(root, letter, count);
    if (count == mystrlen(letter) - count) {
        printf("\nthere are as many vowels as consonants \n");
    }
    if (count < mystrlen(letter) - count) {
        printf("\nThere are fewer vowels than consonants \n");
    }
    if (count > mystrlen(letter) - count) {
        printf("\nThere are more vowels than consonants \n");
    }
    freemem(root);
    return 0;
}


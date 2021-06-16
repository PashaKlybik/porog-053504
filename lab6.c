#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int data;
    struct node *left;
    struct node *right;
}node;

void InOrderL(node *root){
    if(root == NULL) return;
    InOrderL(root->left);
    printf("%d ", root->data);
    InOrderL(root->right);
}
void InOrderR(node *root){
    if(root == NULL) return;
    InOrderR(root->right);
    printf("%d ", root->data);
    InOrderR(root->left);
}
void FreeTree(node *root){
    if(root == NULL) return;
    FreeTree(root->right);
    FreeTree(root->left);
    //printf("\nfreee\n");
    free(root);
}
void add(int data, node* root){
    int cases;
    if(data <= root->data) cases = 1;
    if(data > root->data) cases = 2;
    switch(cases){
    case 1:{
        //printf("left!!\n");
     if(root->left == NULL){
         //printf("\nnew\n");
         node *temp = (node*)malloc(sizeof (node));
         temp->data = data;
         temp->left = NULL;
         temp->right = NULL;
         root->left = temp;
     }
     else{
        // printf("left rec\n");
         add(data, root->left);

     }
     break;
    }
    case 2:{
       // printf("right!!\n");
        if(root->right == NULL){
             //printf("\nnew\n");
             node *temp = (node*)malloc(sizeof (node));
             temp->left = NULL;
             temp->right = NULL;
             temp->data = data;
             root->right = temp;
        }
        else{
            // printf("right rec\n");
             add(data, root->right);

        }
        break;
    }
    }
}
int main()
{
    char arr[300];
    printf("Enter numbers: \n");
    gets(arr);
    printf("%s\n" , arr);
    int flag = 0;
    int i = 0;
    int amount = 0;
    while(arr[i] != '\0'){
        if((arr[i] >= 48) && (arr[i] <= 57)){
            i++;
            flag = 1;
        }
        else{
            i++;
            if(flag){
                flag = 0;
                amount++;
            }
        }
        if(arr[i+1] =='\0' && flag) {
            amount++;
            flag = 0;
            break;
        }
    }
    if(amount == 0) {
        printf("\nNumbers not found!!!\n");
        return 0;
    }
    int d[amount];
    int num = 0;
    char temp[30];
    i = 0;
    int j = 0;
    int mas = 0;
    int flajok = 0;
    while(arr[i] != '\0'){
        if(arr[i+1] == '\0' && flajok == 0){
            arr[i+1]=' ';
            arr[i+2] ='\0';
            flajok = 1;
        }
        if((arr[i] >= 48) && (arr[i] <= 57)){
            temp[j] = arr[i];
            j++;
            i++;
            flag = 1;
        }
        else{
            i++;
            temp[j] ='\0';
            if(flag){
                flag = 0;
                int size = 0;
                int num = 0;
                while(temp[size]!='\0') size++;
                for(int i = size-1, j = 0; i >= 0; i-- , j++){
                    num += (temp[j] - 48) * powl(10, i);
                }
                //printf("\ntest:%d\n", num);
                d[mas] = num;
                mas++;
                j = 0;
            }
        }
    }
  //  printf("amount %d\n", amount);
    printf("Your numbers: \n");
    for(int i = 0; i < amount; i++){
        printf("%d\n", d[i]);
    }

    node *root = (node*)malloc(sizeof (node));
    root->left = NULL;
    root->right = NULL;
    root->data = d[0];
    for(int i = 1; i < amount; i++){
        add(d[i], root);
    }

    printf("\nInOrderL\n");
    InOrderL(root);
    printf("\nInOrderR\n");
    InOrderR(root);
    FreeTree(root);
    return 0;
}

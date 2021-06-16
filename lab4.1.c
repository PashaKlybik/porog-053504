#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
int CheckSim(char arr1[], char arr2[] );
int main()
{
    setlocale(LC_ALL, "Rus");
 const int size = 200;
 char arr[size];
 char **data = (char**)malloc(sizeof(char*)*size);
 for(int i = 0; i < size ; i++){
     data[i] = (char*)malloc(sizeof(char)*200);
 }
 printf("Enter text (max200): \n");
 fgets(arr, size, stdin);
// printf("%s", arr);
 int i = 0;
 int k = 0;
 int j = 0;
 int words = 0;
 int flag = 0;
 while(arr[i] != '\0'){
     if( ((int)arr[i] >= 97 && (int)arr[i] <= 122) || ((int)arr[i] >= 65 && (int)arr[i] <= 90)){
         flag = 1;
         data[k][j] = arr[i];
         j++;
         //printf("test\n");
     }
     else{
         data[k][j] = '\0';
         j = 0;
         if(flag == 1){
            k++;
            words++;
            flag = 0;
         }
     }
     i++;
 }
printf("************************************\n");
char **temp = (char**)malloc(sizeof(char*)*words);
for(int i = 0; i < words ; i++){
    temp[i] = (char*)malloc(sizeof(char)*200);
}
int chek_val = 0;
////////////////////////////////////////////////
for(int i = 0, k = 0; i < words; i++){
    int flajocheck = 1;
    for(int f = 0; f < chek_val; f++){
        if(CheckSim(data[i], temp[f])) flajocheck = 0;
    }
    if(flajocheck == 1){
    for(int j = i; j < words; j++){
        if(CheckSim(data[i], data[j])){
            k++;
        }
        if(j == words - 1){
            temp[chek_val] = data[i];
            chek_val++;
        }
    }

    printf("%s: %d \n", data[i], k);
    k = 0;
    }

}

for(int i = 0; i < size; i++){
    free(data[i]);
}
free(data);
for(int k = 0; k < words; k++){
        //free(temp[1]);
}
free(temp);
    printf("************************************\n");
    return 0;
}

int CheckSim(char arr1[], char arr2[] ){
    int size_1 = 0;
    int size_2 = 0;
    int max_size = 0;
    int check = 0;
    while(arr1[size_1]!='\0') size_1++;
    while(arr2[size_2]!='\0') size_2++;
    if(size_1 > size_2){
        max_size = size_1;
    }
    else{
        max_size = size_2;
    }
    for(int i = 0; i < max_size; i++){
        if(arr1[i] == arr2[i]) check++;
    }
    if(check == max_size) return 1;
    else return 0;
}

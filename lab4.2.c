#include <stdio.h>
#include <stdlib.h>
int CheckSim(char arr1[], char arr2[] );
int main()
{
    FILE *f;
    f= fopen("test.txt", "r");
    int words = 0;
    const int lenght = 200;
    int i = 0;
    char arr[lenght];
    //*****schitaet slova dlya massiva**********
    while(!feof(f)){
        i = 0;
        fgets(arr, lenght, f);
        printf("%s",arr);
        int flag = 0;
        while(arr[i] != '\0'){
            if( ((int)arr[i] >= 97 && (int)arr[i] <= 122) || ((int)arr[i] >= 65 && (int)arr[i] <= 90)){
                i++;
                flag = 1;
            }
            else{
                i++;
                if(arr[i]=='\n') words++;
                if(flag){
                    flag = 0;
                    words++;
                }
            }
        }
    }
    printf("\nwords: %d", words);
    ////////////////////////////////////////////////////
     char **data = (char**)malloc(sizeof(char*)*words);
     for(int i = 0; i < words; i++){
         data[i] = (char*)malloc(sizeof (char) * 100);
     }
     fclose(f);
     f= fopen("test.txt", "r");


     int k = 0;
     while(!feof(f)){
         i = 0;
         int j = 0;
         int flag = 0;
         char temp[lenght];
         fgets(temp, lenght, f);
     while(temp[i] != '\0'){
         if( ((int)temp[i] >= 97 && (int)temp[i] <= 122) || ((int)temp[i] >= 65 && (int)temp[i] <= 90)){
             flag = 1;
             data[k][j] = temp[i];
             j++;
         }
         else{
             data[k][j] = '\0';
             j = 0;

             if(flag == 1){
                k++;
                flag = 0;
             }
         }
         i++;
     }
     }
      printf("\n******************************\n");
     for(int i = 0; i < words; i++){
         int size = 0;
         int check = 0;
         int echeck = 0;
         while(data[i][size]!=0){
             size++;
         }
         if(size%2 == 0) echeck = size/2;
         else echeck = (size-1)/2 + 1;
         for(int j = 0, s = size-1; j < echeck; j++, s--){
             if(((int)data[i][j] + 32 == (int)data[i][s])|| ((int)data[i][j] == (int)data[i][s] + 32) ||
                     (int)data[i][j]  == (int)data[i][s]) check++;
             //printf("\n%d %d \n", i , check);
         }
         if (check == echeck && size >= 3){
             printf("%s\n", data[i]);
         }
     }
     printf("***********************************\n");
     ///////////////////////////////////

    for(int i = 0; i < words; i++){
        char temp[words*50];
        for(int z = words; z >= 0;z--){
            int m = 0;
      for(int j = i; j < z; j++){
          int u = 0;
          while(data[j][u]!='\0'){
             temp[m] = data[j][u];
             m++;
             u++;
          }
          temp[m] = '\0';
      }

        int size = 0;
        while(temp[size]!='\0') size++;
       // printf(" size: %d \n", size);
        char sravn[size];
      // printf("\n");
        for(int w = 0, n = size-1; w <= size; w++, n--){
            sravn[w] = temp[n];
            sravn[w+1] = '\0';
        }
       if(CheckSim(sravn, temp) && size >= 10) printf("%s\n", sravn);
}

        //printf("\n");

     }
    printf("****************************************\n");
     ///////////////////////////////////
     for(int i = 0; i < words; i++){
         free(data[i]);
     }
     free(data);
    fclose(f);
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
        if(((int)arr1[i] + 32 == (int)arr2[i])|| ((int)arr1[i] == (int)arr2[i] + 32) ||
                (int)arr1[i] == (int)arr2[i]) check++;
    }
    if(check == max_size) return 1;
    else return 0;
}


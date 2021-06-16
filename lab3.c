#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
int filter(int **mas, int a, int b);
void sort_zao(int **mas, int a ,int b);
int main()
{
    srand(time(NULL));
    int a = 20;
    int b = 5;
    int **mas = malloc(sizeof(int*)*a);
    for(int i = 0; i < a; i++){
        mas[i] = (int*)malloc(sizeof(int)*b);
    }
    for(int i = 0; i < a; i++){
        for(int j =0; j < b; j++){
            mas[i][j] = rand() % 2;
        }
    }
    printf("********************\n");
    printf("****STANDART*******\n");

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }


    a = filter(mas, a, b);
    printf("********************\n");
    printf("****FILTR**********\n");
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }

    sort_zao(mas, a, b);

     printf("********************\n");
     printf("********SORRT*******\n");
     for(int i = 0; i < a; i++){
         for(int j = 0; j < b; j++){
             printf("%d ", mas[i][j]);
         }
         printf("\n");
     }
    ///////////////////////////
    for(int i = 0 ; i < b; i++){
        free(mas[i]);
    }
    free(mas);

    ///////////////////////////
    return 0;
}


int filter(int **mas, int a ,int b){
    for(int i = 0; i < a; i++){
        int it = 0;
        if(it){
        it = 0;
        i=0;
        }
            for(int k = i+1; k < a; k++){
                int check = 0;
                for(int j = 0; j < b; j++){
                    if(mas[i][j] == mas[k][j]){
                        check++;
                    }
                }
                if(check == b){
                    a--;
                    it = 1;
                    for(int m = k; m < a; m++){
                        for(int t = 0; t < b;t++){
                            mas[m][t] = mas[m+1][t];
                        }
                    }
                }
            }
        }

    return a;
}

void sort_zao(int **mas, int a ,int b){
    int shag = 0;
    if(a%2 == 0){
    shag = a/2;
    }
    else shag = (a-1)/2;
    while(shag){
        int i = 0;
       while((i + shag) < a){
           int x =0, y =0;
           for(int j = 0, m = b-1 ; j < b; j++, m--){
             x += mas[i][j] * pow(10,m);
             y += mas[i + shag][j] * pow(10,m);
           }
           if(x > y){
               for(int t = 0; t < b; t++){
                  int buf = 0;
                  buf = mas[i+shag][t];
                  mas[i+shag][t] = mas[i][t];
                  mas[i][t] = buf;

                }
           }

           i++;
       }
        shag--;
    }
}

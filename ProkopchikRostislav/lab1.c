#include <stdio.h>
#include <math.h>
int main(){
        for(int i = 100; i<1000 ; i++){
            int temp = i;
            int des;
            int ed;
            int sot;
            ed  = temp % 10;
            temp -= ed;
            des = temp % 100;
            temp -= des;
            des = des / 10;
            sot = temp / 100;
           // printf("********");
            int sum = pow(des,3)+ pow(ed, 3) + pow(sot,3);
            if(sum == i){
                printf("\n");
                printf("********\n");
                printf("%d^3 + %d^3 + %d^3 = %d\n", sot, des,ed,i);
                printf("%d + %d + %d = %d\n", sot * sot* sot  , des*des*des , ed*ed*ed, i);
                printf("%d", i);
                printf("\n");
            }
            //printf("\n" );
            //printf("%d", sot );
            //printf("\n" );
            //printf("%d", des );
            //printf("\n" );
            //printf("%d", ed );
            //printf("\n" );
        }
        return 0;
}

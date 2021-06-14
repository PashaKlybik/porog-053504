#include <stdio.h>
#include<malloc.h>

void rus(int* a);
void eng(int* a);
void inf();
int* input();
int Check(int* a);


int main()
{
    int ch = 0, check;
    int* a;
  
    a = (int*)malloc(4 * sizeof(int));
m1:
    printf("1.transfer\n2.information\n0.exit\n");
    scanf_s("%d", &ch);
    switch (ch) {
    case 1:
        a = input();
        check = Check(a);
        if (check == 1)
            break;
        else {
            printf("Select in which number system:\n1-Russian traditional\n2-English traditional:\n");
            scanf_s("%d", &ch);
            switch (ch) {
            case 1:rus(a); break;
            case 2:eng(a); break;
            default:printf("*I CAN'T DO IT*\nyou selected a non-existent runt.\n"); break;
            }
            break;
        }
    case 2: inf(); break;
    case 0: free(a); return 0;
    default:printf("*I CAN'T DO IT*\nyou selected a non-existent runt.\n"); break;
    }
    goto m1;

}

void rus(int* a) {
    float versta, sagen, arshina, vershok;
    float zn = a[0] * 1000000 + a[1] * 1000 + a[2] * 10 + a[3];
    
    vershok = zn / 44.45;
    arshina =(int)vershok / 16;
    vershok -= (int)arshina * 16;
    sagen = (int)arshina / 3;
    arshina -= (int)sagen * 3;
    versta = (int)sagen / 500;
    sagen -= (int)versta * 500;
    printf("versta = %f\nsagen = %f\narshina = %f\nvershok = %f\n\n", versta, sagen, arshina, vershok);
}

void eng(int* a) {
    float mil, yard, fut, duym;
    float zn = a[0] * 100000 + a[1] * 100 + a[2] + a[3] / 10.0;
 
    duym = zn / 2.54;
    fut = (int)(duym / 12);
    duym -= (int)fut * 12;
    yard = (int)fut / 3;
    fut -= (int)yard * 3;
    mil = (int)yard / 1760;
    yard -= (int)mil * 1760;
    printf("mil = %f\nyard = %f\nfut = %f\nduym = %f\n\n", mil, yard, fut, duym);
}

void inf() {
    printf("\nArseniy Novikov, group 053504, version 1.0\n\n");
}

int* input() {
    int* a;
    a = (int*)malloc(4 * sizeof(int));
    printf("\nEnter an integer.\n");
    printf("Enter km: ");
    scanf_s("%d", &a[0]);
    printf("Enter m: ");
    scanf_s("%d", &a[1]);
    printf("Enter sm: ");
    scanf_s("%d", &a[2]);
    printf("Enter mm: ");
    scanf_s("%d", &a[3]);

    if (a[3] >= 10) {
        a[2] += a[3] / 10;
        a[3] -= a[3] / 10 * 10;
    }
    if (a[2] >= 100) {
        a[1] += a[2] / 100;
        a[2] -= a[2] / 100 * 100;
    }
    if (a[1] >= 1000) {
        a[0] += a[1] / 1000;
        a[1] -= a[1] / 1000 * 1000;
    }

    return a;
}

int Check(int* a){
    for (int i = 0; i < 4; i++) {
        if (a[i] < 0) {
            printf("\nDistance cannot be negative!\n");
            return 1;
        }
    }
}
#include <stdio.h>
#define N 80

int mystrlen(char* arr) {
    int j = 0;
    int check = 0;
    for (int i = 0; arr[i] != 0; i++) {
        j++;
    }
    return j;
}

int main() {
    FILE* file;
    char arr[N];
    int i = 0;

    fopen_s(&file, "fscanf.txt", "r");

    while ((arr[i] = fgetc(file)) != EOF) {
        if (arr[i] == '\n' || arr [i] == ' ') {
            arr[i] = '\0';
            printf("\n%s\n", arr);
            for (int j = 0; j < mystrlen(arr); j++) {
                printf("=");
            }
            printf(" %d", mystrlen(arr));
            i = 0;
        }
        else i++;
    }
    arr[i] = '\0';
    printf("\n%s\n", arr);

    fclose(file);
}
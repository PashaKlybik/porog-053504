#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STR_SIZE 80

void findCoincidences(FILE *file, char str[MAX_STR_SIZE]) {
    fseek(file, 0, SEEK_SET);
    char fileStr[MAX_STR_SIZE];
    while(fgets(fileStr, MAX_STR_SIZE, file) != NULL) {
        int isFinded = 0;
        int fileStrLength = 0;
        int searchStrLength = 0;
        for(int i = 0; i < MAX_STR_SIZE; i++) {
            if(fileStr[i] == '\0') {
                fileStrLength = i;
                break;
            }
        }
        for(int i = 0; i < MAX_STR_SIZE; i++) {
            if(str[i] == '\0') {
                searchStrLength = i-1;
                break;
            }
        }
        for(int i = 0; i < fileStrLength; i++) {
            for(int j = 0; j < searchStrLength; j++) {
                if(fileStr[i+j] != str[j]) {
                    isFinded = 0;
                    break;
                }
                else {
                    isFinded = 1;
                }
            }
            if(isFinded) {
                printf("FINDED=%s", fileStr);
            }
        }
    }
}

int main() {
    FILE *file = fopen("dataLab4.txt","r");

    char str[MAX_STR_SIZE];

    while(1) {
        printf("Type your string: \n");
        fgets(str, MAX_STR_SIZE, stdin);
        printf("There is results of search:\n");
        findCoincidences(file, str);
    }

    fclose(file);

	return 0;
}

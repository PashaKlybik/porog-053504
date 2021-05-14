#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

void encryption (char **array, int size, char *string, char *encryptedString);
void decryption (char *encryptedString, int size, char **array, char *decryptedString);

int main() {
    //create a string and allocate memory for it
    char* str, c;
    int i = 0, j = 1;
    str = malloc(sizeof(char));
    printf("->");
    while (c != '\n') {
        c = getc(stdin);
        str = (char*) realloc(str, j * sizeof(char));
        str[i] = c;
        j++;
        i++;
    }
    str[strlen(str)-1] = '\0';
    printf("\n");

    //create a size variable for matrix
    int N = sqrt(strlen(str));
    if (N * N <= strlen(str)) {
        ++N;
    }

    char **arr = (char**) malloc(N * sizeof(char*));
    for (int i = 0; i < N; ++i) {
        arr[i] = (char*) malloc(N * sizeof(char));
    }

    //encrypted string
    char *encryptedStr = malloc(sizeof(char) * N * N);
    encryption(arr, N, str, encryptedStr);
    printf("Encrypted string: ");
    for (int i = 0; i < N*N; ++i) {
        printf("%c", encryptedStr[i]);
    }
    printf("\n");

    //decrypted string
    char *decryptedStr = malloc(sizeof(char) * N * N);
    decryption(encryptedStr, N, arr, decryptedStr);
    printf("\nDecrypted string: ");
    for (int i = 0; i < N*N; ++i) {
        printf("%c",decryptedStr[i]);
    }
    printf("\n");

    //free the memory
    for (int i = 0; i < N; ++i) {
        free(arr[i]);
    }
    free(arr);
    free(str);
    free(encryptedStr);
    free(decryptedStr);
    return 0;
}

void encryption (char **array, int size, char *string, char *encryptedString) {
    int counter = 0;
    for (int t = 0; t < (size + 1) / 2; ++t) {
        for (int i = t; i < size - t; ++i) {
            if (counter <= strlen(string)) array[i][t] = string[counter++];
            else array[i][t] = ' ';
        }
        for (int j = t + 1; j < size - t; ++j) {
            if (counter <= strlen(string)) array[size - t - 1][j] = string[counter++];
            else array[size - t - 1][j] = ' ';
        }
        for (int i = size - t - 2; i >= t ; --i) {
            if (counter <= strlen(string)) array[i][size - t - 1] = string[counter++];
            else array[i][size - t - 1] = ' ';
        }
        for (int j = size - t - 2; j > t; --j) {
            if (counter <= strlen(string)) array[t][j] = string[counter++];
            else array[t][j] = ' ';
        }
    }
    counter = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            encryptedString[counter++] = array[i][j];
        }
    }
}

void decryption (char *encryptedString, int size, char **array, char *decryptedString) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            array[i][j] = encryptedString[counter++];
        }
    }
    counter = 0;
    for (int t = 0; t < (size + 1) / 2; ++t) {
        for (int i = t; i < size - t; ++i) {
            decryptedString[counter++] = array[i][t];
        }
        for (int j = t + 1; j < size - t; ++j) {
            decryptedString[counter++] = array[size - t - 1][j];
        }
        for (int i = size - t - 2; i >= t ; --i) {
            decryptedString[counter++] = array[i][size - t - 1];
        }
        for (int j = size - t - 2; j > t; --j) {
            decryptedString[counter++] = array[t][j];
        }
    }
}

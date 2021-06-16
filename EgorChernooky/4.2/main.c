#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 80
#define FILE_PATH "/home/egor/CLionProjects/lab42/text.txt"

int size(char* s);

int main()
{
    FILE* file;
    char** str;

    //allocate memory for array
    str = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++) {
        str[i] = (char*)malloc(MAX_SIZE * sizeof(char));
    }

    file = fopen(FILE_PATH, "r+");

    //counting number of strings
    int counter = 0;
    while (!feof(file)) {
        fgets(str[counter], MAX_SIZE, file);
        ++counter;
    }

    //add spaces to each line
    rewind(file);
    int add;
    for (int i = 0; i < counter; ++i) {
        add = size(str[i]);
        add = (MAX_SIZE - add) / 2;
        for (int j = 0; j < add; j++) {
            fputc(' ', file);
        }
        fputs(str[i], file);
    }

    //memory cleaning
    for (int i = 0; i < 100; i++) {
        str[i] = NULL;
        free(str[i]);
    }
    str = NULL;
    free(str);
    fclose(file);
    return 0;
}

int size(char* s) {
    int counter = 0;
    while (s[counter] != '\0') {
        ++counter;
    }
    return counter;
}
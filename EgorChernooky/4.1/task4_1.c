#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 80

void enterText(FILE* f);

int main() {
    FILE* file = (FILE *) ("text.txt", "w+");
    enterText(file);
    return 0;
}

int isEqual(char* s1, char* s2) {
    int x = 0, y = 0;
    while(s1[x] != '\0') {
        if (s1[x] != s2[y]) return 0;
        ++x;
        ++y;
    }
    return 1;
}

void enterText(FILE* f) {
    printf("If you want to stop writing enter 'end'.");
    while(1) {
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
        if (isEqual(str, "end")) return;
        fprintf(f, "%s", str);
        free(str);
    }
}
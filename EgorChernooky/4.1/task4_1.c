#include <stdio.h>
#include <malloc.h>

#define X1 3
#define X2 3
#define Y1 5
#define Y2 3

char* toUpper(char* string);
char* toLower(char* string);
int size(const char* s);
void output(char** a, char** b);
void input(char** a, char** b);
void editArrays(char** a, char** b);
void delete(char*** a, char*** b);

int main() {
    char** A = (char**) malloc(sizeof(char) * X1);
    char** B = (char**) malloc(sizeof(char) * X2);
    for (int i = 0; i < X1; ++i) {
        A[i] = (char*) malloc(sizeof(char) * Y1);
        B[i] = (char*) malloc(sizeof(char) * Y2);
    }

    input(A, B);
    editArrays(A, B);
    output(A, B);
    delete(&A, &B);

    return 0;
}

int size(const char* s){
    int counter = 0;
    while (s[counter])
    {
        ++counter;
    }
    return counter;
}

char* toUpper(char* string) {
    for (int i = 0; i < size(string); ++i) {
        if (string[i] > 96 && string[i] < 123) {
            string[i] -= 32;
        } else {
            continue;
        }
    }
    return string;
}

char* toLower(char* string) {
    for (int i = 0; i < size(string); ++i) {
        if (string[i] > 64 && string[i] < 91) {
            string[i] += 32;
        } else {
            continue;
        }
    }
    return string;
}

void output(char** a, char** b) {
    printf("\n");
    for (int i = 0; i < X1; ++i) {
        for (int j = 0; j < Y1; ++j) {
            printf("%c", a[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < Y2; ++j) {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }
}

void input(char** a, char** b) {
    printf("Fill the first array (length - 5).\n");
    for (int i = 0; i < X1; ++i) {
        char ch = 0;
        int j = 0;
        printf("Enter word: ");
        while (1) {
            ch = getc(stdin);
            if (ch == '\n') break;
            a[i][j] = ch;
            j++;
        }
    }

    printf("\nFill the second array (length - 3).\n");
    for (int i = 0; i < X2; ++i) {
        char ch = 0;
        int j = 0;
        printf("Enter word: ");
        while (1) {
            ch = getc(stdin);
            if (ch == '\n') break;
            b[i][j] = ch;
            j++;
        }
    }
}

void editArrays(char** a, char** b) {

    int counter;
    for (int i = 0; i < X1; ++i) {
        counter = 0;
        toLower(&(*a[i]));
        for (int j = 0; j < Y1; ++j) {
            for (int k = 0; k < Y1; ++k) {
                if (a[i][j] == a[i][k]) ++counter;
            }
        }
        if (counter == Y1) toUpper(&(*a[i]));
    }

    for (int i = 0; i < X2; ++i) {
        counter = 0;
        toLower(&(*b[i]));
        for (int j = 0; j < Y2; ++j) {
            for (int k = 0; k < Y2; ++k) {
                if (b[i][j] == b[i][k]) ++counter;
            }
        }
        if (counter == Y2) toUpper(&(*b[i]));
    }
}
void delete(char*** a, char*** b) {
    for (int i = 0; i < X1; ++i) {
        a[i] = NULL;
        free(a[i]);
    }
    for (int i = 0; i < X2; ++i) {
        b[i] = NULL;
        free(b[i]);
    }
    a = NULL;
    b = NULL;
    free(a);
    free(b);
}

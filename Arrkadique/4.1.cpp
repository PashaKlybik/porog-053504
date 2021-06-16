#include <stdio.h>
#include <stdlib.h>


int mystrlen(char* arr) {
    int j = 0;
    int check = 0;
    for (int i = 0; arr[i] != 0; i++) {
        j++;
    }
    return j;
}

int main() {
    system("color 0D");
    int n, m, k = 0;
    int z = 0;
    char s[70], s1[70], s2[70], sbuf1[70], sbuf2[70];
    for (int i = 0; i < 70; i++){
        s[i] = '\0';
        s1[i] = '\0';
        s2[i] = '\0';
    }
    printf("Enter the 1-st string:\n");
    fgets(sbuf1, 69, stdin);
    printf("Enter the 2-st string:\n");
    fgets(sbuf2, 69, stdin);
    for (int i = 0; i < mystrlen(sbuf1); i++) {
        if ((sbuf1[i] > 64 && sbuf1[i] < 91) || (sbuf1[i] > 96 && sbuf1[i] < 123)) {
            if (sbuf1[i] > 64 && sbuf1[i] < 91) {
                sbuf1[i] += 32;
            }
            s1[z] = sbuf1[i];
            z++;
        }
    }
    s1[z] = '\0';
    z = 0;
    for (int i = 0; i < mystrlen(sbuf2); i++) {
        if ((sbuf2[i] > 64 && sbuf2[i] < 91) || (sbuf2[i] > 96 && sbuf2[i] < 123)) {
            if (sbuf2[i] > 64 && sbuf2[i] < 91) {
                sbuf2[i] += 32;
            }
            s2[z] = sbuf2[i];
            z++;
        }
    }
    s2[z] = '\0';
    
    printf("\n");
    puts(s1);
    printf("\n");
    puts(s2);
    m = mystrlen(s1) + 1;
    n = mystrlen(s2) + 1;
    printf("1-st string: %d 2-st string: %d\n", m, n);
    int** a = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            if (s1[i - 1] == s2[j - 1])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = 0;
        }
    }
    printf("\nTarget matrix:\n\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%*d ", 5, a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 70; i++) {
        s[i] = '\0';
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] > mystrlen(s)){
                k = 0;
                s[0] = '\0';
                for (int z = i - a[i][j]; z < i; z++) {
                    s[k] = s1[z];
                    k++;
                }
            }
        }
    }
    
    printf("\nTarget substring: %s \n\n", s);
    free(a);
    return 0;
}
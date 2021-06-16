#define _CRT_SECURE_NO_WARNINGS
#define _CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#define DELIM " ,.\t\n"
/*var.5 Разнобуквица. С клавиатуры вводится многострочный текст.
Распечатать самое длинное слово, в котором все буквы разные.*/
int unique_letters(const char* s) {
    return (!*s) ? 1 : strchr(s + 1, *s) ? 0 : unique_letters(s + 1);
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    char text[1024];
    printf("Введите текст: \n");
    fgets(text, sizeof(text) - 1, stdin);
    char* ptr;
    const char* longestUnique = "";

    for (ptr = strtok(text, DELIM); ptr; ptr = strtok(NULL, DELIM))
        if (unique_letters(ptr) && strlen(ptr) > strlen(longestUnique))
            longestUnique = ptr;

    printf("%s\n", (*longestUnique) ? longestUnique : "No suitable words found.");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void replace(char* w);
bool isEndPunctMark(char symbol);
bool isPunctMark(char symbol);

int main() {

    FILE *f;
    f = fopen("/Users/katasorokina/my projects/sea4_2/text.txt","r+");
    char symbol;
    int size;

    while (1){
        char* word = (char*) malloc(35* sizeof(char));
        size=1;

        if(symbol == EOF || symbol=='\n')
            break;

        symbol = 'q';
        while(!isEndPunctMark(symbol) && !isPunctMark(symbol) && symbol!=' ' && symbol!='\n'){
            symbol = fgetc(f);
            if(!isEndPunctMark(symbol) && !isPunctMark(symbol) && symbol!=' ' && symbol!='\n'){
                word[size-1] = symbol;
                size++;
            }
        }
        word[size-1]='\0';
        replace(word);
        if (isEndPunctMark(symbol) || isPunctMark(symbol) || symbol==' ' || symbol=='\n') {
            printf("%c",symbol);
        }
    }

    return 0;
}

void replace(char* w){
    if(strcmp(w,"")==0)
        return;
    FILE *f;
    char str[50];
    f = fopen("/Users/katasorokina/my projects/sea4_2/words.txt", "r");

    char *replacedOne, *replacingOne;

    int number = 0;

    while(1){
        char *string = fgets(str, sizeof(str),f);

        if (string==NULL)
            break;

        number++;

        replacedOne = strtok(string, " ");
        replacedOne[0]=(char)tolower(replacedOne[0]);
        replacingOne = strtok(NULL, " \n");
        replacingOne[0]=(char)tolower(replacingOne[0]);

        char first = w[0];
        int j = 0;

        while(w[j]!='\0'){
            w[j]=(char)tolower(w[j]);
            j++;
        }

        if (strcmp(w,replacedOne)==0) {
            w = replacingOne;
            if(!islower(first))
                w[0]=(char)toupper(w[0]);
            fclose(f);
            printf("%s", w);
            return;
        }

        if(!islower(first))
            w[0]=(char)toupper(w[0]);
    }

    fclose(f);
    printf("%s", w);
}

bool isEndPunctMark(char symbol){
    if (symbol=='.' || symbol=='?' || symbol=='!')
        return true;
    return false;
}

bool isPunctMark(char symbol){
    if (symbol==',' || symbol==';' || symbol==':')
        return true;
    return false;
}

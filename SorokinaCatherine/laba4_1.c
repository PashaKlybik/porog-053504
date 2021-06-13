#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isEndPunctMark(char symbol);
bool isPunctMark(char symbol);
int length(char *str);

int main() {
    char* sentence[40];
    char symbol='f';
    int maxx=0, minn=10;

    printf("Enter ur text: \n");

    while (symbol!='\n'){
        int number = 0;
        symbol='f';
        while (!isEndPunctMark(symbol) && symbol!='\n'){
            int index = 0;
            symbol='a';
            char* word = (char*) malloc(30* sizeof(char));
            while (!isPunctMark(symbol) && !isEndPunctMark(symbol) && symbol!=' ' && symbol!='\n'){
                symbol = getc(stdin);
                if (!isPunctMark(symbol) && !isEndPunctMark(symbol) && symbol!=' ' && symbol!='\n') {
                    word[index]=symbol;
                    index++;
                }
            }
            if(strcmp(word,"")!=0) {
                sentence[number] = word;
                number++;
            }
            if (isPunctMark(symbol) || isEndPunctMark(symbol)) {
                sentence[number]=(char*) malloc(sizeof(char));
                sentence[number][0]=symbol;
                number++;
            }
        }
        int min = 8, max = 0, minId, maxId;
        for(int i = 0; i<number; i++){
            if(isEndPunctMark(sentence[i][0]) || isPunctMark(sentence[i][0]))
                continue;
            if(length(sentence[i])>max) {
                max=length(sentence[i]);
                maxId=i;
                if(max>maxx)
                    maxx=max;
            }
            if(length(sentence[i])<min){
                min=length(sentence[i]);
                minId=i;
                if(min<minn)
                    minn=min;
            }
        }
        char* word = sentence[maxId];
        sentence[maxId]=sentence[minId];
        sentence[minId]=word;
        if(isupper(sentence[minId][0])){
            sentence[minId][0] = (char) tolower(sentence[minId][0]);
            sentence[maxId][0] = (char) toupper(sentence[maxId][0]);
        } else if(isupper(sentence[maxId][0])){
            sentence[minId][0] = (char) toupper(sentence[minId][0]);
            sentence[maxId][0] = (char) tolower(sentence[maxId][0]);
        }

        for(int i = 0; i<number; i++){
            if (i==0 || isEndPunctMark(sentence[i][0]) || isPunctMark(sentence[i][0]))
                printf("%s", sentence[i]);
            else printf(" %s",sentence[i]);
        }
        printf(" ");

        for(int i = 0; i<number; i++){
            free(sentence[i]);
        }
    }

    printf("\nThe size of the smallest word: %d", minn);
    printf("\nThe size of the biggest word: %d", maxx);

    return 0;
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

int length(char *str){
    int i = 0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}

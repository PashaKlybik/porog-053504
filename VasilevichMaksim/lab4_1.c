#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include <string.h>
#define TEXT_SIZE 256


int main(void) {
	char* locale = setlocale(LC_ALL, "Rus");
	FILE* file = fopen("hehehe.txt", "r");
	char** text = (char**)malloc(TEXT_SIZE * sizeof(char*));
	for (int i = 0; i < TEXT_SIZE; i++) {
		text[i] = (char*)malloc(TEXT_SIZE * sizeof(char));
	}
	int amount = 0;
	while (fgets(text[amount], TEXT_SIZE, file) != NULL) {
		if(text[amount][strlen(text[amount]) - 1] == '\n') text[amount][strlen(text[amount]) - 1] = '\0';
		printf("Our text is: %s\n", text[amount]);
		amount++;
	}

	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < i; j++) {
			i--;
			char templast = text[i][strlen(text[i]) - 1];
			for (int k = 0; k < strlen(text[i])-1; k++) {
				char temp = text[i][k+1];
				text[i][k+1] = text[i][0];
				text[i][0] = temp;
			}
			text[i][0] = templast;
			i++;
		}
	}

	printf("Result:\n");
	for (int i = 0; i < amount; i++) {
		printf("%s\n", text[i]);
	}


	fclose(file);
	for (int i = 0; i < TEXT_SIZE; i++)
		free(text[i]);
	free(text);
}
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include <string.h>
#include <stdbool.h>
#define TEXT_SIZE 256

bool compareSeparator(char a) {
	if (a == ' ' || a == ',' || a == '.' || a == '?' || a == '!' || a == ';' || a == ':') return true;
	return false;
}
void compareWord(char* word, char** arr, int k, int index);
bool compareSymbols(char* a, char* b);

int main(void) {
	setlocale(LC_ALL, "Rus");
	FILE* file = fopen("hehehe.txt", "r");
	char separator[] = " .,?!;:";
	char** text = (char**)malloc(TEXT_SIZE * sizeof(char*));
	for (int i = 0; i < TEXT_SIZE; i++) {
		text[i] = (char*)malloc(TEXT_SIZE * sizeof(char));
	}
	char** words = (char**)malloc(TEXT_SIZE * sizeof(char*));
	for (int i = 0; i < TEXT_SIZE; i++) {
		words[i] = (char*)malloc(TEXT_SIZE * sizeof(char));
	}
	int amount = 0;
	int k = 0;
	while (fgets(text[amount], TEXT_SIZE, file) != NULL) {
		if(text[amount][strlen(text[amount]) - 1] == '\n') text[amount][strlen(text[amount]) - 1] = '\0';
		int i = 0;
		while (i < strlen(text[amount])) {
			int j = 0;
			while (!compareSeparator(text[amount][i]) && i < strlen(text[amount])) {
				words[k][j++] = text[amount][i++];
			}
			if (j) words[k][j] = '\0';
			if (!compareSeparator(text[amount][i-1])) k++;
			i++;
		}
		amount++;
	}

	// words - массив слов, k - колво слов
	printf("Words:\n");
	for (int i = 0; i < k; i++)
		printf("%s\n", words[i]);


	printf("\nGroups of words with similar symbols (but not equal words):\n");
	for (int i = 0; i < k; i++) {
		compareWord(words[i], words, k, i+1);
	}

	fclose(file);
	for (int i = 0; i < TEXT_SIZE; i++)
		free(text[i]);
	free(text);
	for (int i = 0; i < TEXT_SIZE; i++)
		free(words[i]);
	free(words);
}

void compareWord(char* word, char** arr, int k, int index) {
	int j = 0;
	for (int i = index; i < k; i++) {
		if ( compareSymbols(word, arr[i]) ) printf("%s, %s\n", word, arr[i]);
	}
}
bool compareSymbols(char* a, char* b) {
	if (strlen(a) != strlen(b)) return false;
	//bool* gga = (bool*)malloc(strlen(a) * sizeof(bool)); // массив для учета проверенных символов из а
	bool* ggb = (bool*)malloc(strlen(b) * sizeof(bool)); // массив для учета проверенных символов из b
	bool diffrWords = false; // проверка на одинаковые слова
	for (int i = 0; i < strlen(a); i++) {
		bool equalSymbols = false;
		for (int j = 0; j < strlen(b); j++) {
			if (!ggb[j]) continue;
			char x = b[j];

			if (a[i] >= 'A' && a[i] <= 'Z' && b[j] >= 'a' && b[j] <= 'z') b[j] -= 32;
			if (a[i] >= 'a' && a[i] <= 'z' && b[j] >= 'A' && b[j] <= 'Z') b[j] += 32;

			if (b[j] == a[i]) {
				ggb[j] = false;
				equalSymbols = true;
				if (j != i) diffrWords = true;
				b[j] = x;
				break;
			}
			b[j] = x;
		}
		if (!equalSymbols) { return false; free(ggb); }
	}
	free(ggb);
	if (!diffrWords) return false;
	else return true;
}

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//ищем количество слов
int Length(char* str, int wordCount)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			wordCount++;
	}
	return wordCount;
}

//заполняем двумерный массив словами из одномерного массива str
char** Filling(char* str, int n, char** words, int position)
{
	for (int i = 0; i < n; i++)
		words[i] = (char*)malloc(n* sizeof(char));
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' || '\0')
		{
			words[position][j] = str[i];
			words[position][j + 1] = '\0';
		}
		j++;
		if (str[i] == ' ')
		{
			position++;
			j = 0;
		}

	}
	return words;
}

//сортируем двумерный массив слов с помощью таблицы аски
char** Sort(char** words, char* temp, int wordCount)
{
	for (int i = 0; i < wordCount; i++) {
		for (int j = 0; j < wordCount - 1; j++) {
			if ((int)(words[j][0]) > (int)(words[j + 1][0]))
			{
				temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp;
			}
			else if ((int)(words[j][0]) == (int)(words[j + 1][0]))
			{
				if ((int)words[j][1] > (int)(words)[j + 1][1])
				{
					temp = words[j];
					words[j] = words[j + 1];
					words[j + 1] = temp;
				}
			}
			else if ((int)(words[j][1]) == (int)(words[j + 1][1]))
			{
				if ((int)words[j][2] > (int)(words)[j + 1][2])
				{
					temp = words[j];
					words[j] = words[j + 1];
					words[j + 1] = temp;
				}
			}
		}
	}
	return words;
}


int main()
{
	
	
	int n = 100;
	int position = 0;
	char* temp = (char*)malloc(n * sizeof(char));
	char** words = (char**)malloc((n) * sizeof(char*));
	char s[500];

	FILE* fp = fopen("D:\\text_for_4_lab.txt", "r");
	if (!fp)
	{
		printf("Error!\n");
		return 1;
	}
	while (!feof(fp))
	{
		fgets(s, sizeof(s), fp);
	}
	printf(" Words from file: %s ", s);
	fclose(fp);

	int wordCount = Length(s, 1);
	Filling(s, n, words, position);
	printf("\n\n");
	Sort(words, temp, wordCount);
	printf(" Words in alphabetical order: ");
	
	for (int q = 0; q< wordCount; q++)
		printf("%s ", words[q]);
	printf("\n\n");

	for (int i = 0; i < n; i++)
	{
		free(words[i]);
	}
	free(words);
	free(temp);
	
	return 0;
}
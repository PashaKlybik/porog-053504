#include <stdio.h> 
#include <stdlib.h> 

int find_count_of_words(char* str);
void repr(int* char_count, char** words, char* buf, int count_of_words);
void find(char** words, int* count_char, int words_count);

void main(void)
{
	FILE* fp;
	char* buf = (char*)malloc(sizeof(char) * 255), **words;
	int count = 0, * char_count, count_of_words;
	char ch;
	fp = fopen("D:/labudi lubuday/Egor/c/lr4/4.2(1)/Egor.txt", "r+");
	while ((ch = fgetc(fp)) != EOF)
	{
		buf[count] = ch;
		count++;
	}
	buf[count] = '\0';

	count_of_words = find_count_of_words(buf);

	char_count = (int*)malloc(sizeof(int) * count_of_words);
	for (int i = 0; i < count_of_words; i++)
		char_count[i] = 0;

	words = (char**)malloc(sizeof(char*) * count_of_words);
	for (int i = 0; i < count_of_words; i++)
		words[i] = (char*)malloc(sizeof(char) * 25);
	
	repr(char_count, words, buf, count_of_words);
	find(words, char_count, count_of_words);
	
	puts(buf);

	for (int i = 0; i < count_of_words; i++)
		free(words[i]);
	free(words);
	free(char_count);
	free(buf);
}

int find_count_of_words(char* str)
{
	int count = 0, i = 0;
	while (str[i] != '\0')
		if (str[i] == ' ' || str[i] == '\n')
		{
			count++;
			i++;
		}
		else i++;

	return count;
}
void repr(int* char_count, char** words, char* buf, int count_of_words)
{
	int i = 0, count = 0;
	words[i][i] = buf[i];
	while (buf[i] != '\0')
	{
		for (int j = 0; j < count_of_words; )
		{
			if (buf[i] == ' ' || buf[i] == '\n')
			{
				words[j][count] = '\0';
				count = 0;
				i++;
				j++;
			}
			else
			{
				words[j][count] = buf[i];
				count++;
				i++;
				char_count[j]++;
			}
		}

	}
}
void find(char** words, int* count_char, int words_count)
{
	int count = 0;
	for(int i = 0; i < words_count; i++)
		for(int j = i; j<words_count; j++)
			if (count_char[i] == count_char[j])
			{
				for (int k = 0, f = count_char[i] - 1; k < count_char[i], f >= 0; k++, f--)
					if (words[i][k] == words[j][f])
						count++;
					else
					{
						count = 0;
						break;
					}
				if (count == count_char[j])
				{
					puts(words[i]);
					puts(words[j]);
				}
			}
}
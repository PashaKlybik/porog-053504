#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int strlen(char* str)
{
	int res = 0;
	while (str[res] != '\0')
		res++;
	return res;
}
void concate(char* str1, char* str2)
{
	int pos = strlen(str1);
	for (int i = 0; i < strlen(str2); i++)
		str1[pos++] = str2[i];
	str1[pos] = '\0';
}
void clearStr(char* str)
{
	str[strlen(str)] = '1';
	str[0] = '\0';
}
char* getResult(char* str)
{
	char prevChar;
	char* temp = malloc(sizeof(char) * strlen(str));
	char* res = malloc(sizeof(char) * strlen(str));
	int tempPos = 0;
	res[0] = temp[0] = '\0';
	prevChar = str[0];
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			temp[tempPos++] = prevChar;
			temp[tempPos] = '\0';
			prevChar = str[i];
			concate(res, temp);
			clearStr(temp);
			tempPos = 0;
		}
		else if (str[i] < prevChar)
		{
			prevChar = ' ';
			clearStr(temp);
			tempPos = 0;
		}
		else {
			temp[tempPos++] = prevChar;
			temp[tempPos] = '\0';
			prevChar = str[i];
		}
	}
	if (prevChar != ' ') {
		temp[tempPos++] = prevChar;
		temp[tempPos] = '\0';
		concate(res, temp);
	}
	free(temp);
	return res;
}

int main()
{
	int n;
	printf("Size of string: ");
	scanf(" %d", &n);
	char* str = malloc(sizeof(char) * n);
	printf("String: ");
	fgets(str, n, stdin);
	fgets(str, n, stdin);
	str[strlen(str) - 1] = '\0';
	printf("Result :\n%s", getResult(str));
	return 0;
}
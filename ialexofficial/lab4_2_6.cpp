#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int strlen(char* str)
{
	int res = 0;
	while (str[res] != '\n' && str[res] != '\0')
		res++;
	return res;
}
int atoi(char c)
{
	return c - '0';
}
int pow(int base, int exp)
{
	int res = 1;
	for (int i = 0; i < exp; i++)
		res *= base;
	return res;
}
int stoi(char* str)
{
	int res = 0, len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int tmp = (int)pow(10, (len - 1));
		res += atoi(str[i]) * pow(10, (len - 1));
	}
	return res;
}
void moveLetters(char* str, int n)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += n;
			if (str[i] % 'Z' < 'A')
				str[i] = 'A' + (str[i] % 'Z') - 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] += n;
			if (str[i] % 'z' < 'a')
				str[i] = 'a' + (str[i] % 'z') - 1;
		}
	}
}

int main()
{
	FILE* file = fopen("C:\\Users\\Asus\\Desktop\\input.txt", "r");
	int n;
	char str[100];
	fgets(str, 100, file);
	n = stoi(str);
	for (int i = 0; i < n; i++)
	{
		fgets(str, 100, file);
		str[strlen(str)] = '\0';
		printf("%s - ", str);
		moveLetters(str, i + 2);
		printf("%s\n", str);
	}
	return 0;
}
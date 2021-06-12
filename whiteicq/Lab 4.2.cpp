//4.2(3)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int atoi(char s)
{
	return s;
}

int main()
{
	FILE* fl;
	if ((fl = fopen("C:\\Users\\user\\Desktop\\Программирование 2 сем\\Lab 4\\Lab 4\\Lab 4\\Text.txt", "r")) == NULL)
	{
		perror("Can't open file");
		exit(0);
	}
	char str[256];
	printf("Your string from file:\n");
	while (fgets(str, 256, fl) != NULL) //запись текста из файла в строку
	{
		fputs(str, fl);
		printf("%s", str);
	}
	printf("\n");

	int i = 0, n = 0, arr[200];
	while(str[i] != '\0')
	{
		if (str[i] > 47 && str[i] < 58 || str[i] == 45)
		{
			arr[n] = atoi(str[i]);
			n++;
		}	
		i++;
	}
	float f = 0;
	for (int i = 0; i < n; i++)
	{
		f += arr[i];
	}
	printf("Average = %f", f / n);
	

	return 0;
}
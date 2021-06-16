#define _CRT_SECURE_NO_WARNINGS
/* variant 5(Длина строк текстового файла не превышает 80 символов.
Разработать программу центрирования строк: короткие строки
дополняются пробелами и размещаются по центру.) */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE* f;
	char** str;
	int i, j, number, add;
	fpos_t pos;

	str = (char**)malloc(100 * sizeof(char*));
	for (i = 0; i < 100; i++) {
		str[i] = (char*)malloc(82 * sizeof(char));
	}

	f = fopen("text.txt", "r+");
	setbuf(f, NULL);
	fgetpos(f, &pos);

	i = 0;
	while (!feof(f)) {
		fgets(str[i], 81, f);
		i++;
	}
	number = i;

	rewind(f);

	for (i = 0; i < number - 1; i++) {
		add = strlen(str[i]) - 1;
		add = (80 - add) / 2;
		for (j = 0; j < add; j++) {
			fputc(' ', f);
		}
		fputs(str[i], f);
	}

	add = strlen(str[i]);
	add = (80 - add) / 2;
	for (j = 0; j < add; j++) {
		fputc(' ', f);
	}
	fputs(str[i], f);

	//-----------------------------------
	for (i = 0; i < 100; i++) {
		free(str[i]);
	}
	free(str);
	fclose(f);

	getchar();
	return 0;
}
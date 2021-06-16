/*4.2 (17).Латинизатор кириллицы.При интернет - общении с русской
диаспорой в других странах часто возникает проблемы отсутствия
кириллицы у зарубежных респондентов, а также слабое знание
иностранных языков у соотечественников.Один из выходов – набор
русских слов похожими по начертанию буквами латинского
алфавита.Среди прописных русских букв таких насчитывается
одиннадцать : А, В, Е, К, М, Н, О, Р, С, Т, Х.Распечатать из
заданного файла те слова, которые без искажения могут быть
написаны латинскими буквами, например :
	ВОВКА РОЕТ РОВ
	СВЕТА СЕЕТ ОВЕС.*/
#define _CRT_SECURE_NO_WARNINGS 

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char letters[16] = "ABCEHKMOPTX";
	char fletters[16] = "DFGIJLNQRSUVWYZ";
	char buffer[128];
	char word[16];
	short incorrectWord = 0;
	FILE *fp;
	fp = fopen("words.txt", "r");
	if (fp)
	{
		while (fgets(buffer, 128, fp))
		{
			int i = 0;
			int wordsize = 0;
			while (buffer[i] != '\0' && buffer[i] != '\n')
			{
				int k = 0; 
				while (letters[k] != '\0')
				{
					if (buffer[i] == letters[k] && incorrectWord == 0)
					{
						word[wordsize++] = buffer[i];
						break;
					}
					else if (buffer[i] == fletters[k])
					{
						wordsize = 0;
						incorrectWord = 1;
					}
					k++;
				}
				i++;
				if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\0')
				{
					if (incorrectWord == 0)
					{
						word[wordsize] = '\0';
						printf("%s ", word);
						wordsize = 0;
					}
					else
					{
						incorrectWord = 0;
					}
				}
			}
		}
	}
}
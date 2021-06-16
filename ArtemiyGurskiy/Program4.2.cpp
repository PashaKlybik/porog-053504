#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128 /* количество символов в строке */

int Strlen(const char* str) {
	int len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

void recognizer(char* text_buffer)
{
	int i_index = 0;
	int j = 0;
	int l = 0;
	int text_buffer_length = Strlen(text_buffer);

	char word_buffer1[N];
	char space = ' ', enter = '\n', null = '\0';

	while(true)
	{
		j = 0;

		for (i_index; i_index <= text_buffer_length; i_index++)
		{
			if (text_buffer[i_index] != space && text_buffer[i_index] != enter)
			{
				if (text_buffer[i_index] != space && text_buffer[i_index] != enter && text_buffer[i_index] != null)
				{
					word_buffer1[j] = text_buffer[i_index];
					text_buffer[i_index] = ' ';
					word_buffer1[j + 1] = '\0';
					j++;
				}

				if (text_buffer[i_index] == null)
				{
					exit(1);
				}

				if (text_buffer[i_index + 1] == ' ' || text_buffer[i_index + 1] == enter || text_buffer[i_index + 1] == null)
				{
					printf_s("\n%s ", word_buffer1);
					break;

				}
			}
		}

		l = 0;
		char word_buffer2[N];

		for (i_index++; i_index <= text_buffer_length; i_index++, l++)
		{
			if (text_buffer[i_index] != space && text_buffer[i_index] != enter && text_buffer[i_index] != null)
			{
				word_buffer2[l] = text_buffer[i_index];
				word_buffer2[l + 1] = '\0';
			}
			else
			{
				bool check = false;
				for(int i = 0; i < j; i++)
				{
					check = false;

					for(int j = 0; j < l; j++)
					{
						check = false;
						if(word_buffer1[i] == word_buffer2[j])
						{
							check = true;
							break;
						}
					}
					if(check == false)
					{
						break;
					}
				}
				for (int i = 0; i < j; i++)
				{
					check = false;

					for (int j = 0; j < l; j++)
					{
						check = false;
						if (word_buffer2[i] == word_buffer1[j])
						{
							check = true;
							break;
						}
					}
					if (check == false)
					{
						break;
					}
				}
				if(check == true)
				{
					printf_s(" %s", word_buffer2);
					for(int k = i_index - Strlen(word_buffer2); k < i_index; k++)
					{
						text_buffer[k] = ' ';
					}
				}
				l = -1;
			}
		}

		i_index = 0;
	}
}

void main(void)
{
	system("chcp 1251");
	system("cls");

	int i_index = 0;

	char temp_text_buffer[N];
	char text_buffer[N];
	FILE* fp;

	fp = fopen("D:\\ex42b.txt", "r");

	if (!fp)
	{
		exit(1);
	}

	while (fgets(temp_text_buffer, N, fp) != NULL)
	{
		puts(temp_text_buffer);
		for(int i = 0; i < Strlen(temp_text_buffer); i++)
		{
			text_buffer[i_index] = temp_text_buffer[0 + i];
			i_index++;
		}
		text_buffer[i_index] = ' ';
	}
	fclose(fp);

	text_buffer[i_index] = '\0';
	recognizer(text_buffer);
}
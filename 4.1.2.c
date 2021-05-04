#include <stdio.h>

char change(char text[], int j);

void main(void) {
	int i = 0;
	char text[80], ch;
	int count = 0;

	printf("Enter string:\n");
	for (i; (ch = getchar()) != '\n'; i++) {
		text[i] = ch;
	}
	text[i] = '\0';
	for (int j = 0; text[j] != '\0'; j++)
		count=j+1;
	for (int j = 0; text[j] !='\0'; j++) {
		if (text[j] == '.' || text[j] == '!' || text[j] == '?' || text[j] == ',' || text[j] == ';' || text[j] == ':') {
			j++;
			if (text[j] >= 97 && text[j] <= 122 && (text[j-1] == '.' || text[j-1] == '!' || text[j-1] == '?'))
			{
				text[j] = text[j] - 32;
			}
			count++;
			change(text, j, count);
		}
	}
	printf("%s", text);
}

char change(char text[], int j, int count) {
	int k = j;
	for (count;  count>j; count--)
		text[count] = text[count-1];
	text[k] = ' ';
	return text;
}
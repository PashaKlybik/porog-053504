#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 128
void main(void) {
	int count = 0, max = 0, i = 0, bracket1 = 0, bracket2 = 0;;
	char buf[N];
	FILE* fp = fopen("D:\\c.txt", "r+");
	if (NULL != fgets(buf, N, fp)) {
		printf("%s", buf);
		for (int i = 0; buf[i] != '\0'; i++) {
			if (buf[i] == '(') 
				bracket1++;
			if (buf[i] == ')')
				bracket2++;
		}
		if (bracket1 == bracket2) {
			for (int i = 0; buf[i] != '\0'; i++) {
				if (buf[i] == '(') {
					buf[i] = '{';
					count++;
					if (count > max)
						max = count;
				}
				if (buf[i] == ')') {
					buf[i] = '}';
					count--;
				}
				
			}
			for (int i = 0; buf[i] != '\0'; i++) {
				if (buf[i] == '{') {
					count++;
					if (count == max) buf[i] = '(';
					if (count == max - 1) buf[i] = '[';
				}
				if (buf[i] == '}') {
					if (count == max) buf[i] = ')';
					if (count == max - 1) buf[i] = ']';
					count--;
				}
			}
			fprintf(fp, "%s", buf);
			printf("%s", buf);
		}
		else {
			printf("\nEnter correct string!");
			return 0;
		}
	}
	else 
		printf("File is empty!");
	fclose(fp);
}
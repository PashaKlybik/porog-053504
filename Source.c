#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
char answer();
void test(char* testf, char* rezultsf);

void main(void)
{
	char ch;
	char testf[256]= "D:\Test.txt";
	char rezultsf[256]= "D:\Rezults.txt";
	for(;;) {
		printf("Choose point:\n");
		printf("1.Test\n");
		printf("2.Finish\n");
		ch = answer();
		switch (ch) {
		case '1':
				test(testf, rezultsf);
				break;
		case '2':
			return 0;
				break;

		default:
			printf("Enter correct point\n");
			continue;
		}
	}
}
char answer() {
	for(;;) {
		char ans[256] = "\0";
		gets(ans);
		if (ans[0]!=NULL)
			return ans[0];
	}
}

void test(char* testf, char* rezultsf) {
    FILE* test = fopen(testf, "r+");
    FILE* rez = fopen(rezultsf, "a+");
    char name[256], right[256], buf[256], ans[64];
    int number = 0, i = 1, points;

    printf("\nWhat is your name?\n");
    scanf("%s", name);

   for(;;) {
        printf("\n");
        while (1) {
            fgets(buf, 256, test);
            if (strcmp(buf, "***\n") == 0)
                break;
            if (strcmp(buf, "keys\n") == 0) {
                i = 0;
                break;
            }
            printf("%s", buf);
        }
        if (i == 0)
            break;
        ans[number++] = answer();
    }

    fgets(right, 256, test);
    for (i = 0, points = 0; i < number; i++)
        if (ans[i] == right[i])
            points++;

    points = (int)(100 / (float)number * points);
    printf("\nYour score: %d\n\n", points);
    printf("-------------------------------------------------------------------------------------\n");
    fprintf(rez, "%s: %d\n", name, points);
    fclose(test);
    fclose(rez);
}
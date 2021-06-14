#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void test();
void main(void )
{
	

	int ch;

	while (1) {
		printf("Choose point:\n");
		printf("1.Start test\n");
		printf("2.Finish\n");

		while (1) {
			scanf_s("%d",&ch);

			switch (ch) {
			case 1:
				//strcpy_s(file, 256, "C test.txt");
				//strcpy_s(file1, 256, "C rez.txt");
				break;
			case 2:
				return 0;
			default:
				printf("Choose right point");
				continue;
			}
			break;
		}

		puts("\n1 - Start test");
		puts("2 - See previous results");
		puts("3 - Clear rezuts");
		puts("0 - go back");

		while (1) {
			scanf_s("%d", &ch);

			switch (ch) {
			case 1:
				test();
				break;
			/*case 2:
				rez(file1);
				putchar('\n');
				break;
			case 3:
				writeRez(file1);
				putchar('\n');
				break;
			case '0':
				putchar('\n');
				break;*/
			default:
				puts("Choose a right point");
				continue;
			}
			break;
		}
	}
}


void test() {
	FILE* f;
	fopen_s(&f,"C test.txt" ,"r");
	FILE* rez;
	fopen_s(&rez,"C rez.txt", "a+");

	char name[256];
	int score=0;

	int quest = 0;
	char answers[256];
	char rightanswers[256];

	int i = 1;
	char buffer[256];

	//printf("\nEnter your name:\n");
	//gets(name);

	while (1) {
		//putchar('\n');
		while (1) {
			fgets(buffer, 256, f);
			if (strcmp(buffer, "@@\n") == 0) {
				break;
			}
			if (strcmp(buffer, "##\n") == 0) {
				i = 0;
				break;
			}
			printf("%s", buffer);
		}
		if (i == 0) {
			break;
		}
		//answers[quest++];
	}

	fgets(rightanswers, 256, f);
	for (i = 0, score = 0; i < quest; i++) {
		if (answers[i] == rightanswers[i]) {
			score++;
		}
	}

	score = (int)(10 / (float)quest * score);
	printf("\nYour score: %d\n", score);
	puts("Result saved\n\n");
	fputc('\n', rez);
	fputs(name, rez);
	fputc('\n', rez);
	fprintf(rez, "%d", score);

	fclose(f);
	fclose(rez);
}

//void rez(char* file) {
//	FILE* f;
//	fopen_s(&f, "C Rez.txt", "r+");
//	fpos_t* pos;
//	char buffer[256];
//
//	putchar('\n');
//	fgets(buffer, 256, f);
//	while (!feof(f)) {
//		fgets(buffer, 256, f);
//		printf("%s", buffer);
//		fgets(buffer, 256, f);
//		printf("%s", buffer);
//	}
//	putchar('\n');
//	fclose(f);
//}
//
//void writeRez(char* file) {
//	FILE* f = fopen_s(file,"C Rez.txt", "w+");
//	fclose(f);
//}
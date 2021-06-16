// variant 17
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GetAnswer() {
	while (1) {
		char choise[256] = "\0";
		gets(choise);
		if (choise[0])
			return choise[0];
	}
}

void GoTest(char *testfilename, char *rezfilename) {
	FILE *f = fopen(testfilename, "r+");
	FILE *frez = fopen(rezfilename, "a+");

	char name[256];
	int score;

	int questions_number = 0;
	char answers[64];
	char rightanswers[64];

	int i = 1;
	char buffer[256];
	//------------------------------------

	puts("\nEnter your name:");
	gets(name);

	while (1) {
		putchar('\n');
		while(1) {
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
		answers[questions_number++] = GetAnswer();
	}

	fgets(rightanswers, 256, f);
	for (i = 0, score = 0; i < questions_number; i++) {
		if (answers[i] == rightanswers[i]) {
			score++;
		}
	}

	score = (int)(10 / (float)questions_number * score);
	printf("\nYour score: %d\n", score);
	puts("Result saved\n\n");
	//---------------------------------------------------
	fputc('\n', frez);
	fputs(name, frez);
	fputc('\n', frez);
	fprintf(frez, "%d", score);

	fclose(f);
	fclose(frez);
}

void SeeRezults(char *filename) {
	FILE *f = fopen(filename, "r+");
	fpos_t *pos;
	char buffer[256];

	putchar('\n');
	fgets(buffer, 256, f);
	while(!feof(f)) {
		fgets(buffer, 256, f);
		printf("%s", buffer);
		fgets(buffer, 256, f);
		printf("%s", buffer);
		//fgetpos(f, pos);
		//1fsetpos(f, pos);
	}
	putchar('\n');
	fclose(f);
}

void ClearRezults(char *filename) {
	FILE *f = fopen(filename, "w+");
	fclose(f);
}

int main()
{
	char choise;
	char testfilename[256];
	char rezfilename[256];

	while (1) {
		puts("Select test:");
		puts("1 - \"C test\"");
		puts("0 - exit");

		while (1) {
			choise = GetAnswer();

			switch (choise) {
			case '1':
				strcpy(testfilename, "C test.txt");
				strcpy(rezfilename, "C rez.txt");
				break;
			case '0':
				return 0;
			default:
				puts("Incorrect data. Repeat please");
				continue;
			}
			break;
		}

		puts("\n1 - Start test");
		puts("2 - See previous results");
		puts("3 - Clear rezuts");
		puts("0 - go back");

		while (1) {
			choise = GetAnswer();

            switch (choise) {
			case '1':
				GoTest(testfilename, rezfilename);
				break;
			case '2':
				SeeRezults(rezfilename);
				putchar('\n');
				break;
			case '3':
				ClearRezults(rezfilename);
				putchar('\n');
				break;
			case '0':
				putchar('\n');
				break;
			default:
				puts("Incorrect data. Repeat please");
				continue;
			}
			break;
		}
	}
}

// variant 17
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGTH 			 256
#define ANSWERS_STR_LENGTH   64

char GetAnswer() {
	while (1) {
		char choise[STR_LENGTH] = "\0";
		gets(choise);
		if (choise[0])
			return choise[0];
	}
}

void GoTest(char *testfilename, char *rezfilename) {
	FILE *f = fopen(testfilename, "r+");
	FILE *frez = fopen(rezfilename, "a+");

	char name[STR_LENGTH];
	int score;

	int questions_number, answers_number;
	char answers[ANSWERS_STR_LENGTH];
	char rightanswers[ANSWERS_STR_LENGTH];

	int i, j, k;
	char buffer[STR_LENGTH];
	//------------------------------------
	fgets(buffer, STR_LENGTH, f);
	questions_number = atoi(buffer);
	fgets(buffer, STR_LENGTH, f);
	answers_number = atoi(buffer);
	//------------------------------------

	puts("\nEnter your name:");
	gets(name);

	for (i = 0, k = 0; i < questions_number; i++) {
		putchar('\n');
		for (j = 0; j <= answers_number; j++) {
			fgets(buffer, STR_LENGTH, f);
			printf("%s", buffer);
		}
		answers[k++] = GetAnswer();
	}

	fgets(rightanswers, STR_LENGTH, f);
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
	char buffer[STR_LENGTH];

	putchar('\n');
	fgets(buffer, STR_LENGTH, f);
	while(!feof(f)) {
		fgets(buffer, STR_LENGTH, f);
		printf("%s", buffer);
		fgets(buffer, STR_LENGTH, f);
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
	char testfilename[STR_LENGTH];
	char rezfilename[STR_LENGTH];

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

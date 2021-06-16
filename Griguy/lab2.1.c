// variant 28
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 6

typedef struct Faculty
{
	char name[NAME_LENGTH];
	int passing_pts;
} Faculty;

void calculate_faculty(Faculty *list, int number) {
	int maths, physics, language, certificate, sum;

	printf("How many points u've got in math?\n");
	scanf("%d", &maths);
	getchar();

	printf("How many points u've got in phesics?\n");
	scanf("%d", &physics);
	getchar();

	printf("How many points u've got in language?\n");
	scanf("%d", &language);
	getchar();

	printf("Certificate points?\n");
	scanf("%d", &certificate);
	getchar();

	if (language - maths > 20 && language - physics > 20) {
		puts("U better try humanitarian)\n");
		return;
	}

	sum = maths + physics + language + certificate;

	if (sum < list[0].passing_pts) {
		puts("Idk dummy\n");
	}
	else if (sum < list[1].passing_pts) {
		printf("Try %s\n\n", list[0].name);
	}
	else if (sum < list[2].passing_pts) {
		printf("Try %s\n\n", list[1].name);
	}
	else if (sum < list[3].passing_pts) {
		printf("Try %s\n\n", list[2].name);
	}
	else if (sum < list[4].passing_pts) {
		printf("Try %s\n\n", list[3].name);
	}
	else {
		printf("Try %s\n\n", list[4].name);
    }

}

void show(Faculty fac) {
	printf("Faculty: %s\nPoints required: %d\n", fac.name, fac.passing_pts);
	puts("Good luck in trying!\n");
}

int main()
{
	Faculty list[5];
	int i, rep = 1;

	strcpy(list[0].name, "FRE");
	list[0].passing_pts = 235;

	strcpy(list[1].name, "FIC");
	list[1].passing_pts = 257;

	strcpy(list[2].name, "FITC");
	list[2].passing_pts = 301;

	strcpy(list[3].name, "FCD");
	list[3].passing_pts = 307;

	strcpy(list[4].name, "FCSaN");
	list[4].passing_pts = 318;

	puts("1 - Show FRE\n2 - Show FIC\n3 - Show FITC\n4 - Show FCD\n5 - Show FCSaN");
	puts("6 - Calculate faculty by test points\n7 - Exit");

	while(rep) {
		scanf("%d", &i);
		switch(i) {
			case 1:
				show(list[0]);
				break;
			case 2:
				show(list[1]);
				break;
			case 3:
				show(list[2]);
				break;
			case 4:
				show(list[3]);
				break;
			case 5:
				show(list[4]);
				break;
			case 6:
				calculate_faculty(list, 5);
				break;
			case 7:
				rep = 0;
		}
    }

	getchar();
	return 0;
}

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>

int myStrlen(char* str) {
	int i = 0;
	int counter = 0;
	if (str[0] == '0') {
		i++;
	}
	while (str[i] != '\0') {
		if ((str[i] - 48) < 10 && (str[i] - 48) >= 0) {
			counter++;
			i++;
		}
		else {
			break;
		}
	}
	return counter;
}

int main()
{
	system("color 0D");
	int intstr;
	char str[7];
	int j, s;
	int res = 0;
	do {
		for (int i = 0; i < 5; i++) {
			str[i] = 0;
		}
		j = 0;
		res = 0;
		s = 0;
		while (s < 70) {
			printf("*");
			s++;
		}
		printf("\nEnter your number[100; 9999](enter <m> to close program) ");
		fgets(str, 6, stdin);
		if (str[0] == 'm') {
			break;
		}
		intstr = atoi(str);
		if ((myStrlen(str) > 2) && (myStrlen(str) < 5) && (intstr < 10000) && (intstr > 99)) {
			intstr = 1;
			printf("Correct number!\n");
			if (myStrlen(str) == 3) {
				if (str[0] == '0') {
					j++;
					res = str[j] - '0';
					j++;
					for (j; j <= myStrlen(str); j++) {
						res *= str[j] - 48;
					}
				}
				else {
					res = str[j] - '0';
					j++;
					for (j; j < myStrlen(str); j++) {
						res *= str[j] - 48;
					}
				}
				
			}
			else {
				if (str[0] == '0') {
					j++;
					res = str[j] - '0';
					j++;
					for (j; j <= myStrlen(str); j++) {
						res += str[j] - '0';
					}
				}
				for (j; j < myStrlen(str); j++) {
					res += str[j] - '0';
				}
			}
			s = 0;
			while (s < 15) {
				printf("-");
				s++;
			}
			printf("\n");
			puts(str);
			printf("Result: %d\n", res);
		}
		else {
			printf("Enter correct number!\n");
		}
		
	} while (true);
	return 0;
}

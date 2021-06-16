#include <stdio.h>


int main() {
	char *numbers[10] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};	
	char *num[10] = {"один", "две", "три", "четыр", "пят", "шест", "сем", "восем", "девят"};	
	int number;
	printf("input number: ");
	scanf("%d", &number);
	printf("%d - ", number);
	
	if (number < 10 && number > 0) 
		printf("%s", numbers[number]);
	else if (number < 20 && number >= 10) {
		if (number == 10) 
			printf("десять");
		else 
			printf("%sнадцать", num[number%10-1]);
		
	}

	else if (number < 40 && number >= 20) 
		printf("%sдцать %s", numbers[number/10], numbers[number%10]);

	else if (number/10 == 4)
		printf("сорок %s", numbers[number%10]);

	else if (number < 90 && number >= 50) 
		printf("%sдесят %s", numbers[number/10], numbers[number%10]);

	else if (number < 100 && number >= 90) 
		printf("девяносто %s", numbers[number%10]);

	else printf("сто");
	printf("\n");

}

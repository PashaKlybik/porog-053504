//  variant 5
#include <stdlib.h>
#include <conio.h>

int main()
{
	//finding numbers with monotonously changing digits
int n, ncpy, i, temp;
	unsigned short count, a[9];

	printf("Enter anything from 1 to 2147483647\n");
	scanf("%d", &n);

	ncpy = n;

	if (n > 98765432)
		n = 98765432;

	for (i = 1; i <= n; i++) {
		temp = i;
		count = 0;

		do {
			a[count] = i % 10;
			i /= 10;
			count++;
		} while (i);

		for (i = 1; i < count; i++) {
			if (a[i] <= a[i-1]) {
				i ^= i;
				break;
			}
		}

		if (i) {
			printf("%d\n", temp);
			i = temp;
			continue ;
		}

		for (i = 1; i < count; i++) {
			if (a[i] >= a[i-1]) {
				i ^= i;
				break;
			}
		}

		if (i) {
			printf("%d\n", temp);
		}
		i = temp;
	}

	if(ncpy >= 123456789)
		printf("%d\n", 123456789);
	if(ncpy >= 876543210)
		printf("%d\n", 876543210);
	if(ncpy >= 976543210)
		printf("%d\n", 976543210);
	if(ncpy >= 986543210)
		printf("%d\n", 986543210);
	if(ncpy >= 987543210)
		printf("%d\n", 987543210);
	if(ncpy >= 987643210)
		printf("%d\n", 987643210);
	if(ncpy >= 987653210)
		printf("%d\n", 987653210);
	if(ncpy >= 987654210)
		printf("%d\n", 987654210);
	if(ncpy >= 987654310)
		printf("%d\n", 987654310);
	if(ncpy >= 987654320)
		printf("%d\n", 987654320);
	if(ncpy >= 987654321)
		printf("%d\n", 987654321);

	printf("That's all");
	getchar();
	getchar();
	return 0;
}

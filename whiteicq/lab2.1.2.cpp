//задание 2
#include <stdio.h>
#include <stdlib.h>

void input(int& a, int& b)
{
	printf("Enter numerator:\n");
	scanf_s("%d", &a);
	printf("Enter denominator:\n");
	scanf_s("%d", &b);
	if (b == 0)
	{
		printf("Error. Denominator cannot be 0. Try again\n");
		return;
	}
}

void output(int a, int b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return;
	}
	printf("%d\n-\n%d\n", a, b);

}

void add(int a, int b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return;
	}
	printf("%d + %d = %d\n", a, b, a + b);

}

void subtraction(int a, int b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return;
	}
	printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return;
	}
	printf("%d * %d = %d\n", a, b, a * b);
}

void division(int& a, int& b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return;
	}
	float k = (float)a / (float)b;
	printf("%d / %d = %f\n", a, b, k);
}

double garmonic(int a, int b)
{
	if (b == 0)
	{
		printf("Denominator can't be 0. Try again");
		return 0;
	}
	return 2.0 * a * b / (a + b);
} 

void bio()
{
	printf("The program was made by Vladislav Belko\n");
}

int main()
{
	int x = 0, y = 0;
	input(x, y);
	int	z;
	printf("1 : input\n2 : output\n3 : addiction\n4 : subraction\n5 : multiply\n6 : division\n7 : garmonic\n8 : name of author\n9 : cancel\n");
	
		while (true)
		{
			printf("\nYour turn: ");
			scanf_s("%d", &z);
			switch (z)
			{
			case 1: input(x, y); break;
			case 2: output(x, y); break;
			case 3: add(x, y); break;
			case 4: subtraction(x, y); break;
			case 5: multiply(x, y); break;
			case 6: division(x, y); break;
			case 7: printf("garmonic = %le\n", garmonic(x, y)); break;
			case 8: bio(); break;
			case 9: exit(0); break;
			default: printf("Error\n");
			}
		}
	
	



	return 0;
}
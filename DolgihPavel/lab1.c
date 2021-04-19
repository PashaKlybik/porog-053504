#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	int b = 0, sum1 = 0, sum2 = 0;
	printf("Enter number:\n");
	scanf_s("%lf", &a);
	if(a<0)
	{
		a = a * (-1);
	}

	while (a >= 1)
	{
		a--;
		b++;
	}
	


	for (int i = 0; i < 9; i++)
	{
		a = a * 10;
	}

	
	while (b != 0)
	{
		sum1 += b % 10;
		b /= 10;

	}
	a = round(a);
	
	while (a != 0)
	{
		sum2 += (int)a % 10;
		a /= 10;

	}

	printf("Summa pered zapyatoi %d\n", sum1);
	printf("Summa posle zapyatoi %d\n", sum2);
	if(sum1>sum2)
	{
		printf("Summa pered zapyatoi > Summi posle zapyatoi  \n");
	}
	else if(sum1==sum2)
	{
		printf("Summa pered zapyatoi = Summi posle zapyatoi  \n");
	}
	else printf("Summa pered zapyatoi < Summi posle zapyatoi  \n");
	return 0;
}
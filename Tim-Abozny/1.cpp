#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	const int SIZE = 255;
	int numberM;
	printf("enter M (m>0):  ");
	scanf("%d", &numberM);
	printf("\n");

	if (numberM > 0)
	{
		int save = 0;
		char buf[SIZE];
		int temp, findNumber = 7;
		int k;

		while(findNumber < numberM)
		{	
			if (numberM > 6)
			{


				temp = findNumber;
				_itoa_s(temp, buf, 2);

				printf("%d) right number(10):\t%d\t(2)\t%s\n", save, findNumber, buf);
				k = save % 2;
				if (k != 0)
				{
					findNumber = (findNumber * 8) + 7;
				}
				else
				{
					findNumber = findNumber * 8;
				}
				save++;

			}
			else printf("Numbers not found ;(\n");
		}
	}
	else printf("Incorrect number!\n");


	getchar();
	return 0;
}
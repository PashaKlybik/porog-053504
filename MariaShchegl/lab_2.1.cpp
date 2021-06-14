
#include<stdio.h>
#include <locale.h>
#include<math.h>
#include < stdlib.h > 


void input(float& r)
{
		scanf_s("%f", &r);
}
void square(float& r)
{
	if (r <= 0)
	{
		printf("Введено отрицательное число");
	}
	else {
		float s = 4 * 3.14 * r * r;
		printf("Площадь равна %.2f", s);
	}
}
void volume (float& r)
{
	if (r <= 0)
	{
		printf("Введено отрицательное число");
	}
	else {
		float v = 0.3 * 3.14 * r * r * r;
		printf("Объем равен %.2f", v);
	}
}
void side(float& r)
{
	if (r <= 0)
	{
		printf("Введено отрицательное число");
	}
	else {
		float a =4*r/2.449;
		printf("Длинна ребра %.2f", a);
	}

}
void squaredistanse(float& r)
{
	float k;
	printf("Введите расстояние от цетра шара до сечения ");
	scanf_s("%f", &k);
	if (k >= r || k <= 0)
	{
		printf("Введены не верные данные");
	}
	else
	{
		float R = pow(r * r - k * k, 0.5);
		float S = 3.14 * R * R;
		printf("Площадб сечения:%.2f", S);

	}


}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	int a;
	float r1;
	while (true)	 
	{
		printf("\n1.Введите радиус\n2.Площадь:\n3.Объем:\n4.Длинна ребра:\n5.Площадь сечения:\n6.Автор\n7.Выход.\n");
		scanf_s("%d", &a);
	
		switch (a)
		{
		case 1:
			printf("Введите радиус:");
			input(r1);
			break;
		case 2:
			square(r1);
			break;
		case 3:
			volume(r1);
			break;
		case 4:
			side(r1);
			break;
		case 5:
			squaredistanse(r1);
			break;
		case 6 :
			printf("Щегловская Мария, гр.053504");
			break;
		case 7:
			exit(0);
			break;
		default:  break;



		}


	}
   
}


// Programming  2 laba 2 task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define M_PI  3.14159265

int n = 1;
long double lol = 0;

int factorial(int k){
	int res = 0;
	if (k < 0) {
		return 0;
	}
	else if(k == 0) {
		return 1;
	}
	else if(k >= 1) {
		return  (k * factorial(k - 1));
	}
}

 float rec(int n, long double x, long double E) {
	
	lol = pow((-1), (n - 1)) * pow((x * M_PI / 180), (2 * n - 1)) / factorial(2 * n - 1);
	return lol;
}

 void buff(int n, long double x, long double E, long double left, long double right) {
	 while (fabs(left - right) > E) {
		 right += rec(n, x, E);
		 n++;
	 }
	 while (fabs(left - right) < E) {
		 printf("correct n is : %d \n", n);
		 printf("Result of calculaton of the right side : \n");
		 printf("right result = %lf \n", right);
		 break;
	 }
}

 void incr(int n, long double x, long double E, long double left, long double right) {
	 while (n)
	 {
		 if (fabs(left - right) > E) {
			 right += pow((-1), (n - 1)) * pow((x * M_PI / 180), (2 * n - 1)) / factorial(2 * n - 1);
			 n++;
		 }
		 else {
			 printf("correct n is : %d \n", n);
			 printf("Result of calculaton of the right side : \n");
			 printf("right result = %lf \n", right);
			 break;
		 }
	 }
 }

int main()
{
	long double first_result = 0, second_result = 0,E,x;
	int choice = 0;
	printf("Enter minimum E : ");
	scanf_s("%lf", &E);
	printf("Enter angle : ");
	scanf_s("%lf", &x);
	while(x > 360) {
		x -= 360;
	}
	while (x < -360) {
		x += 360;
	}
	first_result = sin(x * M_PI / 180);
	printf("Result of calculation of the left side : \n");
	printf("left result = %lf \n", first_result);
	printf("Enter 1 for recursion or 2 for incrementation : \n");
	scanf_s("%d",&choice);
	if (choice == 1) {
		buff(n,x, E, first_result, second_result);
	}
	else if (choice == 2) {
		incr(n, x, E, first_result, second_result);
	}
	return 0;
} 
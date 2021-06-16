#include <stdio.h>
#include <conio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define M_PI  3.14159265

int factorial(int k) {
	int res = 0;
	if (k < 0) {
		return 0;
	}
	else if (k == 0) {
		return 1;
	}
	else if (k >= 1) {
		return  (k * factorial(k - 1));
	}
}

float rec(int n, double x, double E) {
	double rc = 0;
	rc = pow((-1), (n - 1)) * pow((x * M_PI / 180), (2 * n - 1)) / factorial(2 * n - 1);
	return rc;
}

void finrec(int n, double x, double E, double left, double right) {
	while (fabs(left - right) > E) {
		right += rec(n, x, E);
		n++;
	}
	while (fabs(left - right) < E) {
		printf("Recursion : \n");
		printf("right result = %lf \n", right);
		printf("correct n is : %d \n", n);
		break;
	}
}

void incr(int n, double x, double E, double left, double right) {
	while (n)
	{
		if (fabs(left - right) > E) {
			right += pow((-1), (n - 1)) * pow((x * M_PI / 180), (2 * n - 1)) / factorial(2 * n - 1);
			n++;
		}
		else {
			printf("Incrementing: \n");
			printf("right result = %lf \n", right);
			printf("correct n is : %d \n", n);
			break;
		}
	}
}

int main()
{
	long double firstres = 0, secondres = 0, E, x;
	int choice = 0, n = 1;
	printf("Enter minimum E : ");
	scanf_s("%lf", &E);
	printf("Enter angle : ");
	scanf_s("%lf", &x);
	while (x > 360) {
		x -= 360;
	}
	while (x < -360) {
		x += 360;
	}
	firstres = sin(x * M_PI / 180);
	printf("Result of calculation of the left side : \n");
	printf("left result = %lf \n", firstres);
	finrec(n, x, E, firstres, secondres);
	incr(n, x, E, firstres, secondres);
	return 0;
}
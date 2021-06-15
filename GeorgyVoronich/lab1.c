#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>


int main()
{
	int k = 10;
	int n = (k - 1) / 20 + 1;
	int ch = ((k - 1) % 20) / 2;
	int s =(k % 2)* n + ((k + 1) % 2) * ch;
	printf("%d", s);
	return 0;
}

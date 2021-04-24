#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>



using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int n;
	string s;
	printf_s("Введите двузначное число или число сто: ");
	scanf_s("%d", &n);

	if(n > 100)
	{
		while(n > 100)
		{
			printf_s("Введённое число больше ста, пожалуйста, повторите ввод: ");
			scanf_s("%d", &n);
		}
	}

	if (n == 100) {
		s = "Сто";
	}

	else {
		s = "";
		double d = n / 10;
		switch ((int)d) {
		case 2: s = "Двадцать"; 
			break;
		case 3: s = "Тридцать"; 
			break;
		case 4: s = "Сорок"; 
			break;
		case 5: s = "Пятьдесят";
			break;
		case 6: s = "Шестьдесят";
			break;
		case 7: s = "Семьдесят";
			break;
		case 8: s = "Восемьдесят";
			break;
		case 9: s = "Девяносто"; 
			break;
		}
		if (n % 100 >= 10 && n % 100 < 20) {
			switch (n % 100) {
			case 10:s = s + "Десять"; 
				break;
			case 11:s = s + "Одиннадцать";
				break;
			case 12:s = s + "Двенадцать";
				break;
			case 13:s = s + "Тринадцать";
				break;
			case 14:s = s + "Четырнадцать";
				break;
			case 15:s = s + "Пятнадцать";
				break;
			case 16:s = s + "Шестнадцать";
				break;
			case 17:s = s + "Семнадцать";
				break;
			case 18:s = s + "Восемнадцать";
				break;
			case 19:s = s + "Девятнадцать";
				break;
			}
		}
		else {
			switch (n % 10) {
			case 1:s = s + " один"; 
				break;
			case 2:s = s + " два";
				break;
			case 3:s = s + " три";
				break;
			case 4:s = s + " четыре";
				break;
			case 5:s = s + " пять";
				break;
			case 6:s = s + " шесть"; 
				break;
			case 7:s = s + " семь";
				break;
			case 8:s = s + " восемь";
				break;
			case 9:s = s + " девять";
				break;
			}
		}
	}
	printf_s("%s", s.c_str());
}
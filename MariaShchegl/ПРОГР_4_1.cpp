#include <stdio.h>
#include <conio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    char myString[100]; 
    char c;
    printf("Введите длинную строку: ");
    int i = 0;
    int brackets = 0;//скобки
    while ((c = getchar()) != '\n')
    {
        if (c == '(')
        {
            brackets++;
            myString[i] = c;
            i++;
            continue;
        }
        if (c == ')')
        {
            brackets--;
            myString[i] = c;
            i++;
            continue;

        }
        if (brackets > 0)
        {
            continue;
        }
        myString[i] = c;
        i++;
    }
   myString[i] = '\0';
    printf("%s\n", myString);
    if (brackets > 0)
    {
        printf("У вас не закрыто %d скобок", brackets);

    }
    else if (brackets < 0)
    {
        printf("У вас не открыто %d скобок", brackets * -1);
    }

    }
   
    
#include <stdio.h>

void toRoman(int number);

int main() {

    int number, cont = 1;

    while (cont) {
        printf("Введите ваше число: ");
        scanf("%d", &number);
        puts("Ваше число: ");
        toRoman(number);

        printf("\nЕсли хотите выйти, нажмите 0\t");
        scanf("%d", &cont);
    }
    return 0;
}

void toRoman(int number){

    char rom[13][3] = { "M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {
        while (number>=arabic[i]){
            printf("%s",rom[i]);
            number = number - arabic[i];
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

int main()
{
    char n, input, s[5], v[5], h[5], check;
    int j = 0, * data;
    do {
        j = 0;
        while (j < 70) {
            printf("*");
            j++;
        }
        printf("\nWhat would you like to do??\n1 - Enter measurement data  \n2 - Exit \n");
        printf("\ninput ");
        scanf_s("%c", &input);
        while ((getchar()) != '\n');
        if ((input - 48 >= 1) && (input - 48 <= 2)) {
            if (input == '1') {
                printf("\nEnter the number of measurements: ");
                scanf_s("%c", &n);
                while ((getchar()) != '\n');
                data = (int*)malloc(n * sizeof(int));
                for (int i = 0; i < n - 48; i++) {
                    printf("\nEnter measurement data %d(in format XXX [000; 999])\n--------\n", i+1);
                    printf("Enter the width of the river (m): ");
                    fgets(s, 4, stdin);
                    while ((getchar()) != '\n');
                    printf("Enter the depth of the river (m): ");
                    fgets(h, 4, stdin);
                    while ((getchar()) != '\n');
                    printf("Enter river speed (m/s) : ");
                    fgets(v, 4, stdin);
                    while ((getchar()) != '\n');
                    data[i] = ((atoi(s) * atoi(h)) / 2 * atoi(v));
                }
                for (int i = 0; i < n - 48; i++)
                {
                    printf("\nMeasurement data N%d = %d m^3", i + 1, data[i]);
                }
                do {
                    printf("\nDo you want to continue? (Y/N): ");
                    scanf_s("%c", &check);
                    if (check == 'Y' || check == 'y') {
                        break;
                    }
                    if (check == 'N' || check == 'n') {
                        return 0;
                    }
                    if (check != 'Y' || check != 'y') {
                        printf("\nPlease enter the correct letter!\n");
                    }
                    printf("\n");
                } while (true);
            }
            if (input == '2') {
                return 0;
            }
        }
        else {
            printf("\nPlease enter the correct number!\n");
        }
        
        
    } while (true);

    return 0;
}

#include <stdio.h>

int main()
{
    int s;
    printf("Enter s: ");
    scanf_s("%d", &s);

    int buf = s % 10, f = 0, t=0;
    s -= buf;
    
    if (s > 9) {
        while (1 == 1) {
            if (buf % 3 == 0 && s % 5 == 0) {
                t = buf / 3;
                f = s / 5;
                break;
            }
            else {
                buf += 5;
                s -= 5;
            }
        }
    }
    else if (buf == 8) {
        t = 1;
        f = 1;
    }
    else if (buf == 9)
        t = 3;
    else{
        printf("\nERROR.");
        return 1;
    }
        

    printf("\nThree= %d\nFive= %d", t, f);
}


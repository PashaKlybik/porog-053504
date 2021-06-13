#include <stdio.h>

int main()
{
    int a, num, N;

    printf("\n\n Enter a: "); //10111213141516171819...
    do 
    {
        scanf("%d", &a);
        if (a < 1 || a > 180)
        {
            printf("The number should be between 1 and 180!\nPlease try again: ");
        }
    } 
    while (a < 1 || a > 180);

    N = a;
    for (int i = 10; a; i++)
    {
        num = (i / 10) % 10;
        a--;
        if (a)
        {
            num = i % 10;
            a--;
        }
    }
    printf("%d number in the sequence is:  %d\n", N, num);
    getchar();
    return 0;
}
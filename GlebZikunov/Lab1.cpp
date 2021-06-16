#include <stdio.h> 

int main()
{
    int i;
    printf("\n\n\n\t\t\t\t");

    for (i = 1; i <= 1000; i++)
    {
        if ( i == (i * i) % 10 && i < 9)
        {
            printf("%d\t", i);
        }

        else if (i == (i * i) % 100 && i > 9 && i < 99)
        {
            printf("%d\t", i);
        }

        else if (i == (i * i) % 1000 && i > 99)
        {
            printf("%d\t", i);
        }

    }

    printf("\n\n\n");

    return 0;
}

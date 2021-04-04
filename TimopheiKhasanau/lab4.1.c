#include <stdio.h>

int length(char* str)
{
    int i =0;
    while(str[i])
    {
        i++;
    }
    return i;
}
 unsigned long long int stoI(int size, char *string)
{
    if (size == 1) {
        return (*string - 48);
    }
    else
    {
        return (string[size-1] -48  + 10 * stoI(size-1, string));
    }

}

int main()
{
    _Bool run = 1;
    int amount =0;
     unsigned long long int answ =0 ;
    char str[21];

    printf("Enter string of numbers\n");
    scanf("%20[0-9]", str);
    amount = length(str);
    answ = stoI(amount, str);
    printf("Result:  %llu", answ);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>


char* itob(int num, char* buffer, int base)
{
    if (!num)
        return '\0';

    char res;
    int i, LEN = strlen(buffer);
    if (num % base > 9) res = (char)(num % base - 10) + 'A';
    else res = (char)(num % base) + '0';

    for (i = LEN; i > -1; i--)
        buffer[i + 1] = buffer[i];
    buffer[0] = res;

    itob(num / base, buffer, base);
    return buffer;
}


int main()
{
    int b;
    long n;
    printf( "Enter number\nn = ");
    scanf_s( "%ld",&n);
    printf( "Enter system\nb = ");
    scanf_s("%d", &b);
    char buf[80] = "";
    itob(n, buf, b);
    printf("Number %ld in %d system = %s\n", n,b,buf);
    return 0;
}
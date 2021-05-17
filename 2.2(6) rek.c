#include <stdio.h>
#include<math.h>

long double Fact(int n);
float Find(float x, float e, int n, float raz);

int main()
{
    float x, e, raz = 0;
    int n = 1;
    float a = n - 1;
    float b = 2 * n - 1;

    printf("Enter x: ");
    scanf_s("%f", &x);
    printf("Enter e: ");
    scanf_s("%f", &e);
    
    printf("n= %f", Find(x, e, n, raz));

}

long double Fact(int n) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return n * Fact(n - 1);
}

float Find(float x, float e, int n, float raz) { 
   float a = n - 1;
   float b = 2 * n - 1;

   raz += pow(-1, a) * pow(x, b) / Fact(2 * n - 1);
   if (fabs(sin(x) - raz) < e)
       return n;
   else
       return Find(x, e, n + 1, raz);

}


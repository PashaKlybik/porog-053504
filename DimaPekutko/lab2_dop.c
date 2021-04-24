#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M_PI 3.14159265358979323846

// dop task 2.2.6
float getDouble()
{
    long double n;
    char c;
    while(1)
    {
        // scanf will return 2 if the conversion is succesful, i.e.
        // if it could scan first an integer and then a character
        if (scanf("%Lf%c", &n, &c) == 2 && c == '\n') return n;

        // Conversion failed so flush the input stream
        // Keep reading from input stream until a newline is read
        long double c;
        do
        {
            if ((c = getchar()) == EOF) exit(1);
        } while (c != '\n');
    }
}
    
unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

void iteration(long double x, long double epsilon) {
    long double sum = 0;
    long double currentVal;
    long double sinx = sinf(x);
    long double diff;
    int n = 1;
    while(1) {
         currentVal = pow((-1), (n-1))*((pow(x, (2*n-1)))/(factorial(2*n-1)));
         sum += currentVal;
         diff = fabs(sinx-sum);
         if(diff < epsilon) {
            printf("sum=%.10Lf, n=%d for sin(x)=%.10Lf (in rad), epsilon=%.10Lf\n", sum, n, sinx, epsilon);
            return;
         }
         else {
             n++;
         } 
    }
}

long double recursive(long double x, long double epsilon, int n, long double sum) {
    long double currentVal;
    long double sinx = sinf(x);
    long double diff;
    currentVal = pow((-1), (n-1))*((pow(x, (2*n-1)))/(factorial(2*n-1)));
    sum += currentVal;

    diff = fabs(fabs(sinx)-fabs(sum));
    if(diff < epsilon) {
        printf("sum=%.10Lf, n=%d for sin(x)=%.10Lf (in rad), epsilon=%.10Lf\n", sum, n, sinx, epsilon);
        return sum;
    }
    else {
         n++;
         return recursive(x, epsilon, n, sum);
    } 
}

int main() {
    long double x, epsilon, sinx;

    printf("Your x: ");
    x = getDouble();
    printf("Your epsiolon: ");
    epsilon = getDouble();
    
    if(x > 180) {
        x-=(180*(int)(x/180));
    }
    x = (long double)x/180*3.14;
    sinx = sinf(x);

    printf("sinx=%.10Lf\n", sinx);
    printf("\n_____iteration_____\n");
    iteration(x, epsilon);
    printf("\n_____recursive_____\n");
    double sum = recursive(x, epsilon, 1, 0);
    printf("sum=%lf\n", sum);
    return 0;
}



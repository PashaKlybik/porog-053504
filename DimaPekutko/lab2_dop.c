#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M_PI 3.14159265358979323846

// dop task 2.2.6
float getFloat()
{
    float n;
    char c;
    while(1)
    {
        // scanf will return 2 if the conversion is succesful, i.e.
        // if it could scan first an integer and then a character
        if (scanf("%f%c", &n, &c) == 2 && c == '\n') return n;

        // Conversion failed so flush the input stream
        // Keep reading from input stream until a newline is read
        float c;
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

void iteration(float x, float epsilon) {
    float sum = 0;
    float currentVal;
    int n = 1;
    while(1) {
         currentVal = pow((-1), (n-1))*((pow(x, (2*n-1)))/(factorial(2*n-1)));
         sum += currentVal;
        //  printf("sum=%f\n", sum);
         if(fabs(sum-(sum-currentVal)) < epsilon) {
             printf("sum=%f, n=%d for x=%f(in rad), epsilon=%f\n", sum, n, x, epsilon);
             return;
         }
         else {
             n++;
         } 
    }
}

void recursive(float x, float epsilon, int n, float sum) {
    float currentVal;
    currentVal = pow((-1), (n-1))*((pow(x, (2*n-1)))/(factorial(2*n-1)));
    sum += currentVal;

    if(fabs(sum-(sum-currentVal)) < epsilon) {
        printf("sum=%f, n=%d for x=%f(in rad), epsilon=%f\n", sum, n, x, epsilon);
        return;
    }
    else {
         n++;
         recursive(x, epsilon, n, sum);
    } 
}

int main() {
    float x, epsilon, sinx;

    printf("Your x: ");
    x = getFloat();
    printf("Your epsiolon: ");
    epsilon = getFloat();
    
    if(x > 180) 
        x -= 180/(float)(x/180);
    x = (float)(x/180*3.14);
    sinx = sinf(x);

    printf("sinx=%f\n", sinx);
    printf("\n_____iteration_____\n");
    iteration(x, epsilon);
    printf("\n_____recursive_____\n");
    recursive(x, epsilon, 1, 0);

    return 0;
}



#include <stdio.h>
#include <math.h>



int fact(int n);
float recursion(float x, float accuracy, float value, float* n);
int iter(float x, float accuracy, float* n);

int main() {
    float  x = 0, counter = 1, accuracy = 0;

    printf("input  x: ");
    scanf("%f", &x);

    printf("set accuracy: ");
    scanf("%f",&accuracy);

    printf("Sin(x): %f\n", sinf(x));
    printf("Result: %f\n n = %d", iter(x, accuracy, &counter), counter);
    counter = 1;
    printf("recursion: %f\n ", recursion(x, accuracy, 0, &counter));

    return 0;
}

int fact(int n) {
    return n == 0 ? 1 : n * fact(n-1);
}

float recursion(float x, float accuracy, float value, float* n) {
    float cur = (powf(-1,(*n)-1) * powf(x, 2*(*n)-1)/fact(2*(*n)-1));

    value -= cur;

    if(fabs(value) <  accuracy) return value;

    (*n)++;


    return (value + recursion(x, accuracy, value, n));
}

int iter(float x, float accuracy, float* n) {
    float expression = 0, result = 0, orig = sinf(x);

    do
    {
        expression = powf(-1,(*n)-1) * powf(x, 2*(*n)-1) / fact(2*(*n)-1);
        result += expression;
        (*n)++;
    }
    while (fabs(expression - orig) <= accuracy);

    return result;
}

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//variant 6

struct {
    int userWeight;
    int userDist;
    int carsCount;
    int maxCargo;
    int pricePerKilo;
    int minWeight;
    int maxDist;
    float insurancePercent;
} Company = {0,0,15,20,2,50,4000,0.05};

void flushInput()
{
    // Keep reading from input stream until a newline is read
    int c;
    do
    {
        if ((c = getchar()) == EOF) exit(1);
    } while (c != '\n');
}

int getInt()
{
    int n;
    char c;
    while(1)
    {
        // scanf will return 2 if the conversion is succesful, i.e.
        // if it could scan first an integer and then a character
        if (scanf("%d%c", &n, &c) == 2 && c == '\n') return n;

        // Conversion failed so flush the input stream
        flushInput();
    }
}

void input() {
    printf("Input the weight: ");
    Company.userWeight = getInt(); 
    printf("Input the distance: ");
    Company.userDist = getInt();
}

bool analysis() {
    if(Company.userDist > Company.maxDist) {
        printf("Sorry, but dist is too large.\n");
        return false;
    }
    if(Company.userWeight < Company.minWeight) {
        printf("Sorry, but weight is to small.\n");
        return false;
    }
    return true;
}

void showPrice() {
    int carsNeed = Company.userWeight/Company.maxCargo;
    if(carsNeed > Company.carsCount) {
        carsNeed = Company.carsCount;
        Company.userDist *= (Company.userWeight/Company.carsCount)/Company.maxCargo;
        //printf("!!!%d\n", Company.userDist);
    }
    int price = Company.userDist*Company.pricePerKilo*carsNeed;
    int finalPrice = price + price*Company.insurancePercent;
    int printPercent = Company.insurancePercent*100;	
    printf("Need cars for the distance: %d\n", carsNeed);
    printf("Transportation price: %d$\n", price);
    printf("Total price (with insurance in %d%%): %d$\n", printPercent, finalPrice);
}

int main(void) {
    while(true) {
        system("clear");
        input();
        if(analysis()) {
            showPrice();
        }
        else {
            printf("Sorry, but we cant accept your order.");
        }
        printf("Press 1 to restart, press anything else to exit:"); 
        int restart = getInt();
        if(restart == 1){
           Company.userWeight = 0;
           Company.userDist = 0;
           Company.carsCount = 15;
           Company.maxCargo = 20;
           Company.pricePerKilo = 2;
           Company.minWeight = 50;
           Company.maxDist = 4000;
           Company.insurancePercent = 0.05;
           continue;
        }
        else {
            printf("Program made by @dkefir03 (Dmitry Pekutko)\n");
            return 0;
        }
    }
    return 0;
}









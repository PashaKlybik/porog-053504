// Programming 2 laba 1 task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

float CarEuropePrice, Distance,Capacity;
int Year;

float EnterCarPriceInEurope() {
    printf("Car Price in Europe is (price in EURO) : ");
    scanf_s("%f", &CarEuropePrice);
    return CarEuropePrice;
}
int EnterTheYearOfTheIssue() {
    printf("Year of the car manufacture is : ");
    scanf_s("%d", &Year);
    return Year;
}
float EnterEngineCapacity() {
    printf("Capacity of the engine is (cm.cube) : ");
    scanf_s("%f", &Capacity);
    return Capacity;
}
float EnterDistanceOfTheRun() {
    printf("Distance of the run is (kilometers) : ");
    scanf_s("%f", &Distance);
    return Distance;
}
float CalculateTheFinalPriceOfTheCar() {
    float FinalDistancePrice;
    float PriceOfOneKilometer = 0.5;
    FinalDistancePrice = Distance * PriceOfOneKilometer;
    printf("\nPrice of the distance haul is : %f EURO ", FinalDistancePrice);
    float CarClearancePrice;
    int CurrentYear = 2021;
    if (Year >= CurrentYear - 3) {
        CarClearancePrice = Capacity * 0.6;
        printf("\nCar age is less than 3 years. \nPrice for the customs clearance is : %f EURO ", CarClearancePrice);
    }
    else if(Year < CurrentYear - 3 && Year >= CurrentYear - 10){
        if (Capacity < 2500) {
            CarClearancePrice = Capacity * 0.35;
            printf("\nCar age is more than 3 years,but less than 10 years. Engine capacity is less than 2500 cm.cube.\n Price for the customs clearance is : %f EURO ", CarClearancePrice);
        }
        else {
            CarClearancePrice = Capacity * 0.6;
            printf("\nCar age is more than 3 years,but less than 10 years. Engine capacity is more than 2500 cm.cube. Price for the customs clearance is : %f EURO ", CarClearancePrice);
        }
    }
    else if(Year < CurrentYear - 10 && Year >= CurrentYear - 14) {
        CarClearancePrice = Capacity * 0.6;
        printf("\nCar age is more than 10 years,but less than 14 years.\n Price for the customs clearance is : %f EURO ", CarClearancePrice);
    }
    else {
        CarClearancePrice = Capacity * 2;
        printf("\nCar age is more thsan 14 years.\n Price for the customs clearance is : %f EURO", CarClearancePrice);
    }
    float TheFinalPriceOfTheCar;
    TheFinalPriceOfTheCar = CarEuropePrice + FinalDistancePrice + CarClearancePrice;
    printf("\nThe final price of the car(including car age,engine capacity,price of the distance haul,price of the customs clearance) is : %f EURO", TheFinalPriceOfTheCar);
    return CarClearancePrice;
}
void InformationOfTheCreator() {
    printf("This calculation is actual for 2021 year.\nCreator of this car calculation is Matvey Maximov.");
}

int main()
{
    float CarEuropePrice, Distance;
    int Year, Capacity,a;
    EnterCarPriceInEurope();
    EnterTheYearOfTheIssue();
    EnterEngineCapacity();
    EnterDistanceOfTheRun();
    CalculateTheFinalPriceOfTheCar();
    printf("\n\n\nIf you want to know the information of the program and creator,tab '1' : ");
    scanf_s("%d", &a);
    if (a == 1) {
        InformationOfTheCreator();
    }
    return 0;
}


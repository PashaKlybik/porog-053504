#include <stdio.h>
#include <math.h>

float lencalc()
{
    int x1,y1,x2,y2;
    float len;

    printf_s("First point\n(x, y):\n");
    scanf_s("%d %d",&x1, &y1);
    printf_s("Second point\n(x, y):\n");
    scanf_s("%d %d",&x2, &y2);

    len = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

    return len;
}

float angle(float a, float b, float c)
{
    double angle=0;
    double proto = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);

    angle = 180 * acos(proto) / 3.14;

    return (float)angle;
}

void type( float angle1, float angle2, float angle3 )
{
    if((int)angle1==90|| (int)angle2 == 90|| (int)angle2 == 90)
    {
        printf_s("Type of the triangle: Right\n\n");
    }
    if ((int)angle1 > 90 || (int)angle2 > 90 || (int)angle2 > 90)
    {
        printf_s("Type of the triangle: Acute\n\n");
    }
    if ((int)angle1 < 90 && (int)angle2 < 90 && (int)angle2 < 90)
    {
        printf_s("Type of the triangle: Obtuse\n\n");
    }

}

void per(float a, float b, float c)
{
    float sum = a + b + c;
    printf_s("Perimetr: %.2f\n\n", sum);
}

void area(float a, float b, float c)
{
    float polper = (a + b + c) / 2;
    float area =sqrt(polper * (polper - a) * (polper - b) * (polper - c));
    printf_s("Area: %.2f\n\n", area);
}

int main() {
    int choice =0;
    _Bool run= 1, triangle=1;

    float sideA = 1, sideB = 1, sideC = 1, angle1 = 60, angle2 = 60, angle3 = 60;


    while(run)
    {

        printf_s("\nSet points(1)\nBuildTriangle(2)\nTypeOfTriangle(3)\n"
                 "Perimetr(4)\nArea(5)\nInformation(6)\nExit(7)\n\n");

        printf_s("Choice:\n");
        scanf_s("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf_s("\nEnter x-, y-coordinates of six points(two for each side):\n");

                sideA = lencalc();
                sideB = lencalc();
                sideC = lencalc();

                angle1=angle(sideA,sideB,sideC);
                angle2=angle(sideC,sideB,sideA);
                angle3=angle(sideA,sideC,sideB);

                printf_s("\nSide A:%.2f\nSide B:%.2f\nSide C:%.2f  \n\n", sideA, sideB, sideC);
                continue;
            }

            case 2:
            {
                printf_s("Triangle test: \n");

                if( sideA+sideB < sideC && sideB+sideC < sideA && sideC+sideA < sideB)
                {
                   printf_s("It's not a triangle!\n\n");
                   triangle = 0;
                }
                else
                {
                    triangle = 1;
                    printf_s("It's a triangle \n\n");
                }
                continue;
            }

            case 3:
            {
                if(triangle==0)
                {
                    printf_s("It's not a triangle! Try again \n\n");
                }
                else
                {
                    printf_s("\nAngle A:%.1f deg\nAngle B:%.1f deg\nAngle C:%.1f deg \n\n", angle1, angle2, angle3);
                    type(angle1,angle2,angle3);
                }
                continue;
            }
            case 4:
            {
                if(triangle==0)
                {
                    printf_s("It's not a triangle! Try again \n\n");
                }
                else
                {
                    per(sideA, sideB, sideC);
                }
                continue;
            }
            case 5:
            {
                if(triangle==0)
                {
                    printf_s("It's not a triangle! Try again \n\n");
                }
                else
                {
                    area(sideA, sideB, sideC);
                }
                continue;
            }
            case 6:
            {
                printf_s("Author: Timophei Khasanau, group 053504\n"
                         "Program:\nname: ThreeSegments\nversion: 1.1 beta\n"
                         "Thank for using!\n\n");
                continue;
            }
            case 7:
            {
                printf_s("Work completed\n\nThank for using!\n ");
                run = 0;
                break;
            }
            default:
                continue;
        }

    }

    return 0;
}

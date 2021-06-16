#include <stdio.h>
#include <conio.h>
#include <math.h>

int Menu();
float Segment(char text[2]);
void Perimeter(float,float,float);
int Kind_of_triangle(float,float,float);
float Area_of_triangle(float,float,float,int);
float Radius_opis(float,float,float,int);
float Radius_vpis(float,float,float,int);

int main()
{
    printf("\tTriangle");
    int choise;
    float AB,BC,AC;
    do
   {
    choise = Menu();
    int k,k1;
    switch (choise)
    {
    case 1:
    printf("Enter coord A,B,C\n");
    AB = Segment("AB");
    BC = Segment("BC");
    AC = Segment("AC");  
    break;

    case 2:
    printf("Kind of triangle : ");
    int kind = Kind_of_triangle(AB,BC,AC);
    if (kind == 0)
    {
        printf("\nIsosceles triangle"); // равнобедренный
    }
    else if (kind == 1)
    {
        printf("\nRight triangle"); // прямоугольный
    }
    else if (kind == 2)
    {
        printf("\nRegular triangle"); // правильный
    }
    else if (kind == 3)
    {
        printf("\nArbitrary triangle"); // произвольный
    }
    break;

    case 3:
    printf("Perimeter of a triangle = ");
    Perimeter(AB,AC,BC);
    break;

    case 4:
    k = Kind_of_triangle(AB,BC,AC);
    float area;
    area = Area_of_triangle(AB,BC,AC,k);
    printf("\nArea of a triangle = %0.3f",area);
    break;

    case 5:
    k1 = Kind_of_triangle(AB,BC,AC);
    printf("\nR = %0.3f\n",Radius_opis(AB,BC,AC,k1));
    printf("r = %0.3f", Radius_vpis(AB,BC,AC,k1));
    break;

    case 6:
    printf("\n version 1.0 \n created by Ilya Virich\n");
    break;

    case 7:
    printf("\nEnd.");
    break;

    default:
    printf(" Wrong input! ");
    }

    choise = 7;
    char ch;
    printf("\nContinue? y/z \n");
    ch = getch();
    if(ch == 'y')
        choise = 0;
    else if (ch == 'z')
        choise = 7;

   } while(choise!=7);

    getch();
}

int Menu()
{
    int variant;
    printf("\n Select option");
    printf("\n 1.Enter coord\n 2.Kind of triangle\n 3.Perimetr\n 4.Square\n 5.Radius okr\n 6.Information about the version and the author of the program\n 7.Exit\n >>> ");
    scanf("%d",&variant);
    return variant;
}

float Segment(char text[2])
{
    printf("\nSegment %s\n",text);
    int x1,y1,x2,y2;
    float otr;
    printf("Coord %c\n",text[0]);
    printf("x1 = ");
    scanf("%d",&x1);
    printf("y1 = ");
    scanf("%d",&y1);

    printf("\nCoord %c\n",text[1]);
    printf("x2 = ");
    scanf("%d",&x2);
    printf("y2 = ");
    scanf("%d",&y2);

    otr = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    printf("%s = %0.2f\n",text,otr);
    return otr;
}

void Perimeter(float a, float b, float c) 
{
    printf("%0.3f", a + b + c);
}

int Kind_of_triangle(float a,float b,float c)
{
    int kind;

    if (a==b || a==c ||b==c) // ravnobedr
    {
      kind = 0; 
    }
    else if(a == sqrt(pow(b,2) + pow(c,2)) || b == sqrt(pow(a,2) + pow(c,2)) || c == sqrt(pow(a,2) + pow(b,2)))
    {
        kind = 1; //premoyg
    }
    else if(a==b,b==c)
    {
        kind = 2; //pravil
    }
    else if(a<b<c || a>b>c)
    {
        kind = 3; //proisf
    }

    return kind;
}

float Area_of_triangle(float a,float b,float c,int k)
{
    float area,p;
    switch (k)
    {
    case 0:
    p = (a+b+c)/2.0;
    area = sqrt(p*(p-a)*(p-b)*(p-c)); 
    break;
    
    case 1:
    if(a == sqrt(pow(b,2) + pow(c,2)))
    {
        area = (b*c)/2;
    }
    else if (b == sqrt(pow(a,2) + pow(c,2)))
    {
        area = (a*c)/2;
    }
    else
    {
        area = (a*b)/2;
    }
    break;

    case 2:
    area = (sqrt(3)/4.0)*pow(a,2);
    break;
    
    case 3:
    p = (a+b+c)/2;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    break;
    }

    return area;
}

float Radius_vpis(float a,float b,float c,int k)
{
    float r;
    float p = (a+b+c)/2;
    r = sqrt((p-a)*(p-b)*(p-c)/p);
    return r;

}

float Radius_opis(float a,float b,float c,int k)
{
    float R;
    if (k = 1)
    {
        if (a == sqrt(pow(b,2) + pow(c,2)))
        {
            R = a/2;
        }
        else if (b == sqrt(pow(a,2) + pow(c,2)))
        {
            R = b/2;
        }
        else
        {
            R = c/2; 
        }
    }
    else
    {
            R = (a*b*c)/(4 * Area_of_triangle(a,b,c,k));
    }
    return R;
}
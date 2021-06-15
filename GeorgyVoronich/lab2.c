#define PI 3.14

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct Planet {
	long double weight, radius, speed;
};

long double getYearLength(struct Planet planet) {
	return 2 * PI * planet.radius / planet.speed;
}
long double getPlanetDistance(struct Planet planet1, struct Planet planet2, long double time) {
	long double angle1 = planet1.speed / planet1.radius * time;
	long double angle2 = planet2.speed / planet2.radius * time;
	long double resAngle = fabs(angle1 - angle2);
	return sqrtl(powl(planet1.radius, 2) + powl(planet2.radius, 2) - 2 * planet1.radius * planet2.radius * cos(resAngle));
}
long double getPlanetGravity(struct Planet planet1, struct Planet planet2, long double time) {
	return 6.67 * planet1.weight * planet2.weight / powl(getPlanetDistance(planet1, planet2, time), 2);
}
struct Planet enterPlanetData() {
	long double weight, radius, speed;
	printf("Weight, radius, speed: ");
	scanf("%Lf %Lf %Lf", &weight, &radius, &speed);
	struct Planet planet = { weight, radius, speed };
	return planet;
}

int main(int argc, char* argv[])
{
	struct Planet planets[3];
	for (int i = 0; i < 3; i++) {
		printf("E2G_%d\n", i + 1);
		planets[i] = enterPlanetData();
	}

	char choice = 'y';
	while (tolower(choice) == 'y')
	{
		printf(
			"1. Enter planet data\n\
		2. Get planets years long\n\
		3. Get distance between planets\n\
		4. Get planets gravities\n"
		);

		scanf("\n%c", &choice);
		if (choice == '1') {
			int planetNumber;
			printf("Planet number: ");
			scanf("%d", &planetNumber);
			if (planetNumber > 0 && planetNumber < 4) {
				planets[planetNumber - 1] = enterPlanetData();
			}
			else {
				printf("Wrong value\n");
			}
		}
		else if (choice == '2') {
			for (int i = 0; i < 3; i++) {
				printf("E2G_%d's year long: %Lf\n", i + 1, getYearLength(planets[i]));
			}
		}
		else if (choice == '3') {
			long double time;
			printf("Enter time: ");
			scanf("%Lf", &time);
			if (time >= 0) {
				printf("Distance between E2G_%d and E2G_%d: %Lf\n", 1, 2, getPlanetDistance(planets[0], planets[1], time));
				printf("Distance between E2G_%d and E2G_%d: %Lf\n", 1, 3, getPlanetDistance(planets[0], planets[2], time));
				printf("Distance between E2G_%d and E2G_%d: %Lf\n", 2, 3, getPlanetDistance(planets[1], planets[2], time));
			}
			else {
				printf("Incorrect time\n");
			}

		}
		else if (choice == '4') {
			long double time;
			printf("Enter time: ");
			scanf("%Lf", &time);
			if (time >= 0) {
				printf("Gravity between E2G_%d and E2G_%d: %Lf\n", 1, 2, getPlanetGravity(planets[0], planets[1], time));
				printf("Gravity between E2G_%d and E2G_%d: %Lf\n", 1, 3, getPlanetGravity(planets[0], planets[2], time));
				printf("Gravity between E2G_%d and E2G_%d: %Lf\n", 2, 3, getPlanetGravity(planets[1], planets[2], time));
			}
			else {
				printf("Incorrect time\n");
			}
		}
		else {
			printf("Wrong value\n");
		}
		printf("Do you want to continue(Y/n)\n");
		scanf("\n%c", &choice);
	}
	return 0;
}


//ВНИМАНИЕ ЗАДАНИЕ 2.2.6!!!



#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough

const double Pi = 3.1415926535897932;

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0'){
        i++;
    }

    return i ;
}

double binpow (int a, int n) {        /// V STEPEN
	if (n == 0)
		return 1;

    if (n<0){
        if ((-1*n) % 2 == 1)
            return binpow (a, n+1) * (1.0/a);
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
    if (n>0){
        if (n % 2 == 1)
            return binpow (a, n-1) * a;
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
}

double binfact (int n)
{
    int r = 1;

    for (int i=2; i<=n; i++)
    {
        r *= i;
    }

    return r;
}

double Perevodvdouble(char n[])
{
    double chislo = 0;
    int BeforeDot = 0;
    int AfterDot = 0;
    int Dot = 0;

    int i=0;
    while (n[i]!=',' && n[i]!='.' && n[i]!='\0'){
        BeforeDot++;
        i++;
    }
    i = 0;
    while (n[i]!='\0'){
        if (n[i]==',' || n[i]=='.'){
            Dot++;
        }
        i++;
    }

    if (Dot == 1){
        AfterDot = razmer(n) - BeforeDot - 1;
    }

    int flag = 0;
    int NumAfterDot = 0;
    i=0;
    while (n[i]!='\0'){

        if (n[i]==',' || n[i]=='.'){
            flag = 1;
        }

        if (flag == 0){
            chislo += binpow(10, (BeforeDot - i - 1)) * (n[i] - '0');
        }
        else if (flag == 1 && n[i]!='.' && n[i]!=','){
            chislo += binpow(10, (NumAfterDot) ) * (n[i] - '0');
        }

        if (flag){
            NumAfterDot--;
        }

        i++;
    }

    return chislo;
}

int isdouble(char n[])  ///FUNCTION OF CHECKING OF DOUBLE INPUT
{
    if (razmer(n)>27 || n[0] == ',' || n[0] == '.'){
        return 0;
    }

    int counter = 0;
    int dotorcomma = 0;
    int ZnakAfterdotOrComma = 0;
    int i=0;
    while (n[i]!='\0'){
        if (isdigit(n[i]) == 0){
            if (n[i]=='.' || n[i]==','){
                dotorcomma++;
            }
            else {
                counter++;
            }
        }
        i++;
    }

    if (dotorcomma>1 || counter>0){
        return 0;
    }

    int flag = 0;
    i = 0;
    while (n[i]!='\0'){
        if (flag){
            ZnakAfterdotOrComma++;
        }

        if (n[i] == '.' || n[i] == ','){
            flag = 1;
        }

        i++;
    }

    if (ZnakAfterdotOrComma>16 || Perevodvdouble(n) > MAX_DOUBLE){
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
//    double x = 0;
//    double epsilon = 0;
    double OurSin = 0;
    char x[28] = "nothing";
    char epsilon[28] = "nothing";



    printf("Enter an x : ");
    scanf("%s", x);
    //scanf("%lf", &x);
    while (isdouble(x)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", x);
    }


    printf("Enter an epsilon : ");
    scanf("%s", epsilon);
//    scanf("%lf", &epsilon);
    while (isdouble(epsilon)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", epsilon);
    }

    OurSin = sin(Perevodvdouble(x));
    printf("Sin (x) = %lf\n", OurSin);

    double OurExpression = Perevodvdouble(x) ;
    double Factor = 1;
    int n = 2;
    while ( fabs(OurExpression - OurSin) > Perevodvdouble(epsilon) )
    {
        Factor *= (n-1)*2*((n-1)*2+1);
        OurExpression += pow(-1, n-1) * ( pow( Perevodvdouble(x) ,(2*n - 1)) /  Factor );
        n++;
    }

    printf("OurExpression = %lf\n", OurExpression);
    printf("Otvet : n = %d\n", n);



    return 0;
}

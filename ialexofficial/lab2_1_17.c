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
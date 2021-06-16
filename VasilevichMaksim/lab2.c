#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ������� 2.1 (27)

int cCement = 230; int cCementS = 160;
int cGraviy = 142; int cGraviyS = 96;
int cBeton = 260; int cBetonS = 205;
int maxVagon = 50;
int dBelarus = 200; int dRussia = 320; int dUkraine = 320; int dMoldavia = 360;
int badProfit = 25000;

void material(const char* material, const char* material_a, int cMaterial, int cMaterialS);

int main(void) {
	char* locale = setlocale(LC_ALL, "");
	int nextStep = 0;

	do {
		printf("------------------------- MENU --------------------------------\n");
		printf("1. ������� ����� �� ������\n2. C������ ����� �� ������\n3. ������� ����� �� �����\n4. ��������� ���������\n");
		printf("---------------------------------------------------------------\n");
		printf("������� �����: ");
		while (!scanf("%d", &nextStep) || nextStep <= 0 || nextStep >= 5) {
			while (getchar() != '\n');
			printf("�����������. ���������� ��� ���...\n");
			printf("------------------- MENU --------------------------\n");
			printf("1. ������� ����� �� ������\n2. C������ ����� �� ������\n3. ������� ����� �� �����\n4. ��������� ���������\n");
			printf("---------------------------------------------------\n");
			printf("������� �����: ");
		} 
		while (getchar() != '\n');

		switch (nextStep) 
		{
		case 1:
			material("������", "�������", cCement, cCementS);
			break;
		case 2:
			material("������", "������", cGraviy, cGraviyS);
			break;
		case 3:
			material("�����", "������", cBeton, cBetonS);
			break;
		case 4:
			printf("��������� ���������� ������ ���������. Version 2.2.8.");
			break;
		default: return 0;
		}



	} while (nextStep != 4);

	return 0;
}

int chooseCountry();
int countVagons(float weight);
float getWeight();
bool readyOrder();
void material(const char* material, const char* material_a, int cMaterial, int cMaterialS) {
	float weight = 0.0;
	int amountVagons = 0;
	int costOneVagon = 0;
	float costMaterials = 0.0;
	int costVagons = 0;
	float costOrder = 0.0;
	float profit = 0.0;

	costOneVagon = chooseCountry();
	printf("1 ����� %s ����� ������ $%d\n", material, cMaterial);
	weight = getWeight();
	costMaterials = weight * cMaterial;
	amountVagons = countVagons(weight);
	costVagons = amountVagons * costOneVagon;
	printf("��������� ����������: $%f\n", costMaterials);
	printf("��������� ��������: $%d\n", costVagons);	

	profit = weight * (cMaterial - cMaterialS) - costVagons;
	costOrder = weight * cMaterial + costVagons;
	if (profit <= badProfit) {
		printf("������� �������� ����� ���� $%f, ��� ����� ����, �������� ����� �����...\n", profit);
		return;
	}
	else if (readyOrder()) {
		printf("������� ����������� ��������: $%f\n", profit);
		printf("����� ��������� ��������: $%f\n", costOrder);
		return;
	}
	else return;
}
bool readyOrder() {
	char is[5];
	printf("��������� ���� ����� (yes), ��� ������� ����� (no): ");

	while (!scanf("%s", &is) || strcmp(is, "yes") != 0 || strcmp(is, "no") != 0) {
		if (strcmp(is, "yes") == 0) break;
		if (strcmp(is, "no") == 0) break;
		while (getchar() != '\n');
		printf("����� ����� �� ���...\n");
		printf("��������� ���� ����� (yes), ��� ������� ����� (no): ");
	}
	while (getchar() != '\n');
	if (!strcmp(is, "yes")) return true;
	else if (!strcmp(is, "no")) return false;
	else return readyOrder();
}
int chooseCountry() {
	printf("�������� ������ ��������: ");
	char country[50];
	//fgets(country, 50, stdin);
	//while (getchar() != '\n');

	while (!scanf("%s", &country) || strcmp(country, "Belarus") != 0 || strcmp(country, "Russia") != 0 || strcmp(country, "Ukraine") != 0 || strcmp(country, "Moldavia") != 0) {
		if (strcmp(country, "Belarus") == 0) break;
		if (strcmp(country, "Russia") == 0) break;
		if (strcmp(country, "Ukraine") == 0) break;
		if (strcmp(country, "Moldavia") == 0) break;
		while (getchar() != '\n');
		printf("�� ���������� ������ ������ � ��� ������: Belarus, Russia, Ukraine, Moldavia\n");
		printf("�������� ������ ��������: ");
	}
	while (getchar() != '\n');
	if (!strcmp(country, "Belarus")) return dBelarus;
	else if (!strcmp(country, "Russia")) return dRussia;
	else if (!strcmp(country, "Ukraine")) return dUkraine;
	else if (!strcmp(country, "Moldavia")) return dMoldavia;
	else return chooseCountry();
}
int countVagons(float weight) {
	int c = 0;
	while (weight > 0.0) {
		weight -= 50;
		c++;
	}
	return c;
}
float getWeight() {
	float weight;
	printf("������� ��� ������ (�����): ");
	while (!scanf("%f", &weight) || weight <= 0.0 || weight >= 999999.9) {
		while (getchar() != '\n');
		printf("�����������. ���������� ��� ���... (������� ����� ����� �������)\n");
		printf("������� ��� ������ (�����): ");
	}
	while (getchar() != '\n');
	return weight;
}

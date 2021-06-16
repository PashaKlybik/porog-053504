#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
struct Date
{
	int d;
	int m;
	int y;
};
int main()
{
	struct Date max,min,date;
	int count = 0;
	FILE* fp;
	 fp=fopen("DATA.txt", "r");
	 if (fp == NULL) { printf("Error!"); return 0; }
	
	 while (getc(fp) != EOF) {
		 if (fscanf_s(fp, "%d.%d.%d", &date.d, &date.m, &date.y) == 3)
		 {
			 count++;
			 break;
		 }		 
	 }
	 if(count==0)
	 {
		 fclose(fp);
		 puts("There is no dates in file!");
		 return 0;
	 }
	max = date;
	min = date;
	while (getc(fp) != EOF) {
		while (fscanf_s(fp, "%d.%d.%d", &date.d, &date.m, &date.y) == 3)
		{
			int cd = date.y * 100 + date.m * 10 + date.d;
			int mx = max.y * 100 + max.m * 10 + max.d;
			int mn = min.y * 100 + min.m * 10 + min.d;
			if (mn > cd)min = date;
			if (mx < cd)max = date;
		}
	}
	printf("min:%02d.%02d.%d\n", min.d, min.m, min.y);
	printf("max:%02d.%02d.%d\n", max.d, max.m, max.y);
	fclose(fp);
	return 0;
}
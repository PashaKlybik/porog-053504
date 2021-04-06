#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    FILE* fp;
    char name[] = "C:\\Users\\medve\\prog-053504\\my.txt";

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Couldn't open the file");
        getchar();
        return 0;
    }
    char str[80];
    struct tm *time_;
    time_t tt = time(NULL);
    time_ = localtime(&tt);
    printf("Time now\n");
    printf ("Day: %d\nMonth: %d\nYear: %d\n",time_->tm_mday,time_->tm_mon+1,time_->tm_year+1900);
    printf("\n");
    int loss;
    loss=0;

    while (fgets(str,80,fp)!=NULL)
    {
        char *p;
        p=strchr(str,' ')+1;// strchr Возвращает указатель на первое вхождение символа ' ' в строке str
        p[2]=' ';
        p[5]=' ';
        p[-1]='\0';
        int day,mon,year,count,price;
        sscanf ( p, "%d%d%d%d%d", &day, &mon, &year, &count, &price);
        printf("%s\n",str);
        printf("%d.%d.%d\nAmount %d\nPrice %d",day,mon,year,count,price);
        printf("\n");
        if (year > (time_->tm_year)+1900)  printf("%s is good\n",str);
        if (year < (time_->tm_year)+1900)
        {
            printf("%s is expired\n",str);
            loss=loss+count*price;
        }
        if (year==(time_->tm_year)+1900)
        {
            if (mon>(time_->tm_mon)+1) printf("%s is good\n",str);
            if (mon<(time_->tm_mon)+1)
            {
                printf("%s is expired\n",str);
                loss=loss+count*price;
            }
            if (mon==(time_->tm_mon)+1)
            {
                if (day>(time_->tm_mday)) printf("%s is good\n",str);
                if (day<=(time_->tm_mday))
                {
                    printf("%s is expired\n",str);
                    loss=loss+count*price;
                }
            }
        }
        printf("\n");
    }
    printf("Total loss %d BYR",loss);
    fclose(fp);
    getchar();
}

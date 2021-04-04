#include <stdio.h>
#include <math.h>
struct drug {
    char name[20];
    char date[10];
    int amount;
    int price;
};

void damage(struct drug shop[], int size)
{
    int damage =0;
    int year=0, day=0, month=0, fyear =0, fday =0, fmonth =0;
    printf("\n\nEnter border day: ");
    scanf_s("%d",&day);
    printf("\nEnter border month: ");
    scanf_s("%d",&month);
    printf("\nEnter border year: ");
    scanf_s("%d",&year);

    printf_s("\nBorder Date: [%d.0%d.%d]\n\n", day, month, year);
    printf_s("");

    for (int i = 0; i < size; i++)
    {
        fday =0;
        fmonth =0;
        fyear =0;
        for (int j = 0, z= 1; j < 2; j++, z--)
        {
            fday+= (shop[i].date[j]-48) *pow(10, z);
        }
        for (int j = 3, z= 1; j < 5; j++, z--)
        {
            fmonth+= (shop[i].date[j]-48) *pow(10, z);
        }

        for (int j = 6, z= 3; j < 10; j++, z--)
        {
            fyear+= (shop[i].date[j]-48) *pow(10, z);
        }

        if(fyear > year)
        {
            continue;
        }

        if(fyear < year)
        {
            fprintf(stderr,"[%s] -- EXPIRED\n", shop[i].name);
            damage+= (shop[i].price * shop[i].amount);
        }

        if(fyear == year)
        {
            if(fmonth > month)
            {
                continue;
            }

            if(fmonth < month)
            {
                fprintf(stderr,"[%s] -- EXPIRED\n", shop[i].name);
                damage+= (shop[i].price * shop[i].amount);
            }

            if(fmonth == month)
            {
                if(fday > day)
                {
                    continue;
                }

                if(fday <= day)
                {
                    fprintf(stderr,"[%s] -- EXPIRED\n", shop[i].name);
                    damage+= (shop[i].price * shop[i].amount);
                }
            }
        }

    }

    printf_s("\n\nOwn damage: %d$\n\n", damage);
}

int main()
{

    struct drug shop[10];

    int size =0;
    FILE *test = fopen("C:\\Git_rep\\prog-053504\\TimopheiKhasanau\\testForLab4.2.txt","r");
    if(!test)
    {
        printf("Error open\n");
        return 1;
    }

    while (fscanf(test, "%s %s %d %d",shop[size].name, shop[size].date,
                  &(shop[size].amount),&(shop[size].price)) != EOF)
    {
        printf("%s: [%s] %d packs, %d$\n", shop[size].name, shop[size].date,
               shop[size].amount, shop[size].price);
        size++;
    }
    damage(shop, size);
    return 0;
}

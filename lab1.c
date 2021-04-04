#include <stdio.h>
#include <math.h>

int main()
{
    _Bool run=1;
    unsigned long long int dec = 6, proto, lim_num = 0, limit;
    int counter= 0;
    printf_s(" enter limit number: \n");
    scanf_s("%llu",&lim_num );

    while(run==1)
    {
        limit = sqrtl(dec)+1;
        proto=0;
        for (unsigned long long int j = 1; j < limit; j++)
        {
            if( dec%j==0 )
            {
                proto+=j;
                if(j!=1)
                {
                    proto+= dec/j;
                }
            }
        }

        if(lim_num<proto|| dec==0)
        {
            run=0;
            break;
        }

        if(proto==dec)
        {
            printf_s(" perfect number");
            printf_s("->%llu<-perfect number\n", dec);
        }
        dec+=pow(2, counter);
        dec = dec<<2;
        counter++;
    }
    
    return 0;
}

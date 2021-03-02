#include <stdio.h>
#include <math.h>


int length(int *mass)
{
    int i=0, counter=0;
    while(mass[i]!=2)
    {
        counter++;
        i++;
    }
    return counter;
}

unsigned  long long int fromBintoDec(int *mass, unsigned long long int len)
{
    unsigned long long int dec=0;
    for (int i = 0; i < len; i++)
    {
        dec+=mass[i]* pow(2,len-(i+1));
    }
    return dec;
}

int main()
{

    int len=0, countofones=2, countofzeros=1;
    _Bool run=1;
    unsigned long long int dec=0, proto =0, lim_num=0;

    int binary[60]={0};

    printf_s(" enter limit number: \n");
    scanf_s("%llu",&lim_num );

    binary[0]=1;
    binary[1]=1;
    binary[2]=0;
    binary[3]=2;

    while(run==1)
    {
        len = length(binary);
        dec = fromBintoDec(binary,len);
        proto=0;

        for (int i = 0; binary[i]!=2; i++)
        {
            printf_s("%d",binary[i]);
        }

        for (unsigned long long int j = 1; j < dec; j++)
        {
            if( dec%j==0 )
            {
                proto+=j;
            }
        }

        if(lim_num<proto)
        {
            run=0;
            break;
        }

        if(proto==dec) {

            printf_s(" perfect number");
            printf_s("->%llu<-perfect number\n", dec);
        }
        else
        {
            printf_s("\n");
        }

        if(binary[48]==2)
        {
            break;
        }

        binary[countofones]=1;
        countofones++;

        while(countofzeros!=countofones)
        {

            binary[len]=0;
            len++;
            countofzeros++;
        }

        binary[len]=2;
        countofzeros--;
    }

    return 0;
}

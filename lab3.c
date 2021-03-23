#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int searchForHoles( _Bool ***cube, int side)
{
    int countX=0, countY=0, countZ=0, clCounter=0;

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            for (int k = 0; k < side; k++)
            {
                if(*(cube[i][j] + k) == 0)
                {
                    countZ++;
                }
                else
                {
                    break;
                }
            }
            if(countZ == side)
            {
                printf_s("Clearance coordinates->\tX:%d\tY:%d\n",i,j );
                clCounter++;
                countZ=0;
            }
        }
    }

    for (int k = 0; k < side; k++)
    {
        for (int j = 0; j < side; j++)
        {
            for (int i = 0; i < side; i++)
            {
                if(*(cube[i][j] + k) == 0)
                {
                    countX++;
                }
                else
                {
                    break;
                }
            }
            if(countX == side)
            {
                printf_s("Clearance coordinates->\tY:%d\tZ:%d\n",j,k );
                clCounter++;
                countX=0;
            }
        }
    }

    for (int k = 0; k < side; k++)
    {
        for (int i = 0; i < side; i++)
        {
            for (int j = 0; j < side; j++)
            {
                if(*(cube[i][j] + k) == 0)
                {
                    countY++;
                }
                else
                {
                    break;
                }
            }
            if(countY == side)
            {
                printf_s("Clearance coordinates->\tX:%d\tZ:%d\n",i,k );
                clCounter++;
                countZ=0;
            }
        }
    }

    if(!clCounter)
    {
        printf_s("There are no clearances in the cube!\n");
    }

    return clCounter;
}

int main()
{
    srand(time(0));
    _Bool s[1];
    _Bool ***cube = s;
    _Bool cell;
    int side, run = 0, tryNumb = 0;

    printf("Enter the side of the cube: ");
    scanf_s("%d", &side);

    while(!run)
    {
        cube =(_Bool ***)malloc(side*sizeof(_Bool**));
        if(cube == NULL)
        {
            fprintf(stderr,"no_memory\n");
            return 1;
        }
        for(int i = 0; i < side; i++)
        {
            cube[i] = (_Bool **)malloc(side*sizeof(_Bool*));
            if(cube[i] == NULL)
            {
                fprintf(stderr,"no_memory\n");
                return 1;
            }
            for (int j = 0; j < side; j++)
            {
                cube[i][j] = (_Bool *)malloc(side*sizeof(_Bool));
                if(cube[i][j] == NULL)
                {
                    fprintf(stderr,"no_memory\n");
                    return 1;
                }
            }
        }

        for (int k = 0; k < side; k++)
        {
            for (int i = 0; i < side; i++) {
                for (int j = 0; j < side; j++) {
                    *(cube[i][j] + k) = rand() % 2;

                }
            }
        }

        run = searchForHoles(cube, side);
        tryNumb++;

        for(int i = 0; i < side; i++)
        {
            for (int j = 0; j < side; j++)
            {
                free(cube[i][j]);
            }
            free(cube[i]);
        }
        free(cube);

        if(tryNumb >10)
        {
            run++;
        }
    }
    return 0;
}


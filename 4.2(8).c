
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void check(char* sk, int count);

int main()
{
    char* str, ch;
    int count = 0, i = 0, k = 0;
    char *sk;


    FILE* fp;
    fp = fopen("D:/Study/pr-e/lr/lr4/4.2(8)/1.txt", "r+");

    str = (char*)malloc(sizeof(char) * 200);
    sk = (char*)malloc(sizeof(char) * 80);

    while ((ch = fgetc(fp)) != EOF)
    {
        str[i] = ch;
        i++;

        if (ch == '(')
        {
            sk[k] = '(';
            k++;
        }
        else if (ch == ')')
        {
            sk[k] = ')';
            k++;
        }
        else if (ch == '[')
        {
            sk[k] = '[';
            k++;
        }
        else if (ch == ']')
        {
            sk[k] = ']';
            k++;
        }
        else if (ch == '{')
        {
            sk[k] = '{';
            k++;
        }
        else if (ch == '}')
        {
            sk[k] = '}';
            k++;
        }

    }
    str[i] = '\0';
    sk[k] = '\0';
    puts(str);
    puts(sk);

    check(sk, k);

    free(str);
    free(sk);
}

void check(char* sk, int count)
{
    if (sk[0] == ')' || sk[0] == ']' || sk[0] == '}' || sk[count-1] == '(' || sk[count-1] == '[' || sk[count-1] == '{')
    {
        printf("\nWrong.");
        return;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            if (sk[i] == ')' || sk[i] == ']' || sk[i] == '}')
            {
                int k = 1;
                if (sk[i] == ')')
                {
                    while (1 == 1)
                    {
                        if (sk[i - k] == '(')
                        {
                            sk[i] = '.';
                            sk[i - k] = '.';
                            k = 1;
                            break;
                        }
                        else if (sk[i - k] == '.')
                            k++;
                        else
                        {
                            printf("\nWrong.");
                            return;
                        }
                    }
                }
                else if (sk[i] == ']')
                {
                    while (1 == 1)
                    {
                        if (sk[i - k] == '[')
                        {
                            sk[i] = '.';
                            sk[i - k] = '.';
                            k = 1;
                            break;
                        }
                        else if (sk[i - k] == '.')
                            k++;
                        else
                        {
                            printf("\nWrong.");
                            return;
                        }
                    }
                }
                else if (sk[i] == ']')
                {
                    while (1 == 1)
                    {
                        if (sk[i - k] == '[')
                        {
                            sk[i] = '.';
                            sk[i - k] = '.';
                            k = 1;
                            break;
                        }
                        else if (sk[i - k] == '.')
                            k++;
                        else
                        {
                            printf("\nWrong.");
                            return;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (sk[i] != '.') 
        {
            printf("\nWrong.");
            return;
        }
    }

    printf("\nRight.");
}
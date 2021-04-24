#include <iostream>
#define BUFFER_SIZE 256
using namespace std;

void calculate_shrink(char* s, int index);

int main()
{
    setlocale(LC_ALL, "Rus");

    int i = 0;
    int str_len = 0;

    bool check = false;
    bool no_operation_to_calculacte = false;

    char s[BUFFER_SIZE];
     
    printf_s("Введите арифметическое выражение, не разделяя числа и операции пробелами: ");

    do
    {
        scanf_s("%s", s, BUFFER_SIZE);

        do
        {
            i++;
        } while (s[i] != '\0');

        str_len = i;

        for(i = 0; i < str_len; i++)
        {
            if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '\0')
            {
                printf_s("\nВы ввели запрещённые символы, пожалуйста, повторите ввод.\n");
                break;
            }

        }

        if ((s[0] != '0' && s[0] != '1' && s[0] != '2' && s[0] != '3' && s[0] != '4' && s[0] != '5' && s[0] != '6' && s[0] != '7' && s[0] != '8' && s[0] != '9') || (s[str_len - 1] != '0' && s[str_len - 1] != '1' && s[str_len - 1] != '2' && s[str_len - 1] != '3' && s[str_len - 1] != '4' && s[str_len - 1] != '5' && s[str_len - 1] != '6' && s[str_len - 1] != '7' && s[str_len - 1] != '8' && s[str_len - 1] != '9'))
        {
            printf_s("\nСтрока должна начинаться и заканчиваться числом, пожалуйста, повторите ввод.\n");
        }

        else
        {
            check = true;
        }

    } while (!check);

    printf_s("%s", s);

    while(!no_operation_to_calculacte)
    {
        for(i = 0; i < str_len; i++)
        {
            if(s[i] == '*' || s[i] == '/')
            {
                calculate_shrink(s, i);

                int k = 0;
                do
                {
                    k++;
                } while (s[k] != '\0');
                str_len = k;
                i = 0;
            }
        }

        printf_s("\n\n%s", s);

        for (i = 0; i < str_len; i++)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                calculate_shrink(s, i);

                int k = 0;
                do
                {
                    k++;
                } while (s[k] != '\0');
                str_len = k;
                i = 0;
            }
        }

        printf_s("\n\n%s", s);

        no_operation_to_calculacte = true;
    }
}

void calculate_shrink(char* s, int index)
{
    int i = index;

    int i_index = 0;

    do
    {
        i_index++;
    } while (s[i_index] != '\0');

    int str_len = i_index;

    char s1[BUFFER_SIZE];
    char s2[BUFFER_SIZE];
    char s3[BUFFER_SIZE];
    
    char op1_char[10];
    char op2_char[10];

    int op1_in_e = index - 1;
    int op1_in_b = op1_in_e;

    int op2_in_b = index + 1;
    int op2_in_e = op2_in_b;
    int result = 0;



    while (s[op1_in_b] != '+' && s[op1_in_b] != '-' && s[op1_in_b] != '*' && s[op1_in_b] != '/' && op1_in_b != 0)
    {
        if(s[op1_in_b - 1] == '+' || s[op1_in_b - 1] == '-' || s[op1_in_b - 1] == '*' || s[op1_in_b - 1] == '/' || s[op1_in_b - 1] == 0)
        {
            break;
        }
        op1_in_b--;
    }

    int j;

    for(j = 0; j <= op1_in_e-op1_in_b; j++)
    {
        op1_char[j] = s[(op1_in_b) + j];
        
    }
    op1_char[j] = '\0';

    int op1 = atoi(op1_char);




    while (s[op2_in_e] != '+' && s[op2_in_e] != '-' && s[op2_in_e] != '*' && s[op2_in_e] != '/' && s[op2_in_e] != '\0')
    {
        if (s[op2_in_e + 1] == '+' || s[op2_in_e + 1] == '-' || s[op2_in_e + 1] == '*' || s[op2_in_e + 1] == '/' || s[op2_in_e + 1] == 0)
        {
            break;
        }
        op2_in_e ++;
    }

    int n;

    for (n = 0; n <= op2_in_e - op2_in_b; n++)
    {
        op2_char[n] = s[op2_in_b + n];

    }
    op2_char[n] = '\0';

    int op2 = atoi(op2_char);



    if (s[index] == '*')
    {
        result = op1 * op2;
    }

    if (s[index] == '/')
    {
        result = op1 / op2;
    }

    if (s[index] == '+')
    {
        result = op1 + op2;
    }

    if (s[index] == '-')
    {
        result = op1 - op2;
    }

    _itoa_s(result, s2, _countof(s2), 10);



    int k = 0;

    for(k; k < op1_in_b; k++)
    {
        s1[k] = s[0 + k];
    }

    s1[k] = '\0';


    int l = 0;

    for (l; l < str_len - op2_in_e; l++)
    {
        if (s[op2_in_e + 1] == '\0')
        {
            break;
        }
        s3[l] = s[(op2_in_e + 1) + l];
    }

    s3[l] = '\0';




    i_index = 0;
    j = 0;
    k = 0;
    l = 0;


    while(s1[k] != '\0')
    {
        s[i_index] = s1[k];

        k++;
        i_index++;
    }
    s[i_index] = '\0';


    while (s2[j] != '\0')
    {
        s[i_index] = s2[j];

        j++;
        i_index++;
    }
    s[i_index] = '\0';


    while (s3[l] != '\0')
    {
        s[i_index] = s3[l];

        l++;
        i_index++;
    }
    s[i_index] = '\0';
}
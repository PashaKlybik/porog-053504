//������� 13
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <locale.h>

int main(void)                 
{                               
    char* locale = setlocale(LC_ALL, "");
   
    int numb;
    printf("������� ����������� ����� �����, ��  ������������� 100 \n");
    scanf_s("%d", &numb);
    
    int ost = numb % 10;
    int dec = numb / 10;
    printf("��������� �����: %d, ��� ������ �������� -  ", numb);

    if (numb > 9 && numb < 20)
    {
        switch (numb)
        {
            case 10: printf("������\n"); break;
            case 11: printf("�����������\n"); break;
            case 12: printf("����������\n"); break;
            case 13: printf("����������\n"); break;
            case 14: printf("������������\n"); break;
            case 15: printf("����������\n"); break;
            case 16: printf("�����������\n"); break;
            case 17: printf("����������\n"); break;
            case 18: printf("������������\n"); break;
            case 19: printf("������������\n"); break;
             default:;
        }
    }
    switch (dec)
    {
        
        case 2: printf("�������� "); break;
        case 3: printf("�������� "); break;
        case 4: printf("����� "); break;
        case 5: printf("��������� "); break;
        case 6: printf("���������� "); break;
        case 7: printf("��������� "); break;
        case 8: printf("����������� "); break;
        case 9: printf("��������� "); break;
        case 10: printf("���\n"); break;
         default:;
    }
    switch (ost)
    {

        case 1: printf("����\n"); break;
        case 2: printf("���\n"); break;
        case 3: printf("���\n"); break;
        case 4: printf("������\n"); break;
        case 5: printf("����\n"); break;
        case 6: printf("�����\n"); break;
        case 7: printf("����\n"); break;
        case 8: printf("������\n"); break;
        case 9: printf("������\n"); break;
         default:;
    }
    return 0;                   
}
#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#define QMAX 100

struct queue 
{
    int qu[QMAX];
    int rear, frnt;
};

void init(struct queue* q) 
{
    q->frnt = 1;
    q->rear = 0;
    return;
}

void insert(struct queue* q, int x) 
{
    if (q->rear < QMAX - 1) 
    {
        q->rear++;
        for(int i = 1; i <= q->rear; i++)
        {
            if (x == q->qu[i])
            {
                q->rear--;
                return;
            }
            if(x < q->qu[i])
            {
                for(int j = q->rear; i <= j; j--)
                {
                    q->qu[j] = q->qu[j - 1];
                }
                q->qu[i] = x;
                return;
            }
            else
            {

            }
        }
        q->qu[q->rear] = x;
    }
    else
        printf("Очередь полна!\n");
    return;}

int isempty(struct queue* q) 
{
    if (q->rear < q->frnt)    return 1;
    else  return 0;
}

void print(struct queue* q)
{
    int h;
    if (isempty(q) == 1) 
    {
        printf("\nОчередь пуста!\n");
        return;
    }
    for (h = q->frnt; h <= q->rear; h++)
        printf("%d ", q->qu[h]);
    return;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    struct queue* q1;
    struct queue* q2;
    int a;

    q1 = (queue*)malloc(sizeof(queue));
    init(q1);
    print(q1);
    do
    {
        printf("\nВведите элемент первой очереди, чтобы завершить ввод введите 0: ");
        scanf_s("%d", &a);
        insert(q1, a);
    } while (a != 0);
    printf("\n");
    print(q1);

    q2 = (queue*)malloc(sizeof(queue));
    init(q2);
    print(q2);
    do
    {
        printf("\nВведите элемент второй очереди, чтобы завершить ввод введите 0: ");
        scanf_s("%d", &a);
        insert(q2, a);
    } while (a != 0);
    printf("\n");
    print(q2);

    for(int i = q2->frnt; i <= q2->rear; i++)
    {
        insert(q1, q2->qu[i]);
    }
    printf("\n");
    print(q1);

    return 0;
}


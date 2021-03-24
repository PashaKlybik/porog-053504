#include <stdio.h>

const double COST_T = 3.5;
const double COST_P = 7.2;
const double COST_G = 6.9;
double kg_t, kg_p, kg_g;
double price_t, price_p, price_g;
double sum;

double tangerines()
{
    double kg_t1;
    printf("\nСколько килограмм мандарин вы хотите купить?\n");
    scanf("%lf", &kg_t1);
    kg_t += kg_t1;
    price_t = kg_t * COST_T;
    return price_t;
}

double peaches()
{
    double kg_p1;
    printf("\nСколько килограмм персиков вы хотите купить?\n");
    scanf("%lf", &kg_p1);
    kg_p += kg_p1;
    price_p = kg_p * COST_P;
    return price_p;
}

double grapes()
{
    double kg_g1;
    printf("\nСколько килограмм винограда вы хотите купить?\n");
    scanf("%lf", &kg_g1);
    kg_g += kg_g1;
    price_g = kg_g * COST_G;
    return price_g;
}

void order()
{
    printf("\nМандарины: %lf", kg_t);
    printf("\nПерсики: %lf", kg_p);
    printf("\nВиноград: %lf", kg_g);
}

void summary()
{
    sum = price_t + price_p + price_g;
    printf("\nОбщая стоимость заказа - %lf", sum);
}

void info()
{
    printf("Магазин 'Без Скидок!!!'\nБесплатная доставка!\nНомер телефона: +375(29)-348-99-25.");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Заказ мандаринов (кг). \n2. Заказ персиков (кг).\n3. Заказ винограда (кг).\n4. Корзина.\n5. Расчет стоимости заказа.\n6. Обратная связь.\n7. Выход\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                tangerines();
                break;
            case 2:
                peaches();
                break;
            case 3:
                grapes();
                break;
            case 4:
                order();
                break;
            case 5:
                summary();
                break;
            case 6:
                info();
                break;
            case 7:
                return 0;
            default:
                printf("Некорректный ввод. Попробуйте ещё раз.\n");
                break;
        }
    }
}

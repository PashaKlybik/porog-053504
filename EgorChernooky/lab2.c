#include <stdio.h>

void tangerines(const float price, float kg, float *cost);
void peaches(const float price, float kg, float *cost);
void grapes(const float price, float kg, float *cost);
void bag(float kg_t, float kg_p, float kg_g);
float summary(float cost_t, float cost_p, float cost_g, float kg_t, float kg_p, float kg_g, float sum_p);
void info();

int main() {
    float kg_t = 0, kg_p = 0, kg_g = 0, sum_p = 0;
    const float TANG_PRICE = 1.14,PEACHES_PRICE = 1.0, GRAPES_PRICE = 1.28;
    float cost_t = 0, cost_p = 0, cost_g = 0;

    printf("\nВас приветствует магазин eFruit!\n\n");
    while(1) {
        int choice;
        printf("\n1. Мандарины\n"
               "2. Персики\n"
               "3. Виноград\n"
               "4. Корзина\n"
               "5. Цена\n"
               "6. Контактная информация\n"
               "7. Выход\n\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nВведите кол-во килограмм: ");
                scanf("%f", &kg_t);
                if (kg_t > 0) {
                    tangerines(TANG_PRICE, kg_t, &cost_t);
                    break;
                }
                else if (kg_t < 0) {
                    printf("\nНекорректный ввод.\n");
                    break;
                }
                else {
                    printf("\nНекорректный ввод.\n");
                    return 0;
                }
            case 2:
                printf("\nВведите кол-во килограмм: ");
                scanf("%f", &kg_p);
                if (kg_p > 0) {
                    peaches(PEACHES_PRICE, kg_p, &cost_p);
                    break;
                }
                else if (kg_p < 0) {
                    printf("\nНекорректный ввод.\n");
                    break;
                }
                else {
                    printf("\nНекорректный ввод.\n");
                    return 0;
                }
            case 3:
                printf("\nВведите кол-во килограмм: ");
                scanf("%f", &kg_g);
                if (kg_g > 0) {
                    grapes(GRAPES_PRICE, kg_g, &cost_g);
                    break;
                }
                else if (kg_g < 0) {
                    printf("\nНекорректный ввод.\n");
                    break;
                }
                else {
                    printf("\nНекорректный ввод.\n");
                    return 0;
                }
            case 4:
                bag(kg_t, kg_p, kg_g);
                break;
            case 5:
                summary(cost_t, cost_p, cost_g, kg_t, kg_p, kg_g, sum_p);
                break;
            case 6:
                info();
                break;
            case 7:
                return 0;
            default:
                printf("\n\nНеверный ввод. Попробуйте еще раз.\n\n");
        }
    }
}

void tangerines(const float price, float kg, float *cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void peaches(const float price, float kg, float *cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void grapes(const float price, float kg, float *cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void bag(float kg_t, float kg_p, float kg_g) {
    if (kg_t < 0) kg_t = 0;
    if (kg_p < 0) kg_p = 0;
    if (kg_g < 0) kg_g = 0;

    printf("Мандарины: %0.01fкг\n", kg_t);
    printf("Персики: %0.01fкг\n", kg_p);
    printf("Виноград: %0.01fкг\n\n", kg_g);
}
float summary(float cost_t, float cost_p, float cost_g, float kg_t, float kg_p, float kg_g, float sum_p) {
    sum_p = cost_t + cost_p + cost_g;
    printf("Стоимость заказа: %0.01f$\n", sum_p);

    if (sum_p == 0) {
        return 0;
    }
    if(sum_p >= 100) {
        sum_p *= 0.9;
        printf("\nСтоимость заказа больше 100$, вы получаете скидку 10%!\nТеперь стоимость вашего заказа - %0.01"
               "f$!\n", sum_p);
    }

    float sum_kg = kg_t + kg_p + kg_g;
    if (sum_kg < 5) {
        sum_p += 1.0;
        printf("Вес продуктов меньше 5кг.\nСтоимость доставки - 1$.\n");
    }
    else if (sum_kg >= 5 && sum_kg < 20) {
        sum_p += 3.0;
        printf("Вес продуктов больше 5кг.\nСтоимость доставки - 3$\n");
    }
    else if (sum_kg >= 20) {
        sum_p += 10.0;
        printf("Вес продуктов превышает 20кг.\nСтоимость доставки - 10$. И по 2$ за каждый килограмм.\n");
        while (sum_kg > 20) {
            sum_p += 2.0;
            --sum_kg;
        }
    }
    printf("\nСтоимость заказа вместе с доставкой - %0.01f$\n\n", sum_p);
}
void info() {
    printf("\nКонтактная информация:\n Магазин - eFruit\n Номер телефона - +375(29)3627233\n");
}

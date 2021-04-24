#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

void print_menu() {
    system("cls");  // очищаем экран
    printf("Здравствуйте.\nВы находитесь в меню ТранзитБанка.\nПожалуйста, выберите следующие функции:\n");
    printf("1. Открытие вклада (ввод суммы в белорусских рублях).\n");
    printf("2. Дополнительный взнос на вклад(ввод суммы в белорусских рублях).\n");
    printf("3. Просмотр остатка(суммы вклада).\n");
    printf("4. Просмотр остатка на заданный день.\n");
    printf("5. Закрытие вклада(печатается остаток вклада без процентов).\n");
    printf("6. Краткая информация о банке и контакты.\n");
    printf("7. Выход из программы.\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Неверно выбранный пункт меню. Повторите ввод: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int summa_vklada = 0;
    int dobavochnaya_summa = 0;

    int days_gone = 0;
    float month_gone = 0;

    double mesyachnaya_stavka = 1.0625;

    int variant;

    do {
        print_menu();

        variant = get_variant(7); // получаем номер выбранного пункта меню

        switch (variant) {
        case 1:
            system("cls");
            printf_s("\nВыбран пункт меню 1.\nВведите сумму вклада в белорусских рублях: ");
            scanf_s("%d", &summa_vklada);
            printf_s("Ваш баланс составляет %d рублей\n\n", summa_vklada);
            break;

        case 2:
            system("cls");
            printf_s("Выбран пункт меню 2.\nВведите добавочную сумму вклада в белорусских рублях: ");
            scanf_s("%d", &dobavochnaya_summa);

            summa_vklada += dobavochnaya_summa;

            printf_s("Ваш вклад составляет %d рублей\n\n", summa_vklada);
            break;

        case 3:
            system("cls");
            printf_s("Выбран пункт меню 3.\nПросмотр остатка суммы вклада: %d\n\n", summa_vklada);
            break;

        case 4:
            system("cls");
            printf_s("Выбран пункт меню 4.\nПросмотр остатка на заданный день.\n");
            printf_s("Введите количество прошедших дней: ");
            scanf_s("%d", &days_gone);
            month_gone = days_gone / 30;

            if (days_gone <= 365)
            {
                for (int i = 0; i < (int)month_gone; i++)
                {
                    summa_vklada += (summa_vklada / 100) * mesyachnaya_stavka;
                }
                printf_s("\nВаш баланс составляет %d рублей\n\n", summa_vklada);
            }
            if (days_gone >= 365)
            {
                printf_s("\nСрок начисления вам процентов истёк. Ваш вклад составляет %d рублей\n\n", summa_vklada);
            }
            break;

        case 5:
            system("cls");
            printf_s("Выбран пункт меню 5.\nПроизводится закрытие вклада. Ваш вклад равен %d рублей\n\n", summa_vklada);

            summa_vklada = 0;
            break;

        case 6:
            system("cls");
            printf_s("Выбран пункт меню 6.\nИнформация о нас и наши контакты\nО нас\nБанк был основан 11 сентября в 2001 году в Минске. На данный момент мы поддерживаем\n сотрудничество с несколькими иностранными банковскими организациями.\n Начиная с 2003 года ТранзитБанк следует инновационной стратегии развития и внедряет современные технологии, а именно:\n Интернет-банк и его мобильная версия, биометрические технологий для подтверждения личности по голосу при звонке в контакт-центр,\n бесконтактная технология HCE для расчетов посредством мобильного телефона и других.\n\nКонтакты:\n+375 17 289 92 92\n+375 17 289 90 60\n\n");
            break;
        }

        if (variant != 7)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 7);   
}


#include <stdio.h>
#include <locale.h>
#include <math.h>

float get_size(){
    float a;
    float var =0;
    while(var!=1) {
        printf("Введите длину ребра вашего тетраэдра: ");
        var = scanf("%f", &a);
        if(var!=1 || a<=0) {
            fflush(stdin);
            var = 0;
        }
    }
    return a;
}

float count_aa(float a){
    return a*6;
}

float count_S(float a){
    float S = a * a * sqrtf(3) / 4;
    return S;
}

float count_SS(float a){
    float SS = count_S(a)*4;
    return SS;
}

float count_h(float a){
    float h = a * sqrtf(2) / sqrtf(3);
    return h;
}

float count_V(float a){
    float S = count_S(a);
    float h = count_h(a);
    float V = S * h / 3;
    return V;
}

float count_r(float a){
    float S = count_S(a);
    float V = count_V(a);
    float r = 3 * V / (S * 4);
    return r;
}

void information(){
    printf("Версия 1.0\nАвтор Сорокина Екатерина, гр. 053504");
}

void menu(float *a_, int num, float a){
    switch (num) {
        case 1:
            printf("Общая длина всех рёбер тетраэдра: %f", count_aa(a));
            break;
        case 2:
            printf("Площать одной грани тетраэдра: %f", count_S(a));
            break;
        case 3:
            printf("Площать полной поверхности тетраэдра: %f", count_SS(a));
            break;
        case 4:
            printf("Объём тетраэдра: %f", count_V(a));
            break;
        case 5:
            printf("Высота тетраэдра: %f", count_h(a));
            break;
        case 6:
            printf("Радиус вписанного в тетраэдр шара: %f", count_r(a));
            break;
        case 7:
            information();
            break;
        case 8:
            *a_ = get_size();
            break;
        case 0:
            break;
        default:
            printf("Вы не выбрали действие");
    }
}

int main() {
    setlocale(LC_ALL,"Rus");

    float a;
    int num = 1;
    a=get_size();
    while (num){
        printf("\nВыберите, что вы хотите сделать:"
               "\n1 - найти длину всех рёбер"
               "\n2 - найти площать одной грани"
               "\n3 - найти площать полной поверхности"
               "\n4 - найти объём"
               "\n5 - найти высоту"
               "\n6 - найти радиус вписанного шара"
               "\n7 - получить информацию о версии и авторе программы"
               "\n8 - ввести новые данные"
               "\n0 - выйти\n");
        scanf("%d", &num);
        menu(&a, num, a);
    }
    return 0;
}

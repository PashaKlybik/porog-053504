#include <iostream>
#include <vector>
#include <algorithm>
/* Автосервис. Автосервис предоставляет n различных услуг, в
каждую из которых – очередь автомобилей. Новые автомобили
заезжают в автосервис через случайные интервалы времени; время
обслуживания в каждом из n сервисов – постоянная величина ai
 (i 
<= n). Выбрать маршрут, при котором за заданное время t
автомобиль сможет пройти максимальное число сервисов.*/

//создаем 4 автосервиса, в них записываем их номер и время с которым они обрабатывают услуги
struct Avtoservis {
    Avtoservis(int numb, int tim) : number(numb), time(tim) {};
    int number;
    int time;
};
int main() {
    std::vector<Avtoservis> servis;
    servis.push_back(Avtoservis(1, 3));
    servis.push_back(Avtoservis(2, 5));
    servis.push_back(Avtoservis(4, 2));
    servis.push_back(Avtoservis(5, 1));
    std::cout << "Enter time: ";
    int time;
    std::cin >> time;
    std::vector<Avtoservis> res;
    std::sort(servis.begin(), servis.end(), [](const Avtoservis& avto1, const Avtoservis& avto2) {return avto1.time < avto2.time; });
    for (auto i = 0; i != servis.size(); i++) {
        if (servis[i].time < time) {
            res.push_back(servis[i]);
            time -= servis[i].time;
        }
    }
    std::cout << "Marshrut: ";
    for (auto avto : res) {
        std::cout << avto.number << " ";
    }
    return 0;
}
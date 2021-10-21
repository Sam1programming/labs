#include <iostream>
#include "lib.h"
#include "ellipse.hpp"
const char *MSGS[] = {"0. Quit", "1. Вывести координаты центра", "2. Вывести полуось по х", "3. Вывести полуось по у", "4. Установить новые координаты центра",
                      "5. Установить новую полуось по х", "6. Установить новую полуось по y", "7. Вывести фокальное расстояние", "8. Вывести эксцентриситету",
                      "9. Вывести длинну", "10. Вывести площадь", "11. Вывести мин расст. от фокуса до эллепса", "12. Вывести макс расст. от фокуса до эллепса",
                      "13. Вывести у(х)"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int main() {
    int c;
    Prog2::Ellipse my;
    do {
        c = dialog(MSGS, MSGS_SIZE);
        switch(c) {
            case 0:
                break;
            case 1:
                std::cout<<"Коорд Х: "<< my.getP().x <<"\nКоорд Y: "<< my.getP().y <<std::endl;
                break;
            case 2:
                std::cout<<"Полуось x: "<< my.getA() <<std::endl;
                break;
            case 3:
                std::cout<<"Полуось y: "<< my.getB() <<std::endl;
                break;
            case 4:
                double x, y;
                std::cout<<"Введите x:"; std::cin>> x;
                std::cout<<"\nВведите y:"; std::cin>> y;
                    my.setP(x, y);
                break;
            case 5:
                double a;
                std::cout<<"Введите a:"; std::cin>> a;
                try{
                    my.setA(a);
                }
                catch (std::underflow_error &ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            case 6:
                double b;
                std::cout<<"Введите b:"; std::cin>> b;
                try{
                    my.setB(b);
                }
                catch (std::underflow_error &ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            case 7:
                std::cout<<"Фокальное расстояние: " <<my.focal()<<std::endl;
                break;
            case 8:
                std::cout<<"Эксцентриситета: " <<my.excent()<<std::endl;
                break;
            case 9:
                std::cout<<"Длинна: " <<my.length()<<std::endl;
                break;
            case 10:
                std::cout<<"Площадь: " <<my.square()<<std::endl;
                break;
            case 11:
                std::cout<<"минимальное расстояние: " <<my.min()<<std::endl;
                break;
            case 12:
                std::cout<<"max расстояние: " <<my.max()<<std::endl;
                break;
            case 13:
                double x1 = 0, y0 = 0;
                std::cout<<"Введите x: "; std::cin>> x1;
                try{
                    y0 = my.findY(x1);
                }
                catch (std::underflow_error &ex){
                    std::cout << ex.what() << std::endl;
                    break;
                }
                std::cout<<"\nКоординаты у: +-" << y0 <<std::endl;
                break;
        }
    } while (c != 0);
    return 0;
}

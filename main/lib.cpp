#include <iostream>
#include "lib.h"

template<class T>
int getNum(T &a) {
    while (!(std::cin>>a)){
        if(std::cin.eof()){
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение:\n" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 1;
}

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        getNum(choice);
    } while (choice < 0 || choice >= n);
    return choice;
}

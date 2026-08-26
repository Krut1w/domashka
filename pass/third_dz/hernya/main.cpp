#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"


int main(){
    system("chcp 65001 > nul");

    bugaga::MenuItem study = {"1 - хочу учиться алгоритмам", bugaga::study };
    bugaga::MenuItem exit = {"0 - я лучше пойду полежу...", bugaga::exit};

    bugaga::MenuItem* main_children[] = {&exit, &study};


    return 0;
}




    // std::cout << "Добро пожаловать в обучайку.";
    // std::cout << "Здесь вы можете выучить новые алгоритмы или повторить уже изученные вами";
    // std::cout << "Что вы хотите делать?\n";
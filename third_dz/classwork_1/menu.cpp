#include <iostream>

#include "menu.hpp"

int main(){
    const Kpav::MenuItem* current = &Kpav::Main;

    do{
        current = current->func(current);
    }while (true);

    return 0;
}
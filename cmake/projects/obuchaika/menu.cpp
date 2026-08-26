#include <iostream>
#include <windows.h>


#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_functions.hpp"

int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const Kpav::MenuItem* current = &Kpav::MAIN;

    do{ 
        current = current->func(current);
    }while (true);

    return 0;
}
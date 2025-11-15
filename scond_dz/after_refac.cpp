#include <iostream>
#include <cmath>

int const array_size = 20;

int main()
{
    int list[array_size];
    
    std::cout << "Ваш начальный список: ";
    for (int i = 0; i < array_size; i++){
        list[i] = rand() % array_size;
        std::cout << list[i] << ' ';
    }

    std::cout << std::endl;
    
    int b;
    for (int i = 0; i < array_size / 2; i++){
        b = list[i];
        list[i] = list[array_size - i - 1];
        list[array_size - i - 1] = b;
    }
    
    std::cout << "Ваш итоговый список: ";
    for (int i = 0; i < array_size; i++){
        std::cout << list[i] << ' ';
    }

    return 0;
}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <locale>

#include "sort.h"

int main(){

    int size;
    std::cout << "Введите длину массива: ";
    std::cin >> size;

    int* arr = new int[size];
    
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100;
    }
    std::cout << "Ваш список до сортировки: ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    shellsort(arr, size);

    std::cout << "Ваш список после сортировки: ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;

}
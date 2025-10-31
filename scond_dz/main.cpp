#include <cstdlib>
#include <ctime>
#include <iostream>
#include <locale>

#include "sort.h"

int main(){
    std::locale::global(std::locale("C"));
    std::wcout.imbue(std::locale());

    int size;
    std::cout << "Enter the len of array: ";
    std::cin >> size;

    int* arr = new int[size];
    
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100;
    }
    
    shellsort(arr, size);

    std::cout << "array after sort\n";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;

}
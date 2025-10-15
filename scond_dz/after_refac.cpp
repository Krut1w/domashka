#include <iostream>
#include <cmath>


int main()
{
    int a[20], i, b;

    for (i = 0; i < 20; i++){
        a[i] = rand() % 20;
        std::cout << a[i] << ' ';
    }

    std::cout << std::endl;
    
    for (i = 0; i < 10; i++){
        b = a[i];
        a[i] = a[19 - i];
        a[19 - i] = b;
    }
    
    for (i = 0; i < 20; i++){
        std::cout << a[i] << ' ';
    }

    return 0;
}

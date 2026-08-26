#include <iostream>

struct Ukaz{
    int i;
};






int main(){
    // int a = 10;
    // int* p = &a;
    // *p = 5;

    // std::cout << a;
    Ukaz day = {10};

    Ukaz* cur = &day;
    std::cout << cur->i;

    return 0;
}
#include <iostream>
#include <locale>
#include <vector>
#include "sort.h"

using namespace std;

int main(){
    locale::global(locale("C"));
    wcout.imbue(locale());

    vector<int> n = {1, 5, 62, 97, 2, 5, 197, 111, 304};

    shellsort(n);

    cout << "array after sort";
    for (int num : n){
        cout << num << " "; 
    }
    cout << endl;

    return 0;

}
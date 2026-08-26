#include <iostream>
#include <vector>

using namespace std;

void shellsort(vector<int>&n){
    for (int gap = n.size()/2; gap > 0; gap /= 2){
        for (int i = gap; i < n.size(); i++) {
            int temp = n[i];
            int j;
            for (j= i; j >= gap && n[j-gap] > temp; j -= gap){
                n[j] = n[j-gap];
            }
            n[j] = temp;
        }
    }
    
}
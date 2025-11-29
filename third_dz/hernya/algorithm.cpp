#include <iostream>

struct Algorithm {
    int id;
    const char* name;
    bool is_known; 
};


Algorithm algorithm[11] = {
    {1, "Пирамидальная сортировка", false},
    {2, "Сортировка выбором", false},
    {3, "Сортировка вставками", false},
    {4, "Пузырьковая сортировка", false},
    {5, "Шейкерная сортировка", false},
    {6, "Чёт-нечет сортировка", false},
    {7, "Сортировка расчёской", false},
    {8, "Сортировка Шелла", false},
    {9, "Быстрая сортировка", false},
    {10, "HyperQuicksort, Introsort, PSRS", false},
    {11, "Сортировка слиянием", false}

};

int main(){
    system("chcp 65001 > nul");


    for (int i = 0; i < 11; i++){
    std::cout << algorithm[i].id << "."<< " " << algorithm[i].name << std::endl;
    }

    std::cout << "ВВедите алгоритмы которые вы знаете, если вы не знаете ничего напишите 0, также напишите 0 когда вы уже написали все вам известыне алгортмы, после ввода 0 нажмите enter" << std::endl;
    std:: cout << "Обучайка > ";

    int num;  
    while(std::cin >> num && num != 0){
    algorithm[num - 1].is_known = true;
    }

    int* what_is_know = new int[11];
    for (int i = 0; i < 11; i++){
        if (algorithm[i].is_known == true){
            what_is_know[i] = algorithm[i].id;
        }
    }

    for (int i = 0; i < 11; i++){
        std::cout << what_is_know[i] << std::endl;
    }
return 0;

}






#include <iostream>
#include <vector>
#include <sstream>

int level_1(){
    std::string choice = "Что вы хотите сделать сегодня, выберите и напшите цифру:\n1. Хочу начать учить новые алгоритмы.\n2. Хочу повторить пройденные алгоритмы.\n3. Не хочу ничего делать\n";
    int variant;
    std::cout << choice;
    std::cout << "Обучайка > ";
    std::cin >> variant;

    return variant;
}

int povtor();

int level_2(int lvl1ans){
    std::string ans_1 = "Вот список неизвестных вам алгоритмов:"; // надо сделать чтобы после этого пользователь вводил какой алгоритм он хочет изучить
    std::string ans_2 = "Выбери алгоритм который ты хочешь повторить из уже изученный тобою:";
    if (lvl1ans == 1){
        std::cout << ans_1;
    } else if (lvl1ans == 2){
        std::cout << ans_2;
    } else{
        std::cout << "Нет ты хочешь, выбери 1 из 2 вариантов\n";
        int pov_ans;
        std::cout << "Обучайка > ";
        std::cin >> pov_ans;
        std::cout << std::endl;
        level_2(pov_ans);
    }
    return 0;
}

int level_3(){ // сюда надо передать список алгоритмов который знает/не знает пользователь в зависимости от выбора 2 меню
    // так здесь будет вывод случайного алгоритма и 5 вопросов к нему 
    // или объяснение нового алгоритма и после этого вопрос хотите ли закрпеить материал

    return 0;
}



int main(){
    system("chcp 65001 > nul");
    std::string greeting = "Здравствуйте!\nВы попали в обучайку. Здесь вы сможете изучить новые алгоритмы или повторить уже изученные";
    std::cout << greeting << std::endl;

    std::string knowl_of_alg = R"(Для начала выберите алгоритмы, которые вы знаете:
    1. Пирамидальная сортировка
    2. Сортировка выбором
    3. Сортировка вставками
    4. Пузырьковая сортировка
    5. Шейкерная сортировка
    6. Чёт-нечет сортировка
    7. Сортировка расчёской
    8. Сортировка Шелла
    9. Быстрая сортировка
    10. HyperQuicksort, Introsort, PSRS
    11. Сортировка слиянием
    Обучайка > )";

    std::cout << knowl_of_alg;
    std::vector<int> what_know;
    std::string input;

    std::getline(std::cin >> std::ws,  input);
    std::stringstream ss(input);

    int digit;
    while (ss >> digit) {
        what_know.push_back(digit);
    }

    std::cout << "Отлично, продолжим\n";
    
    int lvl_1 = level_1();
    int lvl_2 = level_2(lvl_1);


    return 0;
}
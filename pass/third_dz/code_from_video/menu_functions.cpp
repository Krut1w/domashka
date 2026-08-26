#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const Kpav::MenuItem* Kpav::show_menu(const MenuItem* current){
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++){
        std::cout << current->children[i]->title <<std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const Kpav::MenuItem* Kpav::exit(const MenuItem* current){
    std::exit(0);
}


const Kpav::MenuItem* Kpav::study_sum(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_substract(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_multiply(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_divide(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_go_back(const MenuItem* current){
    return current->parent->parent;
}
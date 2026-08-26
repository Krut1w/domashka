#include "menu_functions.hpp"

#include <iostream>
#include <cstdlib>

namespace {
    const Kpav::MenuItem* show_children(const Kpav::MenuItem* current) {
        for (int i = 1; i < current->children_count; i++){  
            std::cout << current->children[i]->title << std::endl;
        }

        std::cout << current->children[0]->title << std::endl;
        std::cout << "обучайка > ";

        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;

        return current->children[user_input];
    }
} // namespace 


const Kpav::MenuItem* Kpav::show_menu(const MenuItem* current){
    std::cout << "Главное меню" << std::endl;
    return show_children(current);
}

const Kpav::MenuItem* Kpav::show_menu2(const MenuItem* current){
    std::cout << "Второй уровень меню" << std::endl;
    // std::cout << "Вы перешли на второй уровень\n";
    return show_children(current);
}

const Kpav::MenuItem* Kpav::show_menu3(const MenuItem* current){
    std::cout << "Третий уровень меню"<< std::endl;
    return show_children(current);
}


const Kpav::MenuItem* Kpav::exit(const MenuItem* current){
    std::exit(0);
}

const Kpav::MenuItem* Kpav::study_1grade(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_2grade(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_3grade(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_grade_back(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent->parent;
}

const Kpav::MenuItem* Kpav::study_russian(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_russian_lit(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_math(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::study_pe(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent;
}

const Kpav::MenuItem* Kpav::go_back(const MenuItem* current){
    std::cout << current->title << std::endl;
    return current->parent->parent;
}


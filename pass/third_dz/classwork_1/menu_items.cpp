#include "menu_items.hpp"
#include "menu_functions.hpp"


const Kpav::MenuItem Kpav::STUDY_RUSSIAN = {
    "1 - русский язык", Kpav::study_russian, &Kpav::STUDY_1GRADE
};

const Kpav::MenuItem Kpav::STUDY_RUSSIAN_LIT = {
    "2 - русская литература", Kpav::study_russian_lit, &Kpav::STUDY_1GRADE
};

const Kpav::MenuItem Kpav::STUDY_MATH = {
    "3 - Математика", Kpav::study_math, &Kpav::STUDY_1GRADE
};

const Kpav::MenuItem Kpav::STUDY_PE = {
    "4 - Я люблю физкультуру", Kpav:: study_pe, &Kpav::STUDY_1GRADE
};

const Kpav::MenuItem Kpav::GO_BACK = {
    "0 - Выйти в предыдущее меню", Kpav::go_back, &Kpav::STUDY_1GRADE
};

namespace{
    const Kpav::MenuItem* const study_1grade_children[] = {
        &Kpav::GO_BACK, 
        &Kpav::STUDY_RUSSIAN,
        &Kpav::STUDY_RUSSIAN_LIT,
        &Kpav::STUDY_MATH,
        &Kpav::STUDY_PE
    };
    const int study_1grade_size = sizeof(study_1grade_children) / sizeof(study_1grade_children[0]);
}

const Kpav:: MenuItem Kpav::STUDY_1GRADE ={
    "1 - Изучать предметы 1-го класса", Kpav::show_menu3, &Kpav::STUDY, study_1grade_children, study_1grade_size
};

const Kpav::MenuItem Kpav::STUDY_2GRADE = {
    "2 - Изучать предметы 2-го класса", Kpav::study_2grade, &Kpav::STUDY
};

const Kpav::MenuItem Kpav::STUDY_3GRADE = {
    "3 - Изучать предметы 3 класса", Kpav::study_3grade, &Kpav::STUDY
};

const Kpav::MenuItem Kpav::STUDY_GRADE_BACK = {
    "0 - выйти в главное меню", Kpav::study_grade_back, &Kpav::STUDY
};

namespace {
    const Kpav::MenuItem* const study_children[] = {
        &Kpav::STUDY_GRADE_BACK,
        &Kpav::STUDY_1GRADE,
        &Kpav::STUDY_2GRADE,
        &Kpav::STUDY_3GRADE
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const Kpav::MenuItem Kpav::STUDY = {
    "1 - хочу учить школьные предметы", Kpav::show_menu2, &Kpav::MAIN, study_children, study_size
};

const Kpav::MenuItem Kpav::EXIT = {
    "0 - я уже все знаю", Kpav::exit, &Kpav::MAIN
};
namespace {
    const Kpav::MenuItem* const main_children[] = {
        &Kpav::EXIT,
        &Kpav::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Kpav::MenuItem Kpav::MAIN = {
    "Главное меню", Kpav::show_menu, nullptr, main_children, main_size
};
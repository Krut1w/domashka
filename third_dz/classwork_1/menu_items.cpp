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

const Kpav:: MenuItem Kpav::STUDY_1GRADE ={
    "1 - Изучать предметы 1-го класса", Kpav::study_1grade, &Kpav::STUDY
};

const Kpav::MenuItem Kpav::STUDY_2GRADE = {
    "2 - Изучать предметы 2-го класса"
}
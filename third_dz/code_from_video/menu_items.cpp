#include "menu_items.hpp"
#include "menu_functions.hpp"

const Kpav::MenuItem Kpav::STUDY_SUM = {
    "1 - хочу научиться складывать!", Kpav::study_sum, &Kpav::STUDY
};
const Kpav::MenuItem Kpav::STUDY_SUBSTRACT= {
    "2 - хочу научитья вычитать", Kpav::study_substract, &Kpav::STUDY
};
const Kpav::MenuItem Kpav::STUDY_MULTIPLY = {
    "3 - хочу научиться умножать!", Kpav::study_multiply, &Kpav::STUDY
};
const Kpav::MenuItem Kpav::STUDY_DIVIDE = {
    "4 - хочу научиться умножать!", Kpav::study_divide, &Kpav::STUDY
};
const Kpav::MenuItem Kpav::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", Kpav::study_go_back, &Kpav::STUDY
};

namespace{
    const Kpav::MenuItem* const study_children[] = {
        &Kpav::STUDY_GO_BACK,
        &Kpav::STUDY_SUM,
        &Kpav::STUDY_SUBSTRACT,
        &Kpav::STUDY_MULTIPLY,
        &Kpav::STUDY_DIVIDE
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const Kpav::MenuItem Kpav::STUDY = {
    "1 - хочу учитсья математике!", Kpav::show_menu, &Kpav::MAIN, study_children, study_size
};

const Kpav::MenuItem Kpav::EXIT = {
    "0 - Я лучше пойду полежу...", Kpav::exit, &Kpav::MAIN
};

namespace {
    const Kpav::MenuItem* const main_children[] = {
        &Kpav::EXIT,
        &Kpav::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Kpav::MenuItem Kpav::MAIN = {
    nullptr, Kpav::show_menu, nullptr, main_children, main_size
};

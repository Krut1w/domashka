#pragma once

#include "menu.hpp"

namespace Kpav {
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* study_1grade(const MenuItem* current);
    const MenuItem* study_2grade(const MenuItem* current);
    const MenuItem* study_3grade(const MenuItem* current);
    const MenuItem* study_grade_back(const MenuItem* current);

    const MenuItem* study_russian(const MenuItem* current);
    const MenuItem* study_russian_lit(const MenuItem* current);
    const MenuItem* study_math(const MenuItem* current);
    const MenuItem* study_pe(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);
}
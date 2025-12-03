#pragma once

namespace Kpav{
    struct MenuItem{
        const char* const title;
        const MenuItem* (*func)(const MenuItem* current);

        const MenuItem* parent;

        const MenuItem* const *children;
        const int children_count;

    };
}

// 4 указателя = 1 машинное слово 
// 2 була = 2 байта + 1 инт = 4 байта + 1 флот = 4 байта = 10 байт
#pragma once

#include "Config.hpp"

class Map {
private:
    char matrix[MAP_HEIGHT][MAP_WIDTH + 1];

public:
    void clear_map();
    void show_map();
    void put_score_on_map(const int score);
    void set_cur(const int x, const int y);
    char (*get_matrix())[MAP_WIDTH + 1] { return matrix; }
};
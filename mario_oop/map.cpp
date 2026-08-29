#include "Map.hpp"

#include <cstdio>
#include <cstring>
#include <windows.h>

void Map::clear_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        matrix[0][i] = ' ';
    }
    matrix[0][MAP_WIDTH] = '\0';
    for (int j = 1; j < MAP_HEIGHT; j++) {
        sprintf_s(matrix[j], "%s", matrix[0]);
    }
}

void Map::show_map() {
    matrix[MAP_HEIGHT - 1][MAP_WIDTH - 1] = '\0';
    for (int j = 0; j < MAP_HEIGHT; j++) {
        printf("\n%s", matrix[j]);
    }
}

void Map::put_score_on_map(const int score) {
    char text_buffer[30];
    sprintf_s(text_buffer, "Score %d", score);
    const int len = static_cast<int>(strlen(text_buffer));
    for (int i = 0; i < len; i++) {
        matrix[1][i + 5] = text_buffer[i];
    }
}

void Map::set_cur(const int x, const int y) {
    COORD coord;
    coord.X = static_cast<SHORT>(x);
    coord.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
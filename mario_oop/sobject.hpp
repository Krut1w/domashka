#pragma once

#include <windows.h>

#include "Config.hpp"

class SObject{
    public:
        BOOL is_fly;
        char c_type;
        float height;
        float width;
        float horiz_speed;
        float vert_speed;
        float x;
        float y;

        SObject();

        void set_object_pos(const float x_pos, const float y_pos);
        void init_object(const float x_pos, const float y_pos, const float o_width, const float o_height, const char in_type);

        BOOL is_collision(const SObject o2) const;
        BOOL is_pos_in_map(const int x_pos, const int y_pos) const;

        void put_object_on_map(char map[MAP_HEIGHT][MAP_WIDTH + 1]) const;
};
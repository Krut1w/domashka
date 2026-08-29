#include "SObject.hpp"

#include <cmath>

SObject::SObject(){
    is_fly = FALSE;
    c_type = ' ';
    height = 0;
    width = 0;
    horiz_speed = 0;
    vert_speed = 0;
    x = 0;
    y = 0;
}

void SObject::set_object_pos(const float x_pos, const float y_pos){
    x = x_pos;
    y = y_pos;
}

void SObject::init_object(const float x_pos, const float y_pos, const float o_width, const float o_height, const char in_type){
    set_object_pos(x_pos, y_pos);

    width = o_width;
    height = o_height;
    vert_speed = 0;
    c_type = in_type;
    horiz_speed = 0.2f;
    is_fly = TRUE;
}

BOOL SObject::is_collision(const SObject o2) const{
    return ((x + width) > o2.x) && (x < (o2.x + o2.width)) &&
           (((y + height) > o2.y) && (y < (o2.y + o2.height)));
}

BOOL SObject::is_pos_in_map(const int x_pos, const int y_pos) const{
    return ((x_pos >= 0) && (x_pos < MAP_WIDTH) &&
            (y_pos >= 0) && (y_pos < MAP_HEIGHT));
}

void SObject::put_object_on_map(char map[MAP_HEIGHT][MAP_WIDTH + 1]) const{
    const int ix = (int)round(x);
    const int iy = (int)round(y);
    const int i_width = (int)round(width);
    const int i_height = (int)round(height);

    for (int i = ix; i < ix + i_width; i++){
        for (int j = iy; j < iy + i_height; j++){
            if (is_pos_in_map(i, j)){
                map[j][i] = c_type;
            }
        }
    }
}
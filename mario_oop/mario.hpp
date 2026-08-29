#pragma once

#include "SObject.hpp"

class Mario : public SObject{
    public:
        void vert_move_object(SObject* const obj, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
        void horizon_move_object(SObject* const obj, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
        void mario_collision(SObject*& moving, int& moving_length, int& score, SObject*& brick, int& brick_length, int& level, int& max_lvl);
};
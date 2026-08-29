#pragma once

#include "Map.hpp"
#include "SObject.hpp"

class Mario;

class Game{
    private:
        Map map_obj;
        Mario* mario_ptr;

        SObject* brick;
        SObject* moving;

        int brick_length;
        int moving_length;
        int level;
        int score;
        int max_lvl;

    public:
        Game();
        ~Game();

        void create_level(const int lvl);
        void player_dead();
        void horizon_move_map(const float dx);

        SObject* get_new_brick(SObject*& brick_ref, int& brick_len);
        SObject* get_new_moving(SObject*& moving_ref, int& moving_len);

        void delete_moving(SObject*& moving_ref, int& moving_len, const int i);

        void run();
};
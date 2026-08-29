#include "Game.hpp"
#include "Mario.hpp"

#include <cstdlib>
#include <windows.h>

Game::Game(){
    brick = NULL;
    moving = NULL;

    brick_length = 0;
    moving_length = 0;

    level = 1;
    score = 0;
    max_lvl = 3;

    mario_ptr = new Mario();

    create_level(level);
}

Game::~Game(){
    if (brick != NULL){
        delete[] brick;
    }

    if (moving != NULL){
        delete[] moving;
    }

    if (mario_ptr != NULL){
        delete mario_ptr;
    }
}

void Game::player_dead(){
    system("color 4F");
    Sleep(1000);

    create_level(level);
}

void Game::horizon_move_map(const float dx){
    mario_ptr->x -= dx;

    for (int i = 0; i < brick_length; i++){
        if (mario_ptr->is_collision(brick[i])){
            mario_ptr->x += dx;
            return;
        }
    }

    mario_ptr->x += dx;

    for (int i = 0; i < brick_length; i++){
        brick[i].x += dx;
    }

    for (int i = 0; i < moving_length; i++){
        moving[i].x += dx;
    }
}

SObject* Game::get_new_brick(SObject*& brick_ref, int& brick_len){
    brick_len++;

    SObject* temp_brick = new SObject[brick_len];

    if (brick_ref != NULL){
        for (int j = 0; j < brick_len - 1; j++){
            temp_brick[j] = brick_ref[j];
        }

        delete[] brick_ref;
    }

    brick_ref = temp_brick;

    return brick_ref + brick_len - 1;
}

SObject* Game::get_new_moving(SObject*& moving_ref, int& moving_len){
    moving_len++;

    SObject* temp_moving = new SObject[moving_len];

    if (moving_ref != NULL){
        for (int j = 0; j < moving_len - 1; j++){
            temp_moving[j] = moving_ref[j];
        }

        delete[] moving_ref;
    }

    moving_ref = temp_moving;

    return moving_ref + moving_len - 1;
}

void Game::delete_moving(SObject*& moving_ref, int& moving_len, const int i){
    moving_len--;

    if (moving_len > 0){
        moving_ref[i] = moving_ref[moving_len];

        SObject* temp_moving = new SObject[moving_len];

        for (int j = 0; j < moving_len; j++){
            temp_moving[j] = moving_ref[j];
        }

        delete[] moving_ref;
        moving_ref = temp_moving;
    }
    else{
        delete[] moving_ref;
        moving_ref = NULL;
    }
}

void Game::create_level(const int lvl){
    system("color 9F");

    if (brick != NULL){
        delete[] brick;
        brick = NULL;
    }

    if (moving != NULL){
        delete[] moving;
        moving = NULL;
    }

    brick_length = 0;
    moving_length = 0;

    mario_ptr->init_object(39, 10, 3, 3, '@');

    score = 0;

    switch (lvl){
        case 1:{
            get_new_brick(brick, brick_length)->init_object(20, 20, 40, 5, '#');
            get_new_brick(brick, brick_length)->init_object(30, 10, 5, 3, '?');
            get_new_brick(brick, brick_length)->init_object(50, 10, 5, 3, '?');
            get_new_brick(brick, brick_length)->init_object(60, 15, 40, 10, '#');
            get_new_brick(brick, brick_length)->init_object(60, 5, 10, 3, '-');
            get_new_brick(brick, brick_length)->init_object(70, 5, 5, 3, '?');
            get_new_brick(brick, brick_length)->init_object(75, 5, 5, 3, '-');
            get_new_brick(brick, brick_length)->init_object(80, 5, 5, 3, '?');
            get_new_brick(brick, brick_length)->init_object(85, 5, 10, 3, '-');
            get_new_brick(brick, brick_length)->init_object(100, 20, 20, 5, '#');
            get_new_brick(brick, brick_length)->init_object(120, 15, 10, 10, '#');
            get_new_brick(brick, brick_length)->init_object(150, 20, 40, 5, '#');
            get_new_brick(brick, brick_length)->init_object(210, 15, 10, 10, '+');

            get_new_moving(moving, moving_length)->init_object(25, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(80, 10, 3, 2, 'o');

            break;
        }

        case 2:{
            get_new_brick(brick, brick_length)->init_object(20, 20, 40, 5, '#');
            get_new_brick(brick, brick_length)->init_object(60, 15, 10, 10, '#');
            get_new_brick(brick, brick_length)->init_object(80, 20, 20, 5, '#');
            get_new_brick(brick, brick_length)->init_object(120, 15, 10, 10, '#');
            get_new_brick(brick, brick_length)->init_object(150, 20, 40, 5, '#');
            get_new_brick(brick, brick_length)->init_object(210, 15, 10, 10, '+');

            get_new_moving(moving, moving_length)->init_object(25, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(80, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(65, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(120, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(160, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(175, 10, 3, 2, 'o');

            break;
        }

        case 3:{
            get_new_brick(brick, brick_length)->init_object(20, 20, 40, 5, '#');
            get_new_brick(brick, brick_length)->init_object(80, 20, 15, 5, '#');
            get_new_brick(brick, brick_length)->init_object(120, 15, 15, 10, '#');
            get_new_brick(brick, brick_length)->init_object(160, 10, 15, 15, '+');

            get_new_moving(moving, moving_length)->init_object(25, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(50, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(80, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(90, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(120, 10, 3, 2, 'o');
            get_new_moving(moving, moving_length)->init_object(130, 10, 3, 2, 'o');

            break;
        }
    }

    max_lvl = 3;
}

void Game::run(){
    do{
        map_obj.clear_map();

        if ((mario_ptr->is_fly == FALSE) && (GetKeyState(VK_SPACE) < 0)){
            mario_ptr->vert_speed = -1;
        }

        if (GetKeyState('A') < 0){
            horizon_move_map(1);
        }

        if (GetKeyState('D') < 0){
            horizon_move_map(-1);
        }

        if (mario_ptr->y > MAP_HEIGHT){
            player_dead();
        }

        mario_ptr->vert_move_object(
            mario_ptr,
            brick,
            brick_length,
            moving,
            moving_length,
            level,
            score,
            max_lvl,
            *this
        );

        mario_ptr->mario_collision(
            moving,
            moving_length,
            score,
            brick,
            brick_length,
            level,
            max_lvl,
            *this
        );

        for (int i = 0; i < brick_length; i++){
            brick[i].put_object_on_map(map_obj.get_matrix());
        }

        for (int i = 0; i < moving_length; i++){
            mario_ptr->vert_move_object(
                moving + i,
                brick,
                brick_length,
                moving,
                moving_length,
                level,
                score,
                max_lvl,
                *this
            );

            mario_ptr->horizon_move_object(
                moving + i,
                brick,
                brick_length,
                moving,
                moving_length,
                level,
                score,
                max_lvl,
                *this
            );

            moving[i].put_object_on_map(map_obj.get_matrix());
        }

        mario_ptr->put_object_on_map(map_obj.get_matrix());

        map_obj.put_score_on_map(score);

        map_obj.set_cur(0, 0);
        map_obj.show_map();

    }while (GetKeyState(VK_ESCAPE) >= 0);
}
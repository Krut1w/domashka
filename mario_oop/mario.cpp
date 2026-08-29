#include <windows.h>

#include "Map.hpp"
#include "SObject.hpp"

void player_dead(SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
SObject* get_new_moving(SObject*& moving, int& moving_length);
SObject* get_new_brick(SObject*& brick, int& brick_length);
void vert_move_object(SObject* const obj, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
void delete_moving(SObject*& moving, int& moving_length, const int i);
void mario_collision(SObject& mario, SObject*& moving, int& moving_length, int& score, SObject*& brick, int& brick_length, int& level, int& max_lvl);
void horizon_move_object(SObject* const obj, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
void horizon_move_map(const float dx, SObject& mario, SObject*& brick, const int brick_length, SObject*& moving, const int moving_length);
void create_level(const int lvl, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& score, int& max_lvl);

int main(){
    Map map;

    SObject mario;

    SObject* brick = NULL;
    int brick_length = 0;

    SObject* moving = NULL;
    int moving_length = 0;

    int level = 1;
    int score = 0;
    int max_lvl = 3;

    create_level(level, mario, brick, brick_length, moving, moving_length, score, max_lvl);

    do{
        map.clear_map();

        if ((mario.is_fly == FALSE) && (GetKeyState(VK_SPACE) < 0)){
            mario.vert_speed = -1;
        }

        if (GetKeyState('A') < 0){
            horizon_move_map(1, mario, brick, brick_length, moving, moving_length);
        }

        if (GetKeyState('D') < 0){
            horizon_move_map(-1, mario, brick, brick_length, moving, moving_length);
        }

        if (mario.y > MAP_HEIGHT){
            player_dead(mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
        }

        vert_move_object(&mario, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
        mario_collision(mario, moving, moving_length, score, brick, brick_length, level, max_lvl);

        for (int i = 0; i < brick_length; i++){
            brick[i].put_object_on_map(map.get_matrix());
        }

        for (int i = 0; i < moving_length; i++){
            vert_move_object(moving + i, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
            horizon_move_object(moving + i, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);

            moving[i].put_object_on_map(map.get_matrix());
        }

        mario.put_object_on_map(map.get_matrix());

        map.put_score_on_map(score);
        map.set_cur(0, 0);
        map.show_map();

        //Sleep(10);

    }while (GetKeyState(VK_ESCAPE) >= 0);

    if (brick != NULL){
        delete[] brick;
    }

    if (moving != NULL){
        delete[] moving;
    }

    return 0;
}

void player_dead(SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    system("color 4F");
    Sleep(1000);

    create_level(level, mario, brick, brick_length, moving, moving_length, score, max_lvl);
}

void vert_move_object(SObject* const obj, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    obj->is_fly = TRUE;
    obj->vert_speed += 0.05f;

    obj->set_object_pos(obj->x, obj->y + obj->vert_speed);

    for (int i = 0; i < brick_length; i++){
        if (obj->is_collision(brick[i])){
            if (obj->vert_speed > 0){
                obj->is_fly = FALSE;
            }

            if ((brick[i].c_type == '?') && (obj->vert_speed < 0) && (obj == &mario)){
                brick[i].c_type = '-';

                get_new_moving(moving, moving_length)->init_object(
                    brick[i].x,
                    brick[i].y - 3,
                    3,
                    2,
                    '$'
                );

                moving[moving_length - 1].vert_speed = -0.7f;
            }

            obj->set_object_pos(obj->x, obj->y - obj->vert_speed);
            obj->vert_speed = 0;

            if ((brick[i].c_type == '+') && (obj == &mario)){
                level++;

                if (level > max_lvl){
                    level = 1;
                }

                system("color 2F");

                create_level(level, mario, brick, brick_length, moving, moving_length, score, max_lvl);

                Sleep(1000);
            }

            break;
        }
    }
}

void delete_moving(SObject*& moving, int& moving_length, const int i){
    moving_length--;

    if (moving_length > 0){
        moving[i] = moving[moving_length];

        SObject* temp_moving = new SObject[moving_length];

        for (int j = 0; j < moving_length; j++){
            temp_moving[j] = moving[j];
        }

        delete[] moving;
        moving = temp_moving;
    }
    else{
        delete[] moving;
        moving = NULL;
    }
}

void mario_collision(SObject& mario, SObject*& moving, int& moving_length, int& score, SObject*& brick, int& brick_length, int& level, int& max_lvl){
    for (int i = 0; i < moving_length; i++){
        if (mario.is_collision(moving[i])){
            switch (moving[i].c_type){
                case 'o':{
                    const bool is_mario_falling_on_top =
                        (mario.is_fly == TRUE) &&
                        (mario.vert_speed > 0) &&
                        (mario.y + mario.height < moving[i].y + moving[i].height * 0.5f);

                    if (is_mario_falling_on_top){
                        score += 50;

                        delete_moving(moving, moving_length, i);
                        i--;
                    }
                    else{
                        player_dead(mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
                    }

                    break;
                }

                case '$':{
                    score += 100;

                    delete_moving(moving, moving_length, i);
                    i--;

                    break;
                }
            }
        }
    }
}

void horizon_move_object(SObject* const obj, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    obj->x += obj->horiz_speed;

    for (int i = 0; i < brick_length; i++){
        if (obj->is_collision(brick[i])){
            obj->x -= obj->horiz_speed;
            obj->horiz_speed = -obj->horiz_speed;

            return;
        }
    }

    if (obj->c_type == 'o'){
        SObject tmp = *obj;

        vert_move_object(&tmp, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);

        if (tmp.is_fly == TRUE){
            obj->x -= obj->horiz_speed;
            obj->horiz_speed = -obj->horiz_speed;
        }
    }
}

void horizon_move_map(const float dx, SObject& mario, SObject*& brick, const int brick_length, SObject*& moving, const int moving_length){
    mario.x -= dx;

    for (int i = 0; i < brick_length; i++){
        if (mario.is_collision(brick[i])){
            mario.x += dx;
            return;
        }
    }

    mario.x += dx;

    for (int i = 0; i < brick_length; i++){
        brick[i].x += dx;
    }

    for (int i = 0; i < moving_length; i++){
        moving[i].x += dx;
    }
}

SObject* get_new_brick(SObject*& brick, int& brick_length){
    brick_length++;

    SObject* temp_brick = new SObject[brick_length];

    if (brick != NULL){
        for (int j = 0; j < brick_length - 1; j++){
            temp_brick[j] = brick[j];
        }

        delete[] brick;
    }

    brick = temp_brick;

    return brick + brick_length - 1;
}

SObject* get_new_moving(SObject*& moving, int& moving_length){
    moving_length++;

    SObject* temp_moving = new SObject[moving_length];

    if (moving != NULL){
        for (int j = 0; j < moving_length - 1; j++){
            temp_moving[j] = moving[j];
        }

        delete[] moving;
    }

    moving = temp_moving;

    return moving + moving_length - 1;
}

void create_level(const int lvl, SObject& mario, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& score, int& max_lvl){
    system("color 9F");

    brick_length = 0;
    delete[] brick;
    brick = NULL;

    moving_length = 0;
    delete[] moving;
    moving = NULL;

    mario.init_object(39, 10, 3, 3, '@');

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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

#include "Map.hpp"

typedef struct SObject {
    float x, y;
    float width, height;
    float vert_speed;
    BOOL is_fly;
    char c_type;
    float horiz_speed;
} TObject;

void set_object_pos(TObject* const obj, const float x_pos, const float y_pos);
void init_object(TObject* const obj, const float x_pos, const float y_pos, const float o_width, const float o_height, const char in_type);
void player_dead(TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
BOOL is_collision(const TObject o1, const TObject o2);
TObject* get_new_moving(TObject*& moving, int& moving_length);
TObject* get_new_brick(TObject*& brick, int& brick_length);
void vert_move_object(TObject* const obj, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
void delete_moving(TObject*& moving, int& moving_length, const int i);
void mario_collision(TObject& mario, TObject*& moving, int& moving_length, int& score, TObject*& brick, int& brick_length, int& level, int& max_lvl);
void horizon_move_object(TObject* const obj, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl);
BOOL is_pos_in_map(const int x, const int y);
void put_object_on_map(char map[MAP_HEIGHT][MAP_WIDTH + 1], const TObject obj);
void horizon_move_map(const float dx, TObject& mario, TObject*& brick, const int brick_length, TObject*& moving, const int moving_length);
void create_level(const int lvl, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& score, int& max_lvl);

int main(){
    Map map;

    TObject mario;

    TObject* brick = NULL;
    int brick_length = 0;

    TObject* moving = NULL;
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
            put_object_on_map(map.get_matrix(), brick[i]);
        }

        for (int i = 0; i < moving_length; i++){
            vert_move_object(moving + i, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
            horizon_move_object(moving + i, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);
            put_object_on_map(map.get_matrix(), moving[i]);
        }

        put_object_on_map(map.get_matrix(), mario);
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

void set_object_pos(TObject* const obj, const float x_pos, const float y_pos){
    (*obj).x = x_pos;
    (*obj).y = y_pos;
}

void init_object(TObject* const obj, const float x_pos, const float y_pos, const float o_width, const float o_height, const char in_type){
    set_object_pos(obj, x_pos, y_pos);
    (*obj).width = o_width;
    (*obj).height = o_height;
    (*obj).vert_speed = 0;
    (*obj).c_type = in_type;
    (*obj).horiz_speed = 0.2f;
}

void player_dead(TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    system("color 4F");
    Sleep(1000);

    create_level(level, mario, brick, brick_length, moving, moving_length, score, max_lvl);
}

void vert_move_object(TObject* const obj, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    (*obj).is_fly = TRUE;
    (*obj).vert_speed += 0.05;

    set_object_pos(obj, (*obj).x, (*obj).y + (*obj).vert_speed);

    for (int i = 0; i < brick_length; i++){
        if (is_collision(*obj, brick[i])){
            if ((*obj).vert_speed > 0){
                (*obj).is_fly = FALSE;
            }

            if ((brick[i].c_type == '?') && ((*obj).vert_speed < 0) && (obj == &mario)){
                brick[i].c_type = '-';

                init_object(
                    get_new_moving(moving, moving_length),
                    brick[i].x,
                    brick[i].y - 3,
                    3,
                    2,
                    '$'
                );

                moving[moving_length - 1].vert_speed = -0.7f;
            }

            (*obj).y -= (*obj).vert_speed;
            (*obj).vert_speed = 0;

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

void delete_moving(TObject*& moving, int& moving_length, const int i){
    moving_length--;

    if (moving_length > 0){
        moving[i] = moving[moving_length];

        TObject* temp_moving = new TObject[moving_length];

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

void mario_collision(TObject& mario, TObject*& moving, int& moving_length, int& score, TObject*& brick, int& brick_length, int& level, int& max_lvl){
    for (int i = 0; i < moving_length; i++){
        if (is_collision(mario, moving[i])){
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

void horizon_move_object(TObject* const obj, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    (*obj).x += (*obj).horiz_speed;

    for (int i = 0; i < brick_length; i++){
        if (is_collision(*obj, brick[i])){
            (*obj).x -= (*obj).horiz_speed;
            (*obj).horiz_speed = -(*obj).horiz_speed;

            return;
        }
    }

    if ((*obj).c_type == 'o'){
        TObject tmp = *obj;

        vert_move_object(&tmp, mario, brick, brick_length, moving, moving_length, level, score, max_lvl);

        if (tmp.is_fly == TRUE){
            (*obj).x -= (*obj).horiz_speed;
            (*obj).horiz_speed = -(*obj).horiz_speed;
        }
    }
}

BOOL is_pos_in_map(const int x, const int y){
    return ((x >= 0) && (x < MAP_WIDTH) && (y >= 0) && (y < MAP_HEIGHT));
}

void put_object_on_map(char map[MAP_HEIGHT][MAP_WIDTH + 1], const TObject obj){
    const int ix = (int)round(obj.x);
    const int iy = (int)round(obj.y);
    const int i_width = (int)round(obj.width);
    const int i_height = (int)round(obj.height);

    for (int i = ix; i < (ix + i_width); i++){
        for (int j = iy; j < (iy + i_height); j++){
            if (is_pos_in_map(i, j)){
                map[j][i] = obj.c_type;
            }
        }
    }
}

void horizon_move_map(const float dx, TObject& mario, TObject*& brick, const int brick_length, TObject*& moving, const int moving_length){
    mario.x -= dx;

    for (int i = 0; i < brick_length; i++){
        if (is_collision(mario, brick[i])){
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

BOOL is_collision(const TObject o1, const TObject o2){
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
           (((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height)));
}

TObject* get_new_brick(TObject*& brick, int& brick_length){
    brick_length++;

    TObject* temp_brick = new TObject[brick_length];

    if (brick != NULL){
        for (int j = 0; j < brick_length - 1; j++){
            temp_brick[j] = brick[j];
        }

        delete[] brick;
    }

    brick = temp_brick;

    return brick + brick_length - 1;
}

TObject* get_new_moving(TObject*& moving, int& moving_length){
    moving_length++;

    TObject* temp_moving = new TObject[moving_length];

    if (moving != NULL){
        for (int j = 0; j < moving_length - 1; j++){
            temp_moving[j] = moving[j];
        }

        delete[] moving;
    }

    moving = temp_moving;

    return moving + moving_length - 1;
}

void create_level(const int lvl, TObject& mario, TObject*& brick, int& brick_length, TObject*& moving, int& moving_length, int& score, int& max_lvl){
    system("color 9F");

    brick_length = 0;
    delete[] brick;
    brick = NULL;

    moving_length = 0;
    delete[] moving;
    moving = NULL;

    init_object(&mario, 39, 10, 3, 3, '@');
    score = 0;

    switch (lvl){
        case 1:{
            init_object(get_new_brick(brick, brick_length), 20, 20, 40, 5, '#');
            init_object(get_new_brick(brick, brick_length), 30, 10, 5, 3, '?');
            init_object(get_new_brick(brick, brick_length), 50, 10, 5, 3, '?');
            init_object(get_new_brick(brick, brick_length), 60, 15, 40, 10, '#');
            init_object(get_new_brick(brick, brick_length), 60, 5, 10, 3, '-');
            init_object(get_new_brick(brick, brick_length), 70, 5, 5, 3, '?');
            init_object(get_new_brick(brick, brick_length), 75, 5, 5, 3, '-');
            init_object(get_new_brick(brick, brick_length), 80, 5, 5, 3, '?');
            init_object(get_new_brick(brick, brick_length), 85, 5, 10, 3, '-');
            init_object(get_new_brick(brick, brick_length), 100, 20, 20, 5, '#');
            init_object(get_new_brick(brick, brick_length), 120, 15, 10, 10, '#');
            init_object(get_new_brick(brick, brick_length), 150, 20, 40, 5, '#');
            init_object(get_new_brick(brick, brick_length), 210, 15, 10, 10, '+');

            init_object(get_new_moving(moving, moving_length), 25, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 80, 10, 3, 2, 'o');

            break;
        }

        case 2:{
            init_object(get_new_brick(brick, brick_length), 20, 20, 40, 5, '#');
            init_object(get_new_brick(brick, brick_length), 60, 15, 10, 10, '#');
            init_object(get_new_brick(brick, brick_length), 80, 20, 20, 5, '#');
            init_object(get_new_brick(brick, brick_length), 120, 15, 10, 10, '#');
            init_object(get_new_brick(brick, brick_length), 150, 20, 40, 5, '#');
            init_object(get_new_brick(brick, brick_length), 210, 15, 10, 10, '+');

            init_object(get_new_moving(moving, moving_length), 25, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 80, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 65, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 120, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 160, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 175, 10, 3, 2, 'o');

            break;
        }

        case 3:{
            init_object(get_new_brick(brick, brick_length), 20, 20, 40, 5, '#');
            init_object(get_new_brick(brick, brick_length), 80, 20, 15, 5, '#');
            init_object(get_new_brick(brick, brick_length), 120, 15, 15, 10, '#');
            init_object(get_new_brick(brick, brick_length), 160, 10, 15, 15, '+');

            init_object(get_new_moving(moving, moving_length), 25, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 50, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 80, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 90, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 120, 10, 3, 2, 'o');
            init_object(get_new_moving(moving, moving_length), 130, 10, 3, 2, 'o');

            break;
        }
    }

    max_lvl = 3;
}
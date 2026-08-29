#include "Mario.hpp"

#include <windows.h>

void Mario::vert_move_object(SObject* const obj, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
    obj->is_fly = TRUE;
    obj->vert_speed += 0.05f;

    obj->set_object_pos(obj->x, obj->y + obj->vert_speed);

    for (int i = 0; i < brick_length; i++){
        if (obj->is_collision(brick[i])){
            if (obj->vert_speed > 0){
                obj->is_fly = FALSE;
            }

            if ((brick[i].c_type == '?') && (obj->vert_speed < 0) && (obj == this)){
                brick[i].c_type = '-';

                moving_length++;

                SObject* temp_moving = new SObject[moving_length];

                if (moving != NULL){
                    for (int j = 0; j < moving_length - 1; j++){
                        temp_moving[j] = moving[j];
                    }

                    delete[] moving;
                }

                moving = temp_moving;

                moving[moving_length - 1].init_object(
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

            if ((brick[i].c_type == '+') && (obj == this)){
                level++;

                if (level > max_lvl){
                    level = 1;
                }
            }

            break;
        }
    }
}

void Mario::horizon_move_object(SObject* const obj, SObject*& brick, int& brick_length, SObject*& moving, int& moving_length, int& level, int& score, int& max_lvl){
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

        vert_move_object(&tmp, brick, brick_length, moving, moving_length, level, score, max_lvl);

        if (tmp.is_fly == TRUE){
            obj->x -= obj->horiz_speed;
            obj->horiz_speed = -obj->horiz_speed;
        }
    }
}

void Mario::mario_collision(SObject*& moving, int& moving_length, int& score, SObject*& brick, int& brick_length, int& level, int& max_lvl){
    for (int i = 0; i < moving_length; i++){
        if (is_collision(moving[i])){
            switch (moving[i].c_type){
                case 'o':{
                    const bool is_mario_falling_on_top =
                        (is_fly == TRUE) &&
                        (vert_speed > 0) &&
                        (y + height < moving[i].y + moving[i].height * 0.5f);

                    if (is_mario_falling_on_top){
                        score += 50;

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

                        i--;
                    }

                    break;
                }

                case '$':{
                    score += 100;

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

                    i--;

                    break;
                }
            }
        }
    }
}
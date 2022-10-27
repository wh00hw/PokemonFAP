#include "player.h"


void draw_player(Canvas* canvas, Player* player){
    switch (player->movement)
    {
    case DownStale:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_down_stale);
        break;
    case DownMoving:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_down_moving);
        break;
    case UpStale:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_up_stale);
        break;
    case UpMoving:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_up_moving);
        break;
    case LeftStale:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_left_stale);
        break;
    case LeftMoving:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_left_moving);
        break;
    case RightStale:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_right_stale);
        break;
    case RightMoving:
        canvas_draw_icon(canvas, player->x, player->y, &I_red_right_moving);
        break;
    default:
        break;
    }
}

void handle_player_movement(InputEvent event, Player* player){
    if(event.type == InputTypePress || event.type == InputTypeRepeat) {
                switch(event.key) {
                case InputKeyLeft:
                    if(player->movement == LeftMoving)
                        player->movement = LeftStale;
                    else
                        player->movement = LeftMoving;
                    break;
                case InputKeyRight:
                    if(player->movement == RightMoving)
                        player->movement = RightStale;
                    else
                        player->movement = RightMoving;
                    break;
                case InputKeyUp:
                    if(player->movement == UpMoving)
                        player->movement = UpStale;
                    else
                        player->movement = UpMoving;
                    break;
                case InputKeyDown:
                    if(player->movement == DownMoving)
                        player->movement = DownStale;
                    else
                        player->movement = DownMoving;
                    break;
                default:
                    break;
                }
            }else if(event.type == InputTypeRelease){
                switch (player->movement)
                {
                case DownMoving:
                    player->movement = DownStale;
                    break;
                case UpMoving:
                    player->movement = UpStale;
                    break;
                case LeftMoving:
                    player->movement = LeftStale;
                    break;
                case RightMoving:
                    player->movement = RightStale;
                    break;
                default:
                    break;
                }
            }
        
}
#include "land.h"

void draw_land(Canvas* canvas, uint32_t player_x, uint32_t player_y){
    for (size_t i = 0; i < 128; i+=8)
    {
        for (size_t j= 0; j < 64; j+=8)
        {
            if(!((i == player_x || i == player_x + 8) && (j == player_y || j == player_y + 8)))
                canvas_draw_icon(canvas, i, j, &I_grass);

        }
        
    }
    
}

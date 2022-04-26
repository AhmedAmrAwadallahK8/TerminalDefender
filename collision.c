#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "screen.h"
#include "collision.h"
#include "spider.h"
#include "spiders.h"
#include "p_bullet.h"
#include "p_bullets.h"
#include "player.h"
#include "td_math.h"


//Checks if two rectangles overlap. If their overlap area is greater than zero return true, false otherwise
bool rect_overlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int max_x1, min_x2, max_y1, min_y2;
    max_x1 = max(ax1, bx1);
    min_x2 = min(ax2, bx2);
    max_y1 = max(ay1, by1);
    min_y2 = min(ay2, by2);
    if((min_x2 - max_x1 >= 0) && (min_y2 - max_y1 >= 0)){return true; }
    return false;
    
}

//Check if bullet collided with anything
bool bullet_spider(struct P_Bullet * pb, struct Spider * s){
    return rect_overlap(pb->x, pb->y, pb->x+pb->w, pb->y+pb->h, s->x, s->y,s->x+s->w,s->y+s->h);
}

//Check if bullet collided with edge of screen
bool bullet_edge(struct P_Bullet * pb){
    if(pb->x > term_width){return true; }
    return false;
}

//Check if spider entity collided with player
void spider_check(){

}

//Handle Interaction after spider collides with player
void handle_spider(){

}

//Handle bullet interactions
void handle_bullet(){

}

//Main Collision Function
void detect_collision(struct Player * p, struct Spiders * spids, struct P_Bullets * pbs){
    bool collision = false;
    struct P_Bullet * curr_pb = NULL;
    struct Spider * curr_s = NULL;
    //Bullet
    for(int i = 0; i < MAX_BULLETS; i++){
        collision = false;
        if(pbs->state_arr[i] == 0){continue; }

        curr_pb = pbs->ptr_arr[i];

        collision = bullet_edge(curr_pb);
        if(collision){rem_p_bullet(pbs, curr_pb); continue; }

        for(int j = 0; j < MAX_SPIDERS; j++){
            if(spids->state_arr[j] == 0){continue; }
            curr_s = spids->ptr_arr[j];
            collision = bullet_spider(curr_pb, curr_s);
            if(collision){rem_p_bullet(pbs, curr_pb); rem_spider(spids, curr_s); continue;}
        }
    }

    //Spider
}
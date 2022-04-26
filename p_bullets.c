#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "p_bullets.h"
#include "p_bullet.h"
#include "player.h"

//Create P_Bullets struct
struct P_Bullets create_p_bullets(){
    struct P_Bullets pbs;
    pbs.bullet_count = 0;
    pbs.running_tot = 0;
    for(int i = 0; i < MAX_BULLETS; i++){
        pbs.ptr_arr[i] = NULL;
        pbs.state_arr[i] = 0;
    }
    return pbs;
}

//Adds new bullet to the data structure
void add_p_bullet(struct P_Bullets *pbs, struct Player *p){
    //Note does not handle situations where bullets exceed the array size
    pbs->running_tot++;
    pbs->bullet_count++;
    
    int i = 0;
    while((pbs->state_arr[i] > 0) && (i < MAX_BULLETS)){
        i++;
    }
    if(i != MAX_BULLETS){
        pbs->state_arr[i] = pbs->running_tot;
        pbs->ptr_arr[i] = create_pb_ptr(p->x, p->y);
    }
    else{ //In the futuer I want else to just remove the oldest bullet and replace it with the new one
        printf("\nP_Bullets Error: Index out of bounds"); exit(EXIT_FAILURE);
    }


}

//Removes bullet from the data structure
void rem_p_bullet(struct P_Bullets *pbs, struct P_Bullet *pb){
    struct P_Bullet *curr_pb = NULL;
    for(int i = 0; i < MAX_BULLETS; i++){
        curr_pb = pbs->ptr_arr[i];
        if(curr_pb == pb){
            free_p_bullet(pb);
            pbs->state_arr[i] = 0;
            pbs->ptr_arr[i] = NULL;
            pbs->bullet_count--;
        }
    }
}

//Passes all bullets to the bullet ai function
void move_p_bullets(struct P_Bullets *pbs){
    for(int i = 0; i < MAX_BULLETS; i++){
        if(pbs->state_arr[i] > 0){bullet_ai(pbs->ptr_arr[i]); }
    }
}
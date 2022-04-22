#ifndef P_BULLETS_H
#define P_BULLETS_H

#include "p_bullet.h"
#include "player.h"

#define MAX_BULLETS 50

struct P_Bullets{
    struct P_Bullet *ptr_arr[MAX_BULLETS];
    int state_arr[MAX_BULLETS];
    int bullet_count;
    int running_tot;
};

//Creates and initializes the P_Bullets struct
struct P_Bullets create_p_bullets();

//Adds new p_bullet to array
void add_p_bullet(struct P_Bullets *pbs, struct Player *p);

//Removes p_bullet from game
void rem_p_bullet(struct P_Bullets *pbs, struct P_Bullet *pb);

//Moves all live bullets
void move_p_bullets(struct P_Bullets *pbs);


#endif
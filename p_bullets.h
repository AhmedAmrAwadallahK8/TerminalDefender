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

//Create P_Bullets struct
struct P_Bullets create_p_bullets();

//Adds new bullet to the data structure
void add_p_bullet(struct P_Bullets *pbs, struct Player *p);

//Removes bullet from the data structure
void rem_p_bullet(struct P_Bullets *pbs, struct P_Bullet *pb);

//Passes all bullets to the bullet ai function
void move_p_bullets(struct P_Bullets *pbs);

//Resets the datastructure
void reset_p_bullets(struct P_Bullets *pbs);


#endif
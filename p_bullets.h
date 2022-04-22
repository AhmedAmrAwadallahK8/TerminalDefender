#ifndef P_BULLETS_H
#define P_BULLETS_H

#include "P_Bullet.h";
const int MAX_BULLETS = 50;

struct P_Bullets{
    struct P_Bullet *ptr_arr[MAX_BULLETS];
    int state_arr[MAX_BULLETS];
    int bullet_count;
    int running_tot;
};

#endif
#ifndef P_BULLETS_H
#define P_BULLETS_H

#include "P_Bullet.h";

struct P_Bullets{
    struct P_Bullet ptr_arr[50] = {0};
    int state_arr[50] = {0};
    int bullet_count = 0;
    int running_tot = 0;
};

#endif
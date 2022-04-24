#ifndef COLLISION_H
#define COLLISION_H


#include "spiders.h"
#include "p_bullets.h"
#include "player.h"

//Main Collision Function
void detect_collision(struct Player * p, struct Spiders * spids, struct P_Bullets * pbs);

#endif
#ifndef RENDER_H
#define RENDER_H


#include "player.h"
#include "p_bullet.h"
#include "p_bullets.h"
#include "spider.h"
#include "spiders.h"

//Clear Terminal and Reset Cursor
void clear_terminal();

//Refresh terminal with updated game state
void refresh_terminal(struct Player *p, struct Spiders * spids, struct P_Bullets * pbs);

#endif
#ifndef RENDER_H
#define RENDER_H


#include "player.h"
#include "p_bullet.h"
#include "p_bullets.h"
#include "spider.h"
#include "spiders.h"


//Go line by line,
//Look through list to see who has an x coordinate closer to right side of screen and draw that first
//Repeat until all entity drawn for line
//Go to next line repeat above.
//Repeat until last line reached on screen


//Clear Terminal and Reset Cursor
void clear_terminal();

//Refresh Terminal Screen with Updated Game State
void refresh_terminal(struct Player *p, struct Spiders * spids, struct P_Bullets * pbs);

#endif
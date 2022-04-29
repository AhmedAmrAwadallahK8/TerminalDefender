#ifndef SPIDER_H
#define SPIDER_H

#include <stdbool.h>
#include "player.h"

//Spider Base Fields
struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving, found_pos_y, found_pos_x;
};

//Creates a spider using dynamic memory
struct Spider * create_spider(int x, int y);

//Frees the memory allocated for this spider
void free_spider(struct Spider * s);

//Decides how spider moves next turn
void spider_ai(struct Spider *s, struct Player *p);

//Prints spider to terminal
int print_spider(struct Spider *s);

#endif
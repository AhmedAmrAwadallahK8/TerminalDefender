#ifndef SPIDERS_H
#define SPIDERS_H

#include <stdbool.h>


#include "spider.h"
#include "player.h"

#define MAX_SPIDERS 40

struct Spiders{
    struct Spider *ptr_arr[MAX_SPIDERS];
    int state_arr[MAX_SPIDERS];
    int spider_count, death_count, difficulty, highest_diff;
    bool diff_increased;
};

//Reduces difficulty level
void reduce_difficulty(struct Spiders * spids);

//Creates spiders data structure
struct Spiders create_spiders();

//Adds spider to the list, if full throws error
void add_spider(struct Spiders * spids, int x, int y);

//Adds spider to list with random start position
void add_spider_rand(struct Spiders * spids, struct Player * p);

//Moves all spiders
void move_spiders(struct Spiders * spids, struct Player *p);

//Handles removal of spider
void rem_spider(struct Spiders *spids, struct Spider *s);

//Resets the dataset
void reset_spiders(struct Spiders *spids);

#endif
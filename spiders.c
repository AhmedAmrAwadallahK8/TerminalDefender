#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "spiders.h"
#include "spider.h"
#include "td_rand.h"
#include "screen.h"

#define SPAWN_PAD 15

//Creates data structure for holding multiple spiders
struct Spiders create_spiders(){
    struct Spiders spids;
    spids.spider_count = 0;
    spids.death_count = 0;
    spids.difficulty = 1;
    spids.highest_diff = 1;
    spids.diff_increased = false;
    for(int i = 0; i < MAX_SPIDERS; i++){
        spids.ptr_arr[i] = NULL;
        spids.state_arr[i] = 0;
    }
    
    return spids;
}

//Reduces difficulty level
void reduce_difficulty(struct Spiders * spids){
    spids->difficulty -= 3;
    if(spids->difficulty < 1){spids->difficulty=1; }
}

//Adds spider to the list, if full throws error
void add_spider(struct Spiders * spids, int x, int y){
    int i = 0;
    while((spids->state_arr[i] != 0) && (i < MAX_SPIDERS)){
        i++;
    }
    if(i != MAX_SPIDERS){
        spids->spider_count++;
        spids->ptr_arr[i] = create_spider(x, y);
        spids->state_arr[i] = 1;
    }
    else{return; printf("\nSpiders Error: Index out of bounds"); exit(EXIT_FAILURE); } //Unreacheable code here
}

//Adds spider to list with random posiiton on screen
void add_spider_rand(struct Spiders * spids, struct Player * p){
    if((spids->death_count > 0) && (spids->death_count % 10 == 0) && (spids->diff_increased == false)){
        if(spids->difficulty != 9){spids->difficulty++; }
        spids->diff_increased = true; }
    else if(spids->death_count % 10 != 0){spids->diff_increased = false; }
    if(spids->highest_diff < spids->difficulty){spids->highest_diff = spids->difficulty; }
    int spawn_chance = rand_num(0, 9/spids->difficulty);
    if(spawn_chance == 0){
        int x;
        do{
            x = rand_num(0, term_width);
        }
        while((x <= (p->x+SPAWN_PAD)) && (x >= (p->x-SPAWN_PAD)));
        int y = rand_num(0, term_height);
        add_spider(spids, x, y);
    }
}


//Moves all spiders
void move_spiders(struct Spiders *spids, struct Player *p){
    for(int i = 0; i < MAX_SPIDERS; i++){
        if(spids->state_arr[i] == 1){
            update_spider_speed(spids->ptr_arr[i], spids->difficulty);
            spider_ai(spids->ptr_arr[i], p);
        }
    }
}

//Handles removal of spider
void rem_spider(struct Spiders *spids, struct Spider *s){
    struct Spider *curr_s = NULL;
    for(int i = 0; i < MAX_SPIDERS; i++){
        curr_s = spids->ptr_arr[i];
        if(curr_s == s){
            free_spider(s);
            spids->state_arr[i] = 0;
            spids->ptr_arr[i] = NULL;
            spids->spider_count--;
            spids->death_count++;
        }
    }
}

//Resets the dataset
void reset_spiders(struct Spiders *spids){
    for(int i = 0; i < MAX_SPIDERS; i++){
        free(spids->ptr_arr[i]);
        spids->ptr_arr[i] = NULL;
        spids->state_arr[i] = 0;
    }
}

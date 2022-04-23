#include <stdlib.h>
#include <stdio.h>

#include "spiders.h"
#include "spider.h"
#include "td_rand.h"
#include "screen.h"

//Creates spiders data structure
struct Spiders create_spiders(){
    struct Spiders spids;
    spids.spider_count = 0;
    for(int i = 0; i < MAX_SPIDERS; i++){
        spids.ptr_arr[i] = NULL;
        spids.state_arr[i] = 0;
    }
    return spids;
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
    else{printf("\nSpiders Error: Index out of bounds"); exit(EXIT_FAILURE); }
}

//Adds spider to list with random posiiton on screen
void add_spider_rand(struct Spiders * spids){
    int x = rand_num(0, term_width);
    int y = rand_num(0, term_height);
    add_spider(spids, x, y);
}


//Handles an array of spiders movement
void move_spiders(struct Spiders *spids){
    for(int i = 0; i < MAX_SPIDERS; i++){
        if(spids->state_arr[i] == 1){
            spider_ai(spids->ptr_arr[i]);
        }
    }
}

//Handles removal of spider
void rem_spider(struct Spiders *spids, struct Spider s){

}

#include <stdlib.h>
#include <stdio.h>

#include "spiders.h"
#include "spider.h"

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

void move_spiders(struct Spiders *spids){
    for(int i = 0; i < MAX_SPIDERS; i++){
        if(spids->state_arr[i] == 1){
            spider_ai(spids->ptr_arr[i]);
        }
    }
}

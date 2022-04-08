//Go line by line,
//Look through list to see who has an x coordinate closer to right side of screen and draw that first
//Repeat until all entity drawn for line
//Go to next line repeat above.
//Repeat until last line reached on screen
#include <stdio.h>
#include <stdbool.h>

#include "render.h"
#include "player.h"
#include "spider.h"

int term_height = 7;
int term_width = 200;

void new_line(){
    printf("\n");
}

void new_space(){
    printf(" ");
}

void print(char s[]){
    printf("%s", s);
}

void clear_terminal(){
    char primitive_clear[20] = "\x1B[2J\x1B[H";
    printf("%s", primitive_clear);
}

void refresh_terminal(struct Player p, struct Spider s){
    bool entity_drawn = false;
    //Iterate By Line
    for(int i = 0; i <= term_height; i++){
        //Iterate By Space
        for(int j = 0; j<= term_width; j++){
            //Player
            if(i == p.y){p.found_pos_y = true; }

            //Spider

            if(!entity_drawn){new_space(); }
        }
        new_line();
    }
}
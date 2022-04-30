//Go line by line,
//Look through list to see who has an x coordinate closer to right side of screen and draw that first
//Repeat until all entity drawn for line
//Go to next line repeat above.
//Repeat until last line reached on screen
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "render.h"
#include "player.h"
#include "p_bullet.h"
#include "spider.h"
#include "spiders.h"
#include "screen.h"
#include "p_bullets.h"



//Print newline
void new_line(){
    printf("\n");
}

//Print Edge
void print_edge(){
    printf("|");

}

//Print space
void new_space(){
    printf(" ");
}

//Print given string
void print(char s[]){
    printf("%s", s);
}

//Clear Terminal and Reset Cursor
void clear_terminal(){
    char primitive_clear[20] = "\x1B[2J\x1B[H";
    printf("%s", primitive_clear);
}

//Refresh terminal with updated game state
void refresh_terminal(struct Player *p, struct Spiders * spids, struct P_Bullets * pbs){ 
    //Still a bug that causes the screen to extend, think it occurs because of entity overlap
    bool entity_printed = false;

    //Iterate By Line
    for(int i = 0; i <= term_height; i++){
        print_edge();
        //Iterate By Space
        for(int j = 0; j<= term_width; j++){
            entity_printed = false;
            //Player
            if(((i == p->y) | p->found_pos_y) & (j == p->x)){
                p->found_pos_y = true;
                j += print_player(p) - 1;
                //Entity Is being Printed
                entity_printed = true;
            }

            //Player Bullets
            for(int k = 0; k<MAX_BULLETS; k++){
                if(pbs->state_arr[k] > 0){
                    if((j == pbs->ptr_arr[k]->x) & (i == pbs->ptr_arr[k]->y)){
                        j += print_bullet(pbs->ptr_arr[k]) - 1;

                        //Entity Is being Printed
                        entity_printed = true;
                    }
                }
            }

            //Spiders
            for(int k = 0; k < MAX_SPIDERS; k++){
                if(spids->state_arr[k] == 1){
                    if((j == spids->ptr_arr[k]->x) & (i == spids->ptr_arr[k]->y)){
                        j += print_spider(spids->ptr_arr[k]) - 1;

                        //Entity Is being Printed
                        entity_printed = true;
                    }
                }
            }
            if(!entity_printed){new_space(); }
        }
        print_edge();
        new_line();
    }
    printf("Spiders Killed: %d | Difficulty Level: %d \nPlayer Deaths:  %d", spids->death_count, spids->difficulty, p->death_count);
}
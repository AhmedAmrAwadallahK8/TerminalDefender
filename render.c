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
#include "screen.h"




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
    //char primitive_clear[20] = "cls";
    printf("%s", primitive_clear);
}

void refresh_terminal(struct Player *p, struct Spider s[20], int spider_count, struct P_Bullet b[50], int bullet_count){
    bool entity_printed = false;

    //Iterate By Line
    for(int i = 0; i <= term_height; i++){
        //Iterate By Space
        for(int j = 0; j<= term_width; j++){
            entity_printed = false;
            //Player
            if(((i == p->y) | p->found_pos_y) & (j == p->x)){
                p->found_pos_y = true;
                j += print_player(p);

                //Entity Is being Printed
                entity_printed = true;
            }

            //Player Bullets
            for(int k = 0; k<bullet_count; k++){
                if((j == (&b[k])->x) & (i == (&b[k])->y)){
                    j += print_bullet(&b[k]);

                    //Entity Is being Printed
                    entity_printed = true;
                }
            }

            //Spiders
            for(int k = 0; k < spider_count; k++){
                if((j == (&s[k])->x) & (i == (&s[k])->y)){
                    j += print_spider(&s[k]);

                    //Entity Is being Printed
                    entity_printed = true;
                }
            }

            if(!entity_printed){new_space(); }
        }
        new_line();
    }
}
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
#include "spider.h"

int term_height = 8;
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

void refresh_terminal(struct Player *p, struct Spider s[20], int spider_count){
    bool entity_printed = false;

    //Iterate By Line
    for(int i = 0; i <= term_height; i++){
        //Iterate By Space
        for(int j = 0; j<= term_width; j++){
            entity_printed = false;
            //Player
            if(((i == p->y) | p->found_pos_y) & (j == p->x)){
                p->found_pos_y = true; 
                if(p->print_line == 0){
                    //Draw Head
                    print_ph(p->head);

                    //Save Info for next line pass
                    p->print_line++;

                    //Move the x index j forward by how many characters were printed
                    j += strlen(p->head);

                    //Entity Is being Printed
                    entity_printed = true;
                }
                else if(p->print_line == 1){
                    //Draw Body
                    print_pb(p->body);

                    //Save Info for next line pass
                    p->print_line++;

                    //Move the x index j forward by how many characters were printed
                    j += strlen(p->body);

                    //Entity Is being Printed
                    entity_printed = true;
                }
                else if(p->print_line == 2){
                    //Draw Leg Logic
                    if(p->is_moving==true){print_p_moving(p); j += strlen(p->leg1); }
                    else{print_p_still(p); j += strlen(p->leg2); }

                    //Fully Drawn Person Now. Don't reenter drawing conditional
                    p->found_pos_y = false;

                    //Reset for next draw
                    p->print_line = 0;

                    //Entity Is being Printed
                    entity_printed = true;
                }
            
            }

            //Spider
            for(int k = 0; k < spider_count; k++){
                if((j == (&s[k])->x) & (i == (&s[k])->y)){
                    if((&s[k])->is_moving==true){print_s_moving(&s[k]); j += strlen((&s[k])->body1); }
                    else{print_s_still(&s[k]); j += strlen((&s[k])->body2);}

                    //Entity Is being Printed
                    entity_printed = true;
                }
            }

            if(!entity_printed){new_space(); }
        }
        new_line();
    }
}
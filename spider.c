//Make Spider Enemy

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#include "spider.h"
#include "movement.h"
#include "screen.h"
#include "td_rand.h"
#include "player.h"

#define AGGRO_RANGE 100

//Spider Base Fields
//PROBLEM NOTE: NEED TO LEARN HOW TO HAVE STRUCTS DEFINITIONS IN SOURCE FILES
/**struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving;
};**/

//Creates a spider using dynamic memory
struct Spider * create_spider(int x, int y){
    struct Spider * s = malloc(sizeof(struct Spider));
    //Body
    strcpy(s->body1, "|\\O/\\");
    strcpy(s->body2, "/\\O/|");

    //Starting Position(Top Left Of Spider)
    s->x = x; //Spaces
    s->y = y; //NL

    //HitBox
    s->h = 1; //1 Height Unit is one newline
    s->w = 5; //1 Width Unit is two spaces

    //Animation
    s->at = 0;

    //Movement Check
    s->is_moving = false;

    //Position Check
    s->found_pos_y = false;
    s->found_pos_x = false;

    s->speed = 1;

    return s;
}

//Frees the memory allocated for this spider
void free_spider(struct Spider * s){
    free(s);
}

//Move Position Up
void s_move_up(struct Spider *s){
    s->y-= s->speed;
    if(s->y < 0){s->y = term_height; }
    s->is_moving = true;
}

//Move Position Down
void s_move_down(struct Spider *s){
    s->y+=s->speed;
    if(s->y > term_height){s->y = 0; }
    s->is_moving = true;
}

//Move Position Left
void s_move_left(struct Spider *s){
    s->x-=s->speed;
    if(s->x < 0){s->x = term_width; }
    s->is_moving = true;
}

//Move Position Right
void s_move_right(struct Spider *s){
    s->x+=s->speed;
    if(s->x > term_width){s->x = term_width; }
    s->is_moving = true;
}

//Prints Body Version 1 String to Terminal
void print_sb1(char body1[]){
    printf("%s", body1);
}

//Prints Body Version 2 String to Terminal
void print_sb2(char body2[]){
    printf("%s", body2);
}

//Print Spider standing still
void print_s_still(struct Spider *s){
    if(s->at == 0){print_sb1(s->body1); }
    else if(s->at == 1){print_sb2(s->body2); }
}

//Print Spider moving
void print_s_moving(struct Spider *s){
    if(s->at == 0){print_sb1(s->body1); s->at = 1; }
    else if(s->at == 1){print_sb2(s->body2); s->at = 0; }
    s->is_moving = false;
}

//Returns true if player is near to spider
bool player_nearby(struct Spider *s, struct Player *p){
    if(s->x <= (p->x + AGGRO_RANGE)){
        if(s->x >= (p->x - AGGRO_RANGE)){
            return true;
        }
    }
    return false;
}

//Using spider as origin, move toward player
void chase_player(struct Spider *s, struct Player *p){
    double x, y, m;
    x = p->x - s->x;
    y = p->y - s->y + rand_num(0,2);
    //Undefined Slope
    if(x == 0){
        if(y >= 0){
            s_move_down(s);
        }
        else{
            s_move_up(s);
        }
    }
    //Defined Slope
    else{
        m = y/x;
        if((m >= 0.15) || (m <= -0.15)){
            if(y >= 0){
                s_move_down(s);
            }
            else{
                s_move_up(s);
            }
        }
        else{
            if(x >= 0){
                s_move_right(s);
            }
            else{
                s_move_left(s);
            }
        }
    }

}

//Move spider randomly
void move_rand(struct Spider *s){
    int move_dec = rand_num(0,4);
    switch(move_dec){
            case 0: //Don't Move
                return;
            case 1: //Move Left
                s_move_left(s);
                break;
            case 2: //Move Right
                s_move_right(s);
                break;
            case 3: //Move Up
                s_move_up(s);
                break;
            case 4: //Move Down
                s_move_down(s);
                break;        
    }
}

//Changes speed based on difficulty level
void update_spider_speed(struct Spider *s, int diff){
    s->speed = 1 + diff/3;
}

//Decides how spider moves next turn
void spider_ai(struct Spider *s, struct Player *p){
    bool p_near = player_nearby(s, p);
    if(!p_near){
        move_rand(s);
    }
    else{
        chase_player(s, p);
    }
}

//Prints spider to terminal
int print_spider(struct Spider *s){
    if(s->is_moving==true){print_s_moving(s); return strlen(s->body1); }
    else{print_s_still(s); return strlen(s->body2);}
}
//Make Spider Enemy

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "spider.h"
#include "movement.h"
#include "screen.h"

//Spider Base Fields
//PROBLEM NOTE: NEED TO LEARN HOW TO HAVE STRUCTS DEFINITIONS IN SOURCE FILES
/**struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving;
};**/

//TODO: 
struct Spider create_spider(int x, int y){
    struct Spider s;
    //Body
    strcpy(s.body1, "|\\O/\\");
    strcpy(s.body2, "/\\O/|");

    //Starting Position(Top Left Of Spider)
    s.x = x; //Spaces
    s.y = y; //NL

    //HitBox
    s.h = 1; //1 Height Unit is one newline
    s.w = 5; //1 Width Unit is two spaces

    //Animation
    s.at = 0;

    //Movement Check
    s.is_moving = false;

    //Position Check
    s.found_pos_y = false;
    s.found_pos_x = false;

    return s;
}

//Move Position Up
void s_move_up(struct Spider *s){
    s->y--;
    if(s->y < 0){s->y = term_height; }
    s->is_moving = true;
}

//Move Position Down
void s_move_down(struct Spider *s){
    s->y++;
    if(s->y > term_height){s->y = 0; }
    s->is_moving = true;
}

//Move Position Left
void s_move_left(struct Spider *s){
    s->x--;
    if(s->x < 0){s->x = term_width; }
    s->is_moving = true;
}

//Move Position Right
void s_move_right(struct Spider *s){
    s->x++;
    if(s->x > term_width){s->x = 0; }
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

//Randomly generates a number in between specified lower and upper bound inclusive
int rand_num(int lwr, int upr){
    return (rand() % (upr - lwr + 1)) + lwr;
}



//Decides how spider moves next turn
void spider_ai(struct Spider *s){
    int move_dec = rand_num(0,4);
    switch(move_dec){
        case 0: //Don't Move
            return;
        case 1: //Move Left
            return s_move_left(s);
        case 2: //Move Right
            return s_move_right(s);
        case 3: //Move Up
            return s_move_up(s);
        case 4: //Move Down
            return s_move_down(s);        
    }
}

void move_spiders(struct Spider s[], int spider_count){
    for(int i = 0; i < spider_count; i++){
        spider_ai(&s[i]);
    }
}

int print_spider(struct Spider *s){
    if(s->is_moving==true){print_s_moving(s); return strlen(s->body1); }
    else{print_s_still(s); return strlen(s->body2);}
}

//Legacy Code
//Print State 1 of Spider
void print_s1(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body1);
}

//Legacy Code
//Print State 2 of Spider
void print_s2(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body2);
}
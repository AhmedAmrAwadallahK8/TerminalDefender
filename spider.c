//Make Spider Enemy

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "spider.h"
#include "movement.h"

//Spider Base Fields
//PROBLEM NOTE: NEED TO LEARN HOW TO HAVE STRUCTS DEFINITIONS IN SOURCE FILES
/**struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving;
};**/

//TODO: 
struct Spider create_spider(char body1[], char body2[], int x, int y, int h, int w, int at, bool is_moving){
    struct Spider s;
    //Body
    strcpy(s.body1, body1);
    strcpy(s.body2, body2);

    //Starting Position(Top Left Of Spider)
    s.x = x; //Spaces
    s.y = y; //NL

    //HitBox
    s.h = h; //1 Height Unit is one newline
    s.w = w; //1 Width Unit is two spaces

    //Animation
    s.at = at;

    //Movement Check
    s.is_moving = is_moving;

    //Position Check
    s.found_pos_y = false;
    s.found_pos_x = false;

    return s;
}

//Move Position Up
void s_move_up(struct Spider *s){
    s->y--;
    if(s->y < 0){s->y = 0; }
    s->is_moving = true;
}

//Move Position Down
void s_move_down(struct Spider *s){
    s->y++;
    if(s->y > 7){s->y = 7; }
    s->is_moving = true;
}

//Move Position Left
void s_move_left(struct Spider *s){
    s->x--;
    if(s->x < 0){s->x = 0; }
    s->is_moving = true;
}

//Move Position Right
void s_move_right(struct Spider *s){
    s->x++;
    if(s->x > 200){s->x = 200; }
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
            break;
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

void move_spiders(struct Spider s[], int spider_count){
    for(int i = 0; i < spider_count; i++){
        spider_ai(&s[i]);
    }
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
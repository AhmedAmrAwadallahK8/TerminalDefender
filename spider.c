//Make Spider Enemy

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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
struct Spider s_move_up(struct Spider s){
    s.y--;
    if(s.y < 0){s.y = 0; }
    s.is_moving = true;
    return s;
}

//Move Position Down
struct Spider s_move_down(struct Spider s){
    s.y++;
    if(s.y > 7){s.y = 7; }
    s.is_moving = true;
    return s;
}

//Move Position Left
struct Spider s_move_left(struct Spider s){
    s.x--;
    if(s.x < 0){s.x = 0; }
    s.is_moving = true;
    return s;
}

//Move Position Right
struct Spider s_move_right(struct Spider s){
    s.x++;
    if(s.x > 200){s.x = 200; }
    s.is_moving = true;
    return s;
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
void print_s_still(struct Spider s){
    if(s.at == 0){print_sb1(s.body1); }
    else if(s.at == 1){print_sb2(s.body2); }
}

//Print Spider moving
void print_s_moving(struct Spider s){
    if(s.at == 0){print_sb1(s.body1); s.at = 1; }
    else if(s.at == 1){print_sb2(s.body2); s.at = 0; }
    s.is_moving = false;
}

//Print State 1 of Spider
void print_s1(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body1);
}

//Print State 2 of Spider
void print_s2(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body2);
}
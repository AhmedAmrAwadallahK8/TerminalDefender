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
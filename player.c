#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "movement.h"

//Player Base Fields
//PROBLEM NOTE: NEED TO LEARN HOW TO HAVE STRUCTS DEFINITIONS IN SOURCE FILES
/**struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at;
    bool is_moving;
};**/

//TODO: 
struct Player create_player(char head[], char body[], char leg1[], char leg2[], int x, int y, int h, int w, int at, bool is_moving){
    struct Player p;
    //Body
    strcpy(p.head, head);
    strcpy(p.body, body);
    strcpy(p.leg1, leg1);
    strcpy(p.leg2, leg2);

    //Starting Position(Top Left Of Player)
    p.x = x; //Spaces
    p.y = y; //NL

    //HitBox
    p.h = h; //1 Height Unit is one newline
    p.w = w; //1 Width Unit is two spaces

    //Animation
    p.at = at;

    //Movement Check
    p.is_moving = is_moving;

    //Position Check
    p.found_pos_y = false;
    p.found_pos_x = false;

    //Info For Rendering
    p.print_line = 0;
    
    return p;
}

//Move Position Up
struct Player p_move_up(struct Player p){
    p.y--;
    if(p.y < 0){p.y = 0; }
    p.is_moving = true;
    return p;
}

//Move Position Down
struct Player p_move_down(struct Player p){
    p.y++;
    if(p.y > 7){p.y = 7; }
    p.is_moving = true;
    return p;
}

//Move Position Left
struct Player p_move_left(struct Player p){
    p.x--;
    if(p.x < 0){p.x = 0; }
    p.is_moving = true;
    return p;
}

//Move Position Right
struct Player p_move_right(struct Player p){
    p.x++;
    if(p.x > 200){p.x = 200; }
    p.is_moving = true;
    return p;
}





//Prints Head String to Terminal
void print_ph(char head[]){
    printf("%s", head);

}

//Prints Body String to Terminal
void print_pb(char body[]){
    printf("%s", body);
}

//Prints Leg Version 1 String to Terminal
void print_pl1(char leg1[]){
    printf("%s", leg1);
}

//Prints Leg Version 2 String to Terminal
void print_pl2(char leg2[]){
    printf("%s", leg2);
}

//Print player standing still   
void print_p_still(struct Player *p){
    if(p->at == 0){print_pl1(p->leg1); }
    else if(p->at == 1){print_pl2(p->leg2); }
}

//Print player moving
void print_p_moving(struct Player *p){
    if(p->at == 0){print_pl1(p->leg1); p->at = 1; }
    else if(p->at == 1){print_pl2(p->leg2); p->at = 0; }
    p->is_moving = false;
}

//Legacy Code
//Print State 1 of Player
void print_p1(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg1);
}

//Legacy Code
//Print State 2 of Player
void print_p2(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg2);
}
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "player.h"
#include "movement.h"
#include "screen.h"

//Player Base Fields
//PROBLEM NOTE: NEED TO LEARN HOW TO HAVE STRUCTS DEFINITIONS IN SOURCE FILES
/**struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at;
    bool is_moving;
};**/

//Creates a player struct
struct Player create_player(int x, int y){
    struct Player p;
    //Body
    strcpy(p.head, " O ");
    strcpy(p.body, "-|-");
    strcpy(p.leg1, "/| ");
    strcpy(p.leg2, " |\\");

    //Starting Position(Top Left Of Player)
    p.x = x; //Spaces
    p.y = y; //NL

    //HitBox
    p.h = 3; //1 Height Unit is one newline
    p.w = 3; //1 Width Unit is two spaces

    //Animation
    p.at = 0;

    //Movement Check
    p.is_moving = false;

    //Position Check
    p.found_pos_y = false;
    p.found_pos_x = false;

    //Info For Rendering
    p.print_line = 0;

    //Direction Character is Facing
    //0: Right
    //1: Down
    //2: Left
    //3: Up
    p.face_direc = 0;

    p.alive = true;
    
    return p;
}

//Returns player life status
bool player_alive(struct Player * p){
    return p->alive;
}

//Sets player to be dead
void kill_player(struct Player * p){
    p->alive = false;
}

//Move Position Up
struct Player p_move_up(struct Player p){
    p.y--;
    if(p.y < 0){p.y = term_height; }
    p.face_direc = 3;
    p.is_moving = true;
    return p;
}

//Move Position Down
struct Player p_move_down(struct Player p){
    p.y++;
    if(p.y > term_height){p.y = 0; }
    p.face_direc = 1;
    p.is_moving = true;
    return p;
}

//Move Position Left
struct Player p_move_left(struct Player p){
    p.x--;
    if(p.x < 0){p.x = term_width; }
    p.face_direc = 2;
    p.is_moving = true;
    return p;
}

//Move Position Right
struct Player p_move_right(struct Player p){
    p.x++;
    if(p.x > term_width){p.x = 0; }
    p.face_direc = 0;
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

//Print entire player
int print_player(struct Player *p){
    if(p->print_line == 0){
        //Save Info for next line pass
        p->print_line++;

        //Draw Head
        print_ph(p->head);

        //Move the x index j forward by how many characters were printed
        return strlen(p->head);
    }
    else if(p->print_line == 1){
        //Save Info for next line pass
        p->print_line++;

        //Draw Body
        print_pb(p->body);

        //Move the x index j forward by how many characters were printed
        return strlen(p->body);
    }
    else if(p->print_line == 2){
        //Fully Drawn Person Now. Don't reenter drawing conditional
        p->found_pos_y = false;

        //Reset for next draw
        p->print_line = 0;

        //Draw Leg Logic
        if(p->is_moving){print_p_moving(p); return strlen(p->leg1); }
        else{print_p_still(p); return strlen(p->leg2); }
    }
    return 0;
}
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at, print_line, face_direc;
    bool is_moving, found_pos_y, found_pos_x;
};

//TODO: 
struct Player create_player(int x, int y);

//??: Move This Function elsewhere
//Left Right Movement
void LR_movement(int spaces);

//??: Move this function elsewhere
//Up Down Movement
void UD_movement(int nl);

//Move Position Up
struct Player p_move_up(struct Player p);

//Move Position Down
struct Player p_move_down(struct Player p);

//Move Position Left
struct Player p_move_left(struct Player p);

//Move Position Right
struct Player p_move_right(struct Player p);

//Prints Head String to Terminal
void print_ph(char head[]);

//Prints Body String to Terminal
void print_pb(char body[]);

//Prints Leg Version 1 String to Terminal
void print_pl1(char leg1[]);

//Prints Leg Version 2 String to Terminal
void print_pl2(char leg2[]);

//Print player standing still
void print_p_still(struct Player *p);

//Alternates which leg is printed based on animation state
void print_p_moving(struct Player *p);

//Print Player Logic
int print_player(struct Player *p);

//Print State 1 of Player
void print_p1(struct Player p);

//Print State 2 of Player
void print_p2(struct Player p);

#endif
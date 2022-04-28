#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at, print_line, x_face, y_face, death_count;
    bool is_moving, found_pos_y, found_pos_x, alive;
};

//Returns player life status
bool player_alive(struct Player * p);

//Sets player to be dead
void kill_player(struct Player * p);

//Creates a player struct
struct Player create_player(int x, int y);

//Move Position Up
void p_move_up(struct Player * p);

//Move Position Down
void p_move_down(struct Player * p);

//Move Position Left
void p_move_left(struct Player * p);

//Move Position Right
void p_move_right(struct Player * p);

//Print entire player
int print_player(struct Player *p);

#endif
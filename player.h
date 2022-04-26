#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at, print_line, face_direc;
    bool is_moving, found_pos_y, found_pos_x;
};

//Creates a player struct
struct Player create_player(int x, int y);

//Move Position Up
struct Player p_move_up(struct Player p);

//Move Position Down
struct Player p_move_down(struct Player p);

//Move Position Left
struct Player p_move_left(struct Player p);

//Move Position Right
struct Player p_move_right(struct Player p);

//Print entire player
int print_player(struct Player *p);

#endif
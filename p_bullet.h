#ifndef P_BULLET_H
#define P_BULLET_H

struct P_Bullet {
    char body[6];
    int x, y, h, w;
};

//Creates a p_bullet and returns a copy
struct P_Bullet create_p_bullet(int x, int y);

//Creates a p_bullet using dynamic memory
struct P_Bullet * create_pb_ptr(int x, int y);

//Frees memory
void free_p_bullet(struct P_Bullet *b);

//Terminal printing logic
int print_bullet(struct P_Bullet *b);

//Bullet movement ai
void bullet_ai(struct P_Bullet *b);

#endif
#ifndef P_BULLET_H
#define P_BULLET_H

struct P_Bullet {
    char body[6];
    int x, y, h, w;
};

//Creates a P_Bullet and returns a copy of it
struct P_Bullet create_p_bullet(int x, int y);

//Creates a P_Bullet in the heap and returns a pointer to it
struct P_Bullet * create_pb_ptr(int x, int y);

//Frees memory associated with p_bullet
void free_p_bullet(struct P_Bullet *b);

int print_bullet(struct P_Bullet *b);

void move_bullets(struct P_Bullet b[], int bullet_count);

#endif
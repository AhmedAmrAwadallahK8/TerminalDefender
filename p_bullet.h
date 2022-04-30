#ifndef P_BULLET_H
#define P_BULLET_H

#define BULLET_MAX_DIST 60

struct P_Bullet {
    char body_r[6], body_l[6];
    int x, y, h, w, face_direc, speed, distance_trav;
};

//Creates a p_bullet and returns a copy
struct P_Bullet create_p_bullet(int x, int y);

//Creates a p_bullet using dynamic memory
struct P_Bullet * create_pb_ptr(int x, int y, int p_face_direc);

//Frees memory
void free_p_bullet(struct P_Bullet *b);

//Terminal printing logic
int print_bullet(struct P_Bullet *b);

//Bullet movement ai
void bullet_ai(struct P_Bullet *b);

#endif
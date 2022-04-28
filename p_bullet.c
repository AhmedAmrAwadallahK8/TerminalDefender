#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "p_bullet.h"

//Creates a p_bullet and returns a copy
struct P_Bullet create_p_bullet(int x, int y){
    struct P_Bullet b;

    //Appearance
    strcpy(b.body, "->");
    
    //Position
    b.x = x+3;
    b.y = y+1;

    //Size
    b.h = 1;
    b.w = 2;
    
    return b;
}

//Creates a p_bullet using dynamic memory
struct P_Bullet * create_pb_ptr(int x, int y){
    struct P_Bullet *b = malloc(sizeof(struct P_Bullet));

    //Appearance
    strcpy(b->body, "->");
    
    //Position
    b->x = x+3;
    b->y = y+1;

    //Size
    b->h = 1;
    b->w = 2;
    
    return b;
}

//Frees memory
void free_p_bullet(struct P_Bullet *b){
    free(b);
}

//Terminal printing logic
int print_bullet(struct P_Bullet *b){
    printf("%s", b->body);
    return strlen(b->body);
}

//Bullet movement ai
void bullet_ai(struct P_Bullet *b){
    b->x+=6;
}
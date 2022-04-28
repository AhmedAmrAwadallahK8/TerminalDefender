#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "p_bullet.h"

//Creates a p_bullet and returns a copy
struct P_Bullet create_p_bullet(int x, int y){
    struct P_Bullet b;

    //Appearance
    strcpy(b.body_r, "->");
    
    //Position
    b.x = x+3;
    b.y = y+1;

    //Size
    b.h = 1;
    b.w = 2;
    
    return b;
}

//Creates a p_bullet using dynamic memory
struct P_Bullet * create_pb_ptr(int x, int y, int p_x_face){
    struct P_Bullet *b = malloc(sizeof(struct P_Bullet));

    //Appearance
    strcpy(b->body_r, "->");

    //Direction
    b->face_direc = p_x_face;
    
    //Position
    if(b->face_direc == 0){
        strcpy(b->body_r, "->");
        b->x = x+3;
        b->y = y+1;
    }
    else{
        strcpy(b->body_l, "<-");
        b->x = x-3;
        b->y = y+1;
    }

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
    if(b->face_direc == 0){
        printf("%s", b->body_r);
        return strlen(b->body_r);
    }
    else if(b->face_direc == 2){
        printf("%s", b->body_l);
        return strlen(b->body_l);
    }
    return 0;
}

//Bullet movement ai
void bullet_ai(struct P_Bullet *b){
    if(b->face_direc == 0){
        b->x+=6;
    }
    else{
        b->x-=6;
    }
        
}
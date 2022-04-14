#include <string.h>
#include <stdio.h>

#include "p_bullet.h"

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

int print_bullet(struct P_Bullet *b){
    printf("%s", b->body);
    return strlen(b->body);
}

void bullet_ai(struct P_Bullet *b){
    b->x++;
}

void move_bullets(struct P_Bullet b[], int bullet_count){
    for(int i = 0; i < bullet_count; i++){
        bullet_ai(&b[i]);
    }
}
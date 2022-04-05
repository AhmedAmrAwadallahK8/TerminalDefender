#include <stdbool.h>
#include <stdio.h>

//Player Base Fields
struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w;
    bool is_moving;
};

//TODO: 
struct Player create_player(){
    struct Player p;
    return p;
}





//Left Right Movement
void LR_movement(int spaces){
    for(int i = 0; i<spaces; i++){
        printf(" ");
    }
}

//Up Down Movement
void UD_movement(int nl){
    for(int i = 0; i<nl; i++){
        printf("\n");
    }
}

void print_p1(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg1);
}

void print_p2(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg2);
}


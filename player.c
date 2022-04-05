#include <stdbool.h>
#include <stdio.h>

//Player Base Fields
struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w;
    bool is_moving;
};

//TODO: 
struct Player create_player(char head[], char body[], char leg1[], char leg2[], int x, int y, int h, int w, bool is_moving){
    struct Player p;
    //Body
    strcpy(p.head, head);
    strcpy(p.body, body);
    strcpy(p.leg1, leg1);
    strcpy(p.leg2, leg2);

    //Starting Position(Top Left Of Player)
    p.x = x; //Spaces
    p.y = y; //NL

    //HitBox
    p.h = h; //1 Height Unit is one newline
    p.w = w; //1 Width Unit is two spaces

    //Movement Check
    p.is_moving = is_moving;
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

//Print State 1 of Player
void print_p1(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg1);
}

//Print State 2 of Player
void print_p2(struct Player p){
    UD_movement(p.y);
    LR_movement(p.x);
    printf("%s", p.head);
    LR_movement(p.x);
    printf("%s", p.body);
    LR_movement(p.x);
    printf("%s", p.leg2);
}


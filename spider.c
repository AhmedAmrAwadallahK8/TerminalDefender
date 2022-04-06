//Make Spider Enemy

#include <stdbool.h>
#include <stdio.h>

//Player Base Fields
struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving;
};

//TODO: 
struct Spider create_spider(char body1[], char body2[], int x, int y, int h, int w, int at, bool is_moving){
    struct Spider s;
    //Body
    strcpy(s.body1, body1);
    strcpy(s.body2, body2);

    //Starting Position(Top Left Of Player)
    s.x = x; //Spaces
    s.y = y; //NL

    //HitBox
    s.h = h; //1 Height Unit is one newline
    s.w = w; //1 Width Unit is two spaces

    //Animation
    s.at = at;

    //Movement Check
    s.is_moving = is_moving;
    return s;
}

//Print State 1 of Spider
void print_s1(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body1);
}

//Print State 2 of Spider
void print_s2(struct Spider s){
    UD_movement(s.y);
    LR_movement(s.x);
    printf("%s", s.body2);
}
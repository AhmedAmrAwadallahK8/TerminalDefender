#include <stdbool.h>

//Spider Base Fields
struct Spider {
    char body1[20], body2[20];
    int x, y, h, w, at;
    bool is_moving, found_pos_y, found_pos_x;
};

//TODO: 
struct Spider create_spider(char body1[], char body2[], int x, int y, int h, int w, int at, bool is_moving);

//Move Position Up
struct Spider s_move_up(struct Spider s);

//Move Position Down
struct Spider s_move_down(struct Spider s);

//Move Position Left
struct Spider s_move_left(struct Spider s);

//Move Position Right
struct Spider s_move_right(struct Spider s);

//Prints Body Version 1 String to Terminal
void print_sb1(char leg1[]);

//Prints Body Version 2 String to Terminal
void print_sb2(char leg2[]);

//Print Spider standing still
void print_s_still(struct Spider *s);

//Print Spider moving
void print_s_moving(struct Spider *s);

//Print State 1 of Spider
void print_s1(struct Spider s);

//Print State 2 of Spider
void print_s2(struct Spider s);
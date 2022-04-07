
struct Player {
    char head[6], body[6], leg1[6], leg2[6];
    int x, y, h, w, at;
    bool is_moving;
};

//TODO: 
struct Player create_player(char head[], char body[], char leg1[], char leg2[], int x, int y, int h, int w, int at, bool is_moving);

//??: Move This Function elsewhere
//Left Right Movement
void LR_movement(int spaces);

//??: Move this function elsewhere
//Up Down Movement
void UD_movement(int nl);

//Move Position Up
struct Player p_move_up(struct Player p);

//Move Position Down
struct Player p_move_down(struct Player p);

//Move Position Left
struct Player p_move_left(struct Player p);

//Move Position Right
struct Player p_move_right(struct Player p);

//Print State 1 of Player
void print_p1(struct Player p);

//Print State 2 of Player
void print_p2(struct Player p);
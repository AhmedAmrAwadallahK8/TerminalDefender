struct P_Bullet {
    char body[6];
    int x, y, h, w;
};

struct P_Bullet create_p_bullet(int x, int y);

int print_bullet(struct P_Bullet *b);

void move_bullets(struct P_Bullet b[], int bullet_count);
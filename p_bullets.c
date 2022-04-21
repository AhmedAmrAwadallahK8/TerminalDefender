
#include "p_bullets.h"
#include "p_bullet.h"
#include "player.h"

struct P_Bullets create_p_bullets(){
    struct P_Bullets pbs;
    return pbs;
}

//Adds new bullet to array
void add_bullet(struct P_Bullets *pbs, struct Player *p){
    //Note does not handle situations where bullets exceed the array size
    pbs->running_tot++;
    pbs->bullet_count++;
    
    int i = 0;
    while(pbs->state_arr[i] == 0){
        i++;
    }
    pbs->state_arr[i] = pbs->running_tot;
    pbs->ptr_arr[i] = create_p_bullet(p->x, p->y);


}

//
void rem_bullet(struct P_Bullets *pbs, struct P_Bullet *pb){

}
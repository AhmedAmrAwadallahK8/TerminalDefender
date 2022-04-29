//Update With Sourcefiles
#include <stdio.h>
#include <unistd.h>

#include "game.h"

//Possible Things to add
    //Multithreding for collisions maybe later
    //Spider Collision
    //Ramp Difficulty based on kill count 
        //Want to do this FINISH COND
    //Bullet cooldown cba

int main(){
    //char end = 'a';
    //while(end != 'q'){
    //    end = game_start();
    //    if(end == 'd'){printf("\n%s", "You have Died."); sleep(2); }
    //}
    game_start();
    game_end();
}
//Update With Sourcefiles
#include <stdio.h>
#include <unistd.h>

#include "game.h"

//Possible Things to add
    //Multithreding for collisions maybe later
    //Spider Collision
    //Bullet cooldown cba
    //Better terminal clearing https://stackoverflow.com/questions/43116/how-can-i-run-an-external-program-from-c-and-parse-its-output/28971647#28971647

int main(){
    //char end = 'a';
    //while(end != 'q'){
    //    end = game_start();
    //    if(end == 'd'){printf("\n%s", "You have Died."); sleep(2); }
    //}
    game_start();
    game_end();
}
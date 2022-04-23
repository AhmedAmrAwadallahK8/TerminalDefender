#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "player.h"
#include "spider.h"
#include "spiders.h"
#include "render.h"
#include "p_bullet.h"
#include "p_bullets.h"



//Game Time Logic
int gt_logic(int gt){
    gt++;
    if(gt >= 1000000){gt = 0; }
    return gt;
}


//Up: H, 72
//Down: P, 80
//Left: K, 75
//Right: M, 77
//Keyboard Logic
int kb_logic(){
    char in1, in2;
    in1 = getch();
    if(_kbhit()){in2 = getch(); }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if(in1 == -32){return in2; }
    else{return in1; }
}

//Ends Game
void game_end(){
    clear_terminal();
    printf("THANK YOU FOR PLAYING");
    sleep(2);
}

void game_loop(){
    struct Player p;
    struct Spiders spids = create_spiders();
    struct P_Bullets pbs = create_p_bullets();
    int game = 1, gt = 0, wt = 20000;
    
    bool paused = false, update_step = false;
    char input = 0;

    //Set Random Seed
    srand(time(0));

    //Create Initial Entities
    p = create_player(0, 3);

    add_spider(&spids, 10, 4);
    add_spider(&spids, 30, 4);
    add_spider_rand(&spids);

    //Starting Conditions
    //print_p2(p);

    //InitializeScreen

    //Game Start
    while(game == 1){
        update_step = false;
        while((input == 0) & (paused == false)){
            
            if(gt % wt == 0){
                clear_terminal();

                update_step = true; //I think we have some continuity issues here

                //Move NPCs
                //Move Bullet Problem: Untested
                move_p_bullets(&pbs);
                move_spiders(&spids); //Replace

                //Move bullets needs to be ravamped in refresh terminal
                refresh_terminal(&p, &spids, &pbs); //Change input to just be spids

                
            }
            //Keyboard Handling
            if(_kbhit()){input = kb_logic(); }

            //Game Time
            gt = gt_logic(gt);
        }

        //Input Conditionals
        switch(input){
            case 'q': //Quit Game
                game = 0;
                break;
            case 'K': //Player Left
                if(update_step == true){p = p_move_left(p); }
                break; 
            case 'M': //Player Right
                if(update_step == true){p = p_move_right(p); }
                break;
            case 'H': //Player UP
                if(update_step == true){p = p_move_up(p); }
                break;
            case 'P': //Player Down
                if(update_step == true){p = p_move_down(p); }
                break;
            case 'p': //Pause Game
                paused = !paused;
                break;
            case ' ': //Fire Bullet
                add_p_bullet(&pbs, &p);
        }
        input = 0;


        while((input == 0) & (paused == true)){
            //Game is paused Loop
            if(gt % wt == 0){}

            //Keyboard Handling
            if(_kbhit()){input = kb_logic(); }

            //Game Time Handling
            gt = gt_logic(gt);
        }
    }
}

//Starts Game
void game_start(){
    game_loop();
}



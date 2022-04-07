#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "game.h"
#include "player.h"
#include "spider.h"
#include "render.h"

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
    struct Spider s1;
    int game = 1, gt = 0, wt = 20000;
    
    bool paused = false, update_step = false;
    char input = 0;

    //Create Entities
    p = create_player(" O\n", "-|-\n", "/|\n", " |\\\n", 0, 3, 3, 3, 0, false);
    s1 = create_spider("|\\O/\\\n", "/\\O/|\n", 3, 1, 1, 5, 0, true);

    //Starting Conditions
    print_p2(p);

    //InitializeScreen

    //Game Start
    while(game == 1){
        update_step = false;
        while((input == 0) & (paused == false)){
            
            if(gt % wt == 0){
                clear_terminal();

                update_step = true;

                //Draw Player Standing Still
                if(p.at == 0){print_p1(p); }
                else if(p.at == 1){print_p2(p); }
                
                //Draw Player Movement
                if((p.is_moving==true)){
                    clear_terminal();
                    if(p.at == 0){print_p1(p); p.at = 1; }
                    else if(p.at == 1){print_p2(p); p.at = 0; }
                    p.is_moving = false;
                }

                //Move Spider Right (Temp Test)
                s1 = s_move_right(s1);
                
                //Draw Spider Movement
                if(s1.at == 0){print_s1(s1); s1.at = 1; }
                else if(s1.at == 1){print_s2(s1); s1.at = 0; }

                //Future Draw
                //Refresh Screen(Draws All Entities)
            }
            //Keyboard Handling
            if(_kbhit()){input = kb_logic(); }

            //Game Time
            gt = gt_logic(gt);
        }

        //Quit
        if(input == 'q'){
            game = 0;
        }
        //Left
        if(input == 'K'){
            if(update_step == true){p = p_move_left(p); }
        }
        //Right
        if(input == 'M'){
            if(update_step == true){p = p_move_right(p); }
        }
        //UP
        if(input == 'H'){
            if(update_step == true){p = p_move_up(p); }
        }
        //Down
        if(input == 'P'){
            if(update_step == true){p = p_move_down(p); }
        }
        //Pause
        if(input == 'p'){
            paused = !paused;
        }

        input = 0;
        while((input == 0) & (paused == true)){
            //Game is paused Loop
            if(gt % wt == 0){
                
            }

            //Keyboard Handling
            if(_kbhit()){input = kb_logic(); }

            //Game TIme Handling
            gt = gt_logic(gt);
        }
    }
}

//Starts Game
void game_start(){
    game_loop();
}



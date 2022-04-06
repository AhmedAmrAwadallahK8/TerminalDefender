#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "player.c"
#include "spider.c"

//Game Time Logic
int gt_logic(int gt){
    gt++;
    if(gt >= 1000000){gt = 0; }
    return gt;
}

//Keyboard Logic
//Up: H, 72
//Down: P, 80
//Left: K, 75
//Right: M, 77
int kb_logic(){
    char in1, in2;
    in1 = getch();
    if(_kbhit()){in2 = getch(); }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if(in1 == -32){return in2; }
    else{return in1; }
}

void game_loop(){
    struct Player p;
    struct Spider s1;
    int game = 1, gt = 0, wt = 20000;
    char primitive_clear[20] = "\x1B[2J\x1B[H";
    bool paused = false, update_step = false;
    char input = 0;

    p = create_player(" O\n", "-|-\n", "/|\n", " |\\\n", 0, 3, 3, 3, 0, false);
    s1 = create_spider("|\\O/\\\n", "/\\O/|\n", 3, 1, 1, 5, 0, true);

    //Starting Conditions
    print_p2(p);

    //Game Start
    while(game == 1){
        update_step = false;
        while((input == 0) & (paused == false)){
            
            if(gt % wt == 0){
                printf("%s", primitive_clear);
                update_step = true;

                //Draw Player Standing Still
                if(p.at == 0){print_p1(p); }
                else if(p.at == 1){print_p2(p); }
                
                //Move Player
                if((p.is_moving==true)){
                    printf("%s", primitive_clear);
                    if(p.at == 0){print_p1(p); p.at = 1; }
                    else if(p.at == 1){print_p2(p); p.at = 0; }
                    p.is_moving = false;
                }

                

                
                //Move Spider Right (Temp Test)
                s1.x++;
                if(s1.x > 200){s1.x = 200; }
                
                if(s1.at == 0){print_s1(s1); s1.at = 1; }
                else if(s1.at == 1){print_s2(s1); s1.at = 0; }
            }
            if(_kbhit()){input = kb_logic(); }
            gt = gt_logic(gt);
        }

        //printf("\nInput: %c, %d", input, input);
        //printf("\nSpaces %d", spaces);
        //sleep(1);
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
            if(gt % wt == 0){
            }
            if(_kbhit()){input = kb_logic(); }
            gt = gt_logic(gt);
        }
    }
    
    //End Game
    printf("%s", primitive_clear);
    printf("THANK YOU FOR PLAYING");
    sleep(2);

}

void game_start(){
    game_loop();
}


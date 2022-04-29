#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//OLD PROTOTYPE BUILD

//Game Time Logic
int gt_logic(int gt){
    gt++;
    if(gt >= 1000000){gt = 0; }
    return gt;
}

//Keyboard Logic
int kb_logic(){
    char in1, in2;
    in1 = getch();
    if(_kbhit()){in2 = getch(); }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if(in1 == -32){return in2; }
    else{return in1; }
}
//Up: H, 72
//Down: P, 80
//Left: K, 75
//Right: M, 77

//Left Right Movement
void LR_movement(int spaces){
    for(int i = 0; i<spaces; i++){
        printf(" ");
    }
}

//Up Down Movement
void UD_movement(int nl){
    for(int i = 0; i<nl; i++){
        printf("\n");
    }
}

//Renders The player
void render_player(){

}

//Updates position
void update_pos(){

}

int main(){
    int game = 1, gt = 0, wt = 20000, spaces = 0, nl=3;
    char head[6] = " O\n", body[6] = "-|-\n", leg1[6] = "/|\n", leg2[6] = " |\\\n";
    char primitive_clear[20] = "\x1B[2J\x1B[H";
    int at = 0; //Animation State TEMP
    bool paused = false, is_moving = false, update_step = false;
    char input = 0;

    //Starting Conditions
    printf("%s", primitive_clear);
    UD_movement(nl);
    LR_movement(spaces);
    printf("%s", head);
    LR_movement(spaces);
    printf("%s", body);
    LR_movement(spaces);
    printf("%s", leg2);

    //Game Start
    while(game == 1){
        update_step = false;
        while((input == 0) & (paused == false)){
            
            if(gt % wt == 0){
                update_step = true;
                if((at == 0) & (is_moving==true)){
                    printf("%s", primitive_clear);
                    UD_movement(nl);
                    LR_movement(spaces);
                    printf("%s", head);
                    LR_movement(spaces);
                    printf("%s", body);
                    LR_movement(spaces);
                    printf("%s", leg1);
                    at = 1;
                    is_moving = false;
                }
                else if((at == 1) & (is_moving==true)){
                    printf("%s", primitive_clear);
                    UD_movement(nl);
                    LR_movement(spaces);
                    printf("%s", head);
                    LR_movement(spaces);
                    printf("%s", body);
                    LR_movement(spaces);
                    printf("%s", leg2);
                    at = 0;
                    is_moving = false;
                }

            }
            if(_kbhit()){input = kb_logic(); }
            gt = gt_logic(gt);
        }
         //Need to flush input buffer somehow
        //printf("\nInput: %c, %d", input, input);
        //printf("\nSpaces %d", spaces);
        //sleep(1);
        //Quit
        if(input == 'q'){
            game = 0;
        }
        //Left
        if(input == 'K'){
            if(update_step == true){spaces--; }
            if(spaces < 0){spaces = 0; }
            is_moving = true;
        }
        //Right
        if(input == 'M'){
            if(update_step == true){spaces++; }
            if(spaces > 200){spaces = 200; }
            is_moving = true;
        }
        //UP
        if(input == 'H'){
            if(update_step == true){nl--; }
            if(nl < 0){nl = 0; }
            is_moving = true;
        }
        //Down
        if(input == 'P'){
            if(update_step == true){nl++; }
            if(nl > 30){nl = 30; }
            is_moving = true;
        }
        //Pause
        if(input == 'p'){
            paused = !paused;
        }

        input = 0;
        while((input == 0) & (paused == true)){
            if(gt % wt == 0){
                /**printf("%s", primitive_clear);
                UD_movement(nl);
                LR_movement(spaces);
                printf("%s", head);
                LR_movement(spaces);
                printf("%s", body);
                LR_movement(spaces);
                printf("%s", leg1);**/
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
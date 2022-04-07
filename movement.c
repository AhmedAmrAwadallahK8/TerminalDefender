#include <stdio.h>
#include "movement.h"

//Left Right Entity Movement
void LR_movement(int spaces){
    for(int i = 0; i<spaces; i++){
        printf(" ");
    }
}

//Up Down Entity Movement
void UD_movement(int nl){
    for(int i = 0; i<nl; i++){
        printf("\n");
    }
}
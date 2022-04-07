#include <stdio.h>
#include "movement.h"


//??: Move This Function elsewhere
//Left Right Movement
void LR_movement(int spaces){
    for(int i = 0; i<spaces; i++){
        printf(" ");
    }
}

//??: Move this function elsewhere
//Up Down Movement
void UD_movement(int nl){
    for(int i = 0; i<nl; i++){
        printf("\n");
    }
}
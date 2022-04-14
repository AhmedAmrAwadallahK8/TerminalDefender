#include <stdlib.h>
#include "td_rand.h"

//Randomly generates a number in between specified lower and upper bound inclusive
int rand_num(int lwr, int upr){
    return (rand() % (upr - lwr + 1)) + lwr;
}

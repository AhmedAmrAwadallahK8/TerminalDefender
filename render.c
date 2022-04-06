//Go line by line,
//Look through list to see who has an x coordinate closer to right side of screen and draw that first
//Repeat until all entity drawn for line
//Go to next line repeat above.
//Repeat until last line reached on screen
void clear_terminal(){
    char primitive_clear[20] = "\x1B[2J\x1B[H";
    printf("%s", primitive_clear);
}

void refresh_terminal(){

}
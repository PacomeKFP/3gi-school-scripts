#ifndef _SCREEN_
#define _SCREEN_
#include "types.h"

// to define the screen width, height and dept
// here the depth is used to represent the fact that ech column of the screen is divided in two cels,  the first is used r the value tored and the second is used for the color of the character.
void clear_line(uint8 from, uint8 to);
void update_cursor();
void clear_screen();

// TODO: now this method erase the content of the old line the it is not possible to scrool down, we can modify it to save the content of the old line  and add the scrool down method;
void scrool_up(uint8 line_number);
/*The function scool when we arrive to the last line*/
void new_line_check();

void print_character(char c, uint8 color);
void print(string str, bool display_with_colors);
void println(string str, bool display_with_colors);

#endif //_SCREEN_
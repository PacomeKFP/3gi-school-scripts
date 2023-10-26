#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2; // to define the screen width, height and dept
// here the depth is used to represent the fact that ech column of the screen is divided in two cels,  the first is used r the value tored and the second is used for the color of the character.
void clear_line(uint8 from, uint8 to)
{
    uint16 i = sw * from * to; // this is the place where we will really start clearing
    string vidmem = (string)0xb8000;
    // 0xb8000 represents the first box of the screen (left top posotion)
    // each box of the screen is represented by an adress in hex
    for (i = 0; i < (sw * (to + 1) * sd) /** where we will stop clearing*/; i++)
    {
        vidmem[i] = 0x0;
    }
}
void update_cursor()
{
    unsigned temp;
    temp = cursorY * sw + cursorX; // get the cursor position = y*width + x

    outport(0x3D4, 14);        // CRT Control Register: select Cursor location
    outport(0x3D5, temp >> 8); // Send the high bytes accros the bus
    outport(0x3D4, 15);        // CRT Control Register: select send Low byte
    outport(0x3D5, temp);      // Send the Low byte of the cursor location

    /**the location of the cusor is done with div-mod
     * The Y position is temp / sw
     * The X position is temp % sw
     *
     * the we can implicitly think that given an integer, i tis possible to get her equivalent as positionon the screen,
     * this equivalent is given by trying to count pixels on the screen from left to right and top to bottom
     * Whe stop counting when we the number of counted pixels is equal to the given integer
     */
}
void clear_screen()
{
    clear_line(0, sh - 1);
    cursorX = 0;
    cursorY = 0;
    update_cursor();
}

// TODO: now this method erase the content of the old line the it is not possible to scrool down, we can modify it to save the content of the old line  and add the scrool down method;
void scrool_up(uint8 line_number)
{

    string vidmem = (string)0xb8000;
    uint16 i = 0;
    for (i = 0; i < sw * (sh - 1) * sd; i++)
    {
        /** Here we move the content of a line to a corresponding line located before if*/
        vidmem[i] = vidmem[i + sw * sd * line_number];
    }
    clear_line(sh - 1 - line_number, sh - 1); // clearing the par of the screen scroolled
    if (cursorY - line_number < 0)
        cursorX = 0, cursorY = 0;
    else
        cursorY -= line_number;
    update_cursor();
}

/*The function scool when we arrive to the last line*/
void new_line_check()
{
    if (cursorY >= sh - 1)
        scrool_up(1);
}

void print_character(char c, uint8 color)
{
    string vidmem = (string)0xb8000;
    switch (c)
    {
    case (0x08): // backspace character
        if (cursorX > 0)
        {
            cursorX--;
            vidmem[(cursorY * sw + cursorX) * sd] = 0x00;
        }
        break;
    case (0x09): // tab button pressed
        cursorX = (cursorX + 8) & ~(8 - 1);
        break;
    case ('\r'):
        cursorX = 0;
        break;
    case ('\n'):
        cursorX = 0;
        cursorY++;
        break;
    default:
        vidmem[(cursorY * sw + cursorX) * sd] = c;
        vidmem[(cursorY * sw + cursorX) * sd + 1] = color;
        // the first char control the bg and the second for the fg
        //  TODO customize this method by adding the color as parameter
        cursorX++;
        break;
    }
    /*If we are at the end of the row then go down one row */
    if (cursorX >= sw)
        cursorX = 0, cursorY++;

    /*Check if we reached the bottom of screen */
    new_line_check();
    update_cursor();
}

void print(string str, bool display_with_colors)
{
    uint16 i = 0;

    for (i = 0; i < str_lenght(str); i++)
    {
        uint8 color = display_with_colors ? i*i % 256 : 0x0F;
        print_character(str[i], color);
    }
}

#endif